/*-
 * This code contains changes by
 *      Gunnar Ritter, Freiburg i. Br., Germany, 2002. All rights reserved.
 *
 * Conditions 1, 2, and 4 and the no-warranty notice below apply
 * to these changes.
 *
 *
 * Copyright (c) 1991
 * 	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 * 	This product includes software developed by the University of
 * 	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *
 * Copyright(C) Caldera International Inc. 2001-2002. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *   Redistributions of source code and documentation must retain the
 *    above copyright notice, this list of conditions and the following
 *    disclaimer.
 *   Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *   All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed or owned by Caldera
 *      International, Inc.
 *   Neither the name of Caldera International, Inc. nor the names of
 *    other contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * USE OF THE SOFTWARE PROVIDED FOR UNDER THIS LICENSE BY CALDERA
 * INTERNATIONAL, INC. AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL CALDERA INTERNATIONAL, INC. BE
 * LIABLE FOR ANY DIRECT, INDIRECT INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*	from 4.4BSD /usr/src/old/awk/run.c	4.10 (Berkeley) 5/26/93	*/
/*	Sccsid @(#)run.c	1.20 (gritter) 12/25/06>	*/

#include "sys/param.h"
#include "awk.def"
#include "math.h"
#include "awk.h"
#include "stdio.h"
#include "fcntl.h"
#include "stdarg.h"

static struct
{
	FILE *fp;
	int type;
	char *fname;
} *files;
static int filenum;

#define PA2NUM	29
int pairstack[PA2NUM], paircnt;
node *winner = (node *)NULL;
#define MAXTMP 20
cell tmps[MAXTMP];
static cell nullval ={EMPTY,EMPTY,0.0,NUM,0};
obj	true	={ OBOOL, BTRUE, 0 };
obj	false	={ OBOOL, BFALSE, 0 };

int chrlen(const char *s);
int chrdist(const char *s, const char *end);

static int growsprintf(char **, char **, int *, const char *, ...);
static void growbuf(char **, int *, int, char **, const char *);

void
run(void)
{
	register int i;

	execute(winner);

	/* Wait for children to complete if output to a pipe. */
	for (i=0; i<filenum; i++)
		if (files[i].fp && files[i].type == '|')
			pclose(files[i].fp);
}

obj execute(node *u)
{
	register obj (*proc)(node **, int);
	obj x;
	node *a;

	if (u==(node *)NULL)
		return(true);
	for (a = u; ; a = a->nnext) {
		if (cantexec(a))
			return(nodetoobj(a));
		if (a->ntype==NPA2)
			proc=dopa2;
		else {
			if (notlegal(a->nobj))
				error(FATAL, "illegal statement %o", a);
			proc = proctab[a->nobj-FIRSTTOKEN];
		}
		x = (*proc)(a->narg,a->nobj);
		if (isfld(x)) fldbld();
		if (isexpr(a))
			return(x);
		/* a statement, goto next statement */
		if (isjump(x))
			return(x);
		if (a->nnext == (node *)NULL)
			return(x);
		tempfree(x);
	}
}

obj program(node **a, int n)
{
	obj x;

	if (a[0] != NULL) {
		x = execute(a[0]);
		if (isexit(x))
			return(true);
		if (isjump(x))
			error(FATAL, "unexpected break, continue or next");
		tempfree(x);
	}
	while (getrec()) {
		x = execute(a[1]);
		if (isexit(x)) break;
		tempfree(x);
	}
	/*tempfree(x);*/
	if (a[2] != NULL) {
		x = execute(a[2]);
		if (isbreak(x) || isnext(x) || iscont(x))
			error(FATAL, "unexpected break, continue or next");
		tempfree(x);
	}
	return(true);
}

/*ARGSUSED*/
obj getline(node **a, int n)
{
	obj x;

	x = gettemp();
	setfval(x.optr, (awkfloat) getrec());
	return(x);
}

obj array(node **a,int n)
{
	obj x, y;

	x = execute(a[1]);
	y = arrayel(a[0], x);
	tempfree(x);
	return(y);
}

obj arrayel(node *a,obj b)
{
	char *s;
	cell *x;
	obj y;

	s = getsval(b.optr);
	x = (cell *) a;
	if (!(x->tval&ARR)) {
		strfree(x->sval);
		x->tval &= ~STR;
		x->tval |= ARR;
		x->sval = (char *) makesymtab();
	}
	y.optr = setsymtab(s, tostring(""), 0.0, STR|NUM, (cell **)x->sval);
	y.otype = OCELL;
	y.osub = CVAR;
	return(y);
}

obj matchop(node **a,int n)
{
	obj x;
	char *s;
	int i;

	x = execute(a[0]);
	if (isstr(x)) s = x.optr->sval;
	else	s = getsval(x.optr);
	tempfree(x);
	i = match((struct fa *)a[1], s);
	if (n==MATCH && i==1 || n==NOTMATCH && i==0)
		return(true);
	else
		return(false);
}

obj boolop(node **a,int n)
{
	obj x, y;
	int i;

	x = execute(a[0]);
	i = istrue(x);
	tempfree(x);
	switch (n) {
	default:
		error(FATAL, "unknown boolean operator %d", n);
	case BOR:
		if (i) return(true);
		y = execute(a[1]);
		i = istrue(y);
		tempfree(y);
		if (i) return(true);
		else return(false);
	case AND:
		if ( !i ) return(false);
		y = execute(a[1]);
		i = istrue(y);
		tempfree(y);
		if (i) return(true);
		else return(false);
	case NOT:
		if (i) return(false);
		else return(true);
	}
}

obj relop(node **a,int n)
{
	int i;
	obj x, y;
	awkfloat j;

	x = execute(a[0]);
	y = execute(a[1]);
	if (x.optr->tval&NUM && y.optr->tval&NUM) {
		j = x.optr->fval - y.optr->fval;
		i = j<0? -1: (j>0? 1: 0);
	} else {
		i = strcoll(getsval(x.optr), getsval(y.optr));
	}
	tempfree(x);
	tempfree(y);
	switch (n) {
	default:
		error(FATAL, "unknown relational operator %d", n);
	case LT:	if (i<0) return(true);
			else return(false);
	case LE:	if (i<=0) return(true);
			else return(false);
	case NE:	if (i!=0) return(true);
			else return(false);
	case EQ:	if (i==0) return(true);
			else return(false);
	case GE:	if (i>=0) return(true);
			else return(false);
	case GT:	if (i>0) return(true);
			else return(false);
	}
}

void
tempfree(obj a)
{
	if (!istemp(a)) return;
	strfree(a.optr->sval);
	a.optr->tval = 0;
}

obj gettemp(void)
{
	int i;
	obj x;

	for (i=0; i<MAXTMP; i++)
		if (tmps[i].tval==0)
			break;
	if (i==MAXTMP)
		error(FATAL, "out of temporaries in gettemp");
	x.optr = &tmps[i];
	tmps[i] = nullval;
	x.otype = OCELL;
	x.osub = CTEMP;
	return(x);
}

obj indirect(node **a,int n)
{
	obj x;
	int m;

	x = execute(a[0]);
	m = getfval(x.optr);
	tempfree(x);
	x.optr = fieldadr(m);
	x.otype = OCELL;
	x.osub = CFLD;
	return(x);
}

obj substr(node **a, int nnn)
{
	char *s, *sp, *sq, temp;
	wchar_t wc;
	obj x;
	int k, m, n;

	x = execute(a[0]);
	s = getsval(x.optr);
	k = strlen(s) + 1;
	tempfree(x);
	x = execute(a[1]);
	m = getfval(x.optr);
	if (m <= 0)
		m = 1;
	else if (m > k)
		m = k;
	tempfree(x);
	if (a[2] != nullstat) {
		x = execute(a[2]);
		n = getfval(x.optr);
		tempfree(x);
	}
	else
		n = k - 1;
	if (n < 0)
		n = 0;
	else if (n > k - m)
		n = k - m;
	dprintf("substr: m=%d, n=%d, s=%s\n", m, n, s);
	if (mb_cur_max > 1) {
		for (sp = s; m > 1 && *sp; m--) {
			next(wc, sp, k);
			sp += k;
		}
		m = sp - s + 1;
		for (sq = sp; n > 0 && *sq; n--) {
			next(wc, sq, k);
			sq += k;
		}
		n = sq - sp;
		dprintf("substr: multibyte: m=%d, n=%d, s=%s\n", m, n, s);
	}
	x = gettemp();
	temp = s[n+m-1];	/* with thanks to John Linderman */
	s[n+m-1] = '\0';
	setsval(x.optr, s + m - 1);
	s[n+m-1] = temp;
	return(x);
}

obj sindex(node **a, int nnn)
{
	obj x;
	char *s1, *s2, *p1, *p2, *q;
	int n, nq, n2;
	wchar_t wc, wq, w2;

	x = execute(a[0]);
	s1 = getsval(x.optr);
	tempfree(x);
	x = execute(a[1]);
	s2 = getsval(x.optr);
	tempfree(x);

	x = gettemp();
	for (p1 = s1; next(wc, p1, n), wc != '\0'; p1 += n) {
		for (q = p1, p2 = s2;
				next(wq, q, nq),
				next(w2, p2, n2),
				w2 != '\0' && wq == w2;
				q += nq, p2 += n2)
			;
		if (w2 == '\0') {
			setfval(x.optr, chrdist(s1, p1));
			return(x);
		}
	}
	setfval(x.optr, 0.0);
	return(x);
}

char *format(const char *s,node *a)
{
	char *p, *fmt = NULL, *t, *xs = 0;
	const char *os;
	int fmtsz = 0;
	obj x;
	int flag = 0;
	awkfloat xf = 0;
	char *buf;
	int bufsz;

	os = s;
	fmt = malloc(fmtsz = RECSIZE+1);
	buf = malloc(bufsz = RECSIZE+1);
	if (fmt == NULL || buf == NULL)
		error(FATAL, "out of space in format");
	p = buf;
	while (*s) {
		if (p >= &buf[bufsz])
			growbuf(&buf, &bufsz, RECSIZE, &p, "format");
		if (*s != '%') {
			*p++ = *s++;
			continue;
		}
		if (*(s+1) == '%') {
			*p++ = '%';
			s += 2;
			continue;
		}
		for (t=fmt; (*t++ = *s) != '\0'; s++) {
			if (t >= &fmt[fmtsz])
				growbuf(&fmt, &fmtsz, RECSIZE, &t, "format");
			if (*s >= 'a' && *s <= 'z' && *s != 'l')
				break;
		}
		*t = '\0';
		switch (*s) {
		case 'f': case 'e': case 'g':
			flag = 1;
			break;
		case 'd':
			flag = 2;
			if(*(s-1) == 'l') break;
			*(t-1) = 'l';
			*t = 'd';
			*++t = '\0';
			break;
		case 'o': case 'x':
			flag = *(s-1)=='l' ? 2 : 3;
			break;
		case 'c':
			if (mb_cur_max > 1) {
				*(t-1) = 'l';
				*t = 'c';
				*++t = '\0';
				flag = 6;
			} else
				flag = 3;
			break;
		case 's':
			flag = 4;
			break;
		default:
			flag = 0;
			break;
		}
		if (flag == 0) {
			growsprintf(&buf, &p, &bufsz, "%s", fmt);
			continue;
		}
		if (a == NULL)
			error(FATAL, "not enough arguments in printf(%s)", os);
		x = execute(a);
		a = a->nnext;
		if (flag != 4)	/* watch out for converting to numbers! */
			xf = getfval(x.optr);
		else
			xs = x.optr->sval==NULL ? "" : getsval(x.optr);
		if (flag==1)
			growsprintf(&buf, &p, &bufsz, fmt, xf);
		else if (flag==2)
			growsprintf(&buf, &p, &bufsz, fmt, (long)xf);
		else if (flag==3)
			growsprintf(&buf, &p, &bufsz, fmt, (int)xf);
		else if (flag==4)
			growsprintf(&buf, &p, &bufsz, fmt, xs);
		else if (flag==6)
			growsprintf(&buf, &p, &bufsz, fmt, (wint_t)xf);
		tempfree(x);
		s++;
	}
	*p = '\0';
	xfree(fmt);
	return(buf);
}

obj awsprintf(node **a,int n)
{
	obj x;
	node *y;
	char *s;

	y = a[0]->nnext;
	x = execute(a[0]);
	s = format(getsval(x.optr), y);
	tempfree(x);
	x = gettemp();
	x.optr->sval = s;
	x.optr->tval = STR;
	return(x);
}

obj arith(node **a,int n)
{
	awkfloat i,j = 0;
	obj x,y,z;

	x = execute(a[0]);
	i = getfval(x.optr);
	tempfree(x);
	if (n != UMINUS) {
		y = execute(a[1]);
		j = getfval(y.optr);
		tempfree(y);
	}
	z = gettemp();
	switch (n) {
	default:
		error(FATAL, "illegal arithmetic operator %d", n);
	case ADD:
		i += j;
		break;
	case MINUS:
		i -= j;
		break;
	case MULT:
		i *= j;
		break;
	case DIVIDE:
		if (j == 0)
			error(FATAL, "division by zero");
		i /= j;
		break;
	case MOD:
		if (j == 0)
			error(FATAL, "division by zero");
		i = i - j*(long)(i/j);
		break;
	case UMINUS:
		i = -i;
		break;
	}
	setfval(z.optr, i);
	return(z);
}

obj incrdecr(node **a, int n)
{
	obj x, z;
	int k;
	awkfloat xf;

	x = execute(a[0]);
	xf = getfval(x.optr);
	k = (n == PREINCR || n == POSTINCR) ? 1 : -1;
	if (n == PREINCR || n == PREDECR) {
		setfval(x.optr, xf + k);
		return(x);
	}
	z = gettemp();
	setfval(z.optr, xf);
	setfval(x.optr, xf + k);
	tempfree(x);
	return(z);
}


obj assign(node **a,int n)
{
	obj x, y;
	awkfloat xf, yf;

	x = execute(a[0]);
	y = execute(a[1]);
	if (n == ASSIGN) {	/* ordinary assignment */
		if ((y.optr->tval & (STR|NUM)) == (STR|NUM)) {
			setsval(x.optr, y.optr->sval);
			x.optr->fval = y.optr->fval;
			x.optr->tval |= NUM;
		}
		else if (y.optr->tval & STR)
			setsval(x.optr, y.optr->sval);
		else if (y.optr->tval & NUM)
			setfval(x.optr, y.optr->fval);
		tempfree(y);
		return(x);
	}
	xf = getfval(x.optr);
	yf = getfval(y.optr);
	switch (n) {
	case ADDEQ:
		xf += yf;
		break;
	case SUBEQ:
		xf -= yf;
		break;
	case MULTEQ:
		xf *= yf;
		break;
	case DIVEQ:
		if (yf == 0)
			error(FATAL, "division by zero");
		xf /= yf;
		break;
	case MODEQ:
		if (yf == 0)
			error(FATAL, "division by zero");
		xf = xf - yf*(long)(xf/yf);
		break;
	default:
		error(FATAL, "illegal assignment operator %d", n);
		break;
	}
	tempfree(y);
	setfval(x.optr, xf);
	return(x);
}

obj cat(node **a,int q)
{
	obj x,y,z;
	int n1, n2;
	char *s;

	x = execute(a[0]);
	y = execute(a[1]);
	getsval(x.optr);
	getsval(y.optr);
	n1 = strlen(x.optr->sval);
	n2 = strlen(y.optr->sval);
	s = (char *) malloc(n1 + n2 + 1);
	strcpy(s, x.optr->sval);
	strcpy(s+n1, y.optr->sval);
	tempfree(y);
	z = gettemp();
	z.optr->sval = s;
	z.optr->tval = STR;
	tempfree(x);
	return(z);
}

obj pastat(node **a,int n)
{
	obj x;

	if (a[0]==nullstat)
		x = true;
	else
		x = execute(a[0]);
	if (istrue(x)) {
		tempfree(x);
		x = execute(a[1]);
	}
	return(x);
}

obj dopa2(node **a,int n)
{
	obj x;

	if (pairstack[n]==0) {
		x = execute(a[0]);
		if (istrue(x))
			pairstack[n] = 1;
		tempfree(x);
	}
	if (pairstack[n] == 1) {
		x = execute(a[1]);
		if (istrue(x))
			pairstack[n] = 0;
		tempfree(x);
		x = execute(a[2]);
		return(x);
	}
	return(false);
}

obj aprintf(node **a,int n)
{
	obj x;

	x = awsprintf(a,n);
	if (a[1]==NULL) {
		printf("%s", x.optr->sval);
		tempfree(x);
		return(true);
	}
	redirprint(x.optr->sval, (intptr_t)a[1], a[2]);
	return(x);
}

obj split(node **a,int nnn)
{
	obj x;
	cell *ap;
	register char *s, *fs;
	char *t, temp, num[25];
	wchar_t sep, wc;
	int n, m;

	x = execute(a[0]);
	s = getsval(x.optr);
	tempfree(x);
	if (a[2] == nullstat)
		fs = *FS;
	else {
		x = execute(a[2]);
		fs = getsval(x.optr);
		tempfree(x);
	}
	next(sep, fs, m);
	ap = (cell *) a[1];
	freesymtab(ap);
	dprintf("split: s=|%s|, a=%s, sep=|%lc|\n", s, ap->nval, (wint_t)sep);
	ap->tval &= ~STR;
	ap->tval |= ARR;
	ap->sval = (char *) makesymtab();

	n = 0;
	if (sep == ' ')
		for (n = 0; ; ) {
			while (*s == ' ' || *s == '\t' || *s == '\n')
				s++;
			if (*s == 0)
				break;
			n++;
			t = s;
			next(wc, s, m);
			do {
				s += m;
				next(wc, s, m);
			} while (wc!=' ' && wc!='\t' && wc!='\n' && wc!='\0');
			temp = *s;
			*s = '\0';
			(void)snprintf(num, sizeof num, "%d", n);
			if (isanumber(t))
				setsymtab(num, tostring(t), atof(t), STR|NUM, (cell **)ap->sval);
			else
				setsymtab(num, tostring(t), 0.0, STR, (cell **)ap->sval);
			*s = temp;
			if (*s != 0)
				s++;
		}
	else if (*s != 0)
		for (;;) {
			n++;
			t = s;
			while (next(wc, s, m),
					wc != sep && wc != '\n' && wc != '\0')
				s += m;
			temp = *s;
			*s = '\0';
			(void)snprintf(num, sizeof num, "%d", n);
			if (isanumber(t))
				setsymtab(num, tostring(t), atof(t), STR|NUM, (cell **)ap->sval);
			else
				setsymtab(num, tostring(t), 0.0, STR, (cell **)ap->sval);
			*s = temp;
			if (wc == '\0')
				break;
			s += m;
		}
	x = gettemp();
	x.optr->tval = NUM;
	x.optr->fval = n;
	return(x);
}

obj ifstat(node **a,int n)
{
	obj x;

	x = execute(a[0]);
	if (istrue(x)) {
		tempfree(x);
		x = execute(a[1]);
	}
	else if (a[2] != nullstat) {
		tempfree(x);
		x = execute(a[2]);
	}
	return(x);
}

obj whilestat(node **a,int n)
{
	obj x;

	for (;;) {
		x = execute(a[0]);
		if (!istrue(x)) return(x);
		tempfree(x);
		x = execute(a[1]);
		if (isbreak(x)) {
			x = true;
			return(x);
		}
		if (isnext(x) || isexit(x))
			return(x);
		tempfree(x);
	}
}

obj forstat(node **a,int n)
{
	obj x;

	tempfree(execute(a[0]));
	for (;;) {
		if (a[1]!=nullstat) {
			x = execute(a[1]);
			if (!istrue(x)) return(x);
			else tempfree(x);
		}
		x = execute(a[3]);
		if (isbreak(x)) {	/* turn off break */
			x = true;
			return(x);
		}
		if (isnext(x) || isexit(x))
			return(x);
		tempfree(x);
		tempfree(execute(a[2]));
	}
}

obj instat(node **a, int n)
{
	cell *vp, *arrayp, *cp, **tp;
	obj x;
	int i;

	vp = (cell *) a[0];
	arrayp = (cell *) a[1];
	if (!(arrayp->tval & ARR))
		error(FATAL, "%s is not an array", arrayp->nval);
	tp = (cell **) arrayp->sval;
	for (i = 0; i < MAXSYM; i++) {	/* this routine knows too much */
		for (cp = tp[i]; cp != NULL; cp = cp->nextval) {
			setsval(vp, cp->nval);
			x = execute(a[2]);
			if (isbreak(x)) {
				x = true;
				return(x);
			}
			if (isnext(x) || isexit(x))
				return(x);
			tempfree(x);
		}
	}
	return (true);
}

obj jump(node **a,int n)
{
	obj x, y;

	memset(&x, 0, sizeof x);
	x.otype = OJUMP;
	switch (n) {
	default:
		error(FATAL, "illegal jump type %d", n);
		break;
	case EXIT:
		if (a[0] != 0) {
			y = execute(a[0]);
			errorflag = getfval(y.optr);
		}
		x.osub = JEXIT;
		break;
	case NEXT:
		x.osub = JNEXT;
		break;
	case BREAK:
		x.osub = JBREAK;
		break;
	case CONTINUE:
		x.osub = JCONT;
		break;
	}
	return(x);
}

obj fncn(node **a,int n)
{
	obj x;
	awkfloat u = 0;
	int t;

	t = (intptr_t) a[0];
	x = execute(a[1]);
	if (t == FLENGTH)
		u = (awkfloat) chrlen(getsval(x.optr));
	else if (t == FLOG)
		u = log(getfval(x.optr));
	else if (t == FINT)
		u = (awkfloat) (long) getfval(x.optr);
	else if (t == FEXP)
		u = exp(getfval(x.optr));
	else if (t == FSQRT)
		u = sqrt(getfval(x.optr));
	else
		error(FATAL, "illegal function type %d", t);
	tempfree(x);
	x = gettemp();
	setfval(x.optr, u);
	return(x);
}

obj print(node **a,int n)
{
	register node *x;
	obj y;
	char	*p, *q, *sp;
	static char *s;
	static size_t	ssz;
	size_t	sz;

	if (s == NULL && (s = malloc(ssz = RECSIZE+1)) == NULL)
		error(FATAL, "string %.20s ... too long to print", s);
	s[0] = '\0';
	for (x=a[0], sp = s; x!=NULL; x=x->nnext) {
		y = execute(x);
		p = getsval(y.optr);
		q = x->nnext ? *OFS : *ORS;
		sz = sp + strlen(p) + strlen(q) + 1 - s;
		if (sz > ssz) {
			size_t diff = sp - s;
			if ((s = realloc(s, ssz = sz)) == NULL)
				error(FATAL,
					"string %.20s ... too long to print",
					s);
			sp = &s[diff];
		}
		while (*sp = *p++)
			sp++;
		tempfree(y);
		while (*sp = *q++)
			sp++;
	}
	if (a[1]==nullstat) {
		printf("%s", s);
		return(true);
	}
	redirprint(s, (intptr_t)a[1], a[2]);
	return(false);
}

/*ARGSUSED*/
obj nullproc(node **a, int n) {return(true);}

obj nodetoobj(node *a)
{
	obj x;

	x.optr = (cell *) a->nobj;
	x.otype = OCELL;
	x.osub = a->subtype;
	if (isfld(x)) fldbld();
	return(x);
}

void
redirprint(const char *s, int a, node *b)
{
	register int i;
	obj x;

	x = execute(b);
	getsval(x.optr);
	for (i=0; i<filenum; i++)
		if (files[i].fp && strcmp(x.optr->sval, files[i].fname) == 0)
			goto doit;
	for (i=0; i<filenum; i++)
		if (files[i].fp == 0)
			break;
	if (i >= filenum) {
		if ((files = realloc(files, sizeof *files *
					(filenum = (i + 15)))) == NULL)
			error(FATAL, "too many output files %d", i);
		memset(&files[i], 0, (filenum - i) * sizeof *files);
	}
	if (a == '|')	/* a pipe! */
		files[i].fp = popen(x.optr->sval, "w");
	else if (a == APPEND)
		files[i].fp = fopen(x.optr->sval, "a");
	else
		files[i].fp = fopen(x.optr->sval, "w");
	if (files[i].fp == NULL)
		error(FATAL, "can't open file %s", x.optr->sval);
	if (fcntl(fileno(files[i].fp), F_SETFD, 1) < 0)
		error(FATAL, "close on exec failure");
	files[i].fname = tostring(x.optr->sval);
	files[i].type = a;
doit:
	fprintf(files[i].fp, "%s", s);
#ifndef gcos
	fflush(files[i].fp);	/* in case someone is waiting for the output */
#endif
	tempfree(x);
}

int chrlen(const char *s)
{
	wchar_t wc;
	int m = 0, n;

	while (next(wc, s, n), wc != '\0') {
		s += n;
		m++;
	}
	return m;
}

int chrdist(const char *s, const char *end)
{
	wchar_t wc;
	int m = 1, n;

	while (next(wc, s, n), s < end) {
		s += n;
		m++;
	}
	return m;
}

static int
growsprintf(char **whole, char **target, int *size, const char *fmt, ...)
{
	va_list ap;
	int ret;
	size_t diff = 0, mx;

	if (*size == 0) {
		if ((*whole = malloc(*size = RECSIZE+1)) == NULL)
			goto oflo;
		*target = *whole;
	}
	diff = *target - *whole;
again:	va_start(ap, fmt);

	mx = *size - diff - 8;
	ret = vsnprintf(*target, mx, fmt, ap);
	va_end(ap);

	if (ret < 0 || ret >= mx) {
		if (ret < 0) {
			char	dummy[2];
			va_start(ap, fmt);
			ret = vsnprintf(dummy, sizeof dummy, fmt, ap);
			va_end(ap);
			if (ret < 0)
				goto oflo;
		}
		if ((*whole = realloc(*whole, *size = ret + 1 + diff + 8)) == 0)
		oflo:	error(FATAL, "format item %.20s... too long", fmt);
		*target = &(*whole)[diff];
		goto again;
	}
	
	while (**target)	/* NUL characters might have been printed; */
		(*target)++;	/* don't skip past them. */
	return ret;
}

static void growbuf(char **buf, int *bufsize, int incr,
		char **ptr, const char *fn)
{
	char *op;

	op = *buf;
	if ((*buf = realloc(*buf, *bufsize += incr)) == NULL)
		error(FATAL, "out of %s space", fn ? fn : "");
	if (ptr && *ptr)
		*ptr = &(*buf)[*ptr - op];
}
