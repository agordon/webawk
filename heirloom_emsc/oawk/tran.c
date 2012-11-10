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

/*	from 4.4BSD /usr/src/old/awk/tran.c	4.7 (Berkeley) 5/26/93	*/
/*	Sccsid @(#)tran.c	1.7 (gritter) 3/31/03>	*/

#include "stdio.h"
#include "awk.def"
#include "awk.h"

cell *symtab[MAXSYM];	/* symbol table pointers */

char	**FS;	/* initial field sep */
char	**RS;	/* initial record sep */
char	**OFS;	/* output field sep */
char	**ORS;	/* output record sep */
char	**OFMT;	/*output format for numbers*/
awkfloat *NF;	/* number of fields in current record */
awkfloat *NR;	/* number of current record */
char	**FILENAME;	/* current filename argument */

cell	*recloc;	/* location of record */
cell	*nrloc;		/* NR */
cell	*nfloc;		/* NF */

void
syminit(void)
{
	setsymtab("0", tostring("0"), 0.0, NUM|STR|CON|FLD, symtab);
	/* this one is used for if(x)... tests: */
	setsymtab("$zero&null", tostring(""), 0.0, NUM|STR|CON|FLD, symtab);
	recloc = setsymtab("$record", record, 0.0, STR|FLD, symtab);
	dprintf("recloc %lo lookup %lo\n", (long)recloc, (long)lookup("$record", symtab, 0));
	FS = &setsymtab("FS", tostring(" "), 0.0, STR|FLD, symtab)->sval;
	RS = &setsymtab("RS", tostring("\n"), 0.0, STR|FLD, symtab)->sval;
	OFS = &setsymtab("OFS", tostring(" "), 0.0, STR|FLD, symtab)->sval;
	ORS = &setsymtab("ORS", tostring("\n"), 0.0, STR|FLD, symtab)->sval;
	OFMT = &setsymtab("OFMT", tostring("%.6g"), 0.0, STR|FLD, symtab)->sval;
	FILENAME = &setsymtab("FILENAME", EMPTY, 0.0, STR|FLD, symtab)->sval;
	nfloc = setsymtab("NF", EMPTY, 0.0, NUM, symtab);
	NF = &nfloc->fval;
	nrloc = setsymtab("NR", EMPTY, 0.0, NUM, symtab);
	NR = &nrloc->fval;
}

cell **makesymtab(void)
{
	int i;
	cell **cp;

	cp = (cell **) malloc(MAXSYM * sizeof(cell *));
	if (cp == NULL)
		error(FATAL, "out of space in makesymtab");
	for (i = 0; i < MAXSYM; i++)
		cp[i] = 0;
	return(cp);
}

void
freesymtab(cell *ap)	/* free symbol table */
{
	cell *cp, *op, **tp;
	int i;

	if (!(ap->tval & ARR))
		return;
	tp = (cell **) ap->sval;
	for (i = 0; i < MAXSYM; i++) {
		for (cp = tp[i]; cp != NULL; ) {
			strfree(cp->nval);
			strfree(cp->sval);
			op = cp;
			cp = cp->nextval;
			free(op);
		}
	}
	xfree(tp);
}

cell *setsymtab(const char *n, char *s, awkfloat f, unsigned t, cell **tab)
{
	register int h;
	register cell *p;

	if (n != NULL && (p = lookup(n, tab, 0)) != NULL) {
		if (s != EMPTY ) xfree(s); /* careful here */
		dprintf("setsymtab found %lo: %s", (long)p, p->nval);
		dprintf(" %s %g %o\n", p->sval, p->fval, p->tval);
		return(p);
	}
	p = (cell *) malloc(sizeof(cell));
	if (p == NULL)
		error(FATAL, "symbol table overflow at %s", n);
	p->nval = tostring(n);
	p->sval = s;
	p->fval = f;
	p->tval = t;
	h = hash((unsigned char *)n);
	p->nextval = tab[h];
	tab[h] = p;
	dprintf("setsymtab set %lo: %s", (long)p, p->nval);
	dprintf(" %s %g %o\n", p->sval, p->fval, p->tval);
	return(p);
}

int
hash(register const unsigned char *s)	/* form hash value for string s */
{
	register int hashval;

	for (hashval = 0; *s != '\0'; )
		hashval += *s++;
	return(hashval % MAXSYM);
}

cell *lookup(register const char *s, cell **tab, int flag)
	/* look for s in tab, flag must match*/
{
	register cell *p;

	for (p = tab[hash((unsigned char *)s)]; p != NULL; p = p->nextval)
		if (strcmp(s, p->nval) == 0 &&
			(flag == 0 || flag == p->tval))
			return(p);	/* found it */
	return(NULL);	/* not found */
}

awkfloat setfval(register cell *vp, awkfloat f)
{
	dprintf("setfval: %lo %g\n", (long)vp, f);
	checkval(vp);
	if (vp == recloc)
		error(FATAL, "can't set $0");
	vp->tval &= ~STR;	/* mark string invalid */
	vp->tval |= NUM;	/* mark number ok */
	if ((vp->tval & FLD) && isnull(vp->nval))
		donerec = 0;
	return(vp->fval = f);
}

char *setsval(register cell *vp, const char *s)
{
	dprintf("setsval: %lo %s\n", (long)vp, s);
	checkval(vp);
	if (vp == recloc)
		error(FATAL, "can't set $0");
	vp->tval &= ~NUM;
	vp->tval |= STR;
	if ((vp->tval & FLD) && isnull(vp->nval))
		donerec = 0;
	if (!(vp->tval&FLD))
		strfree(vp->sval);
	vp->tval &= ~FLD;
	return(vp->sval = tostring(s));
}

awkfloat getfval(register cell *vp)
{

	if (vp->sval == record && donerec == 0)
		recbld();
	dprintf("getfval: %lo", (long)vp);
	checkval(vp);
	if ((vp->tval & NUM) == 0) {
		/* the problem is to make non-numeric things */
		/* have unlikely numeric variables, so that */
		/* $1 == $2 comparisons sort of make sense when */
		/* one or the other is numeric */
		if (isanumber(vp->sval)) {
			vp->fval = atof(vp->sval);
			if (!(vp->tval & CON))	/* don't change type of a constant */
				vp->tval |= NUM;
		}
		else
			vp->fval = 0.0;	/* not a very good idea */
	}
	dprintf("  %g\n", vp->fval);
	return(vp->fval);
}

char *getsval(register cell *vp)
{
	char s[100];

	if (vp->sval == record && donerec == 0)
		recbld();
	dprintf("getsval: %lo", (long)vp);
	checkval(vp);
	if ((vp->tval & STR) == 0) {
		if (!(vp->tval&FLD))
			strfree(vp->sval);
		if ((long long)vp->fval==vp->fval)
			(void)snprintf(s, sizeof s, "%.20g", vp->fval);
		else
			(void)snprintf(s, sizeof s, *OFMT, vp->fval);
		vp->sval = tostring(s);
		vp->tval &= ~FLD;
		vp->tval |= STR;
	}
	dprintf("  %s\n", vp->sval);
	return(vp->sval);
}

void
checkval(register cell *vp)
{
	if (vp->tval & ARR)
		error(FATAL, "illegal reference to array %s", vp->nval);
	if ((vp->tval & (NUM | STR)) == 0)
		error(FATAL, "funny variable %o: %s %s %g %o", vp, vp->nval,
			vp->sval, vp->fval, vp->tval);
}

char *tostring(register const char *s)
{
	register char *p;

	if (s==NULL){
		p = malloc(1);
		if (p == NULL)
			error(FATAL, "out of space in tostring on %s", s);
		*p = '\0';
	} else {
		p = malloc(strlen(s)+1);
		if (p == NULL)
			error(FATAL, "out of space in tostring on %s", s);
		strcpy(p, s);
	}
	return(p);
}
#ifndef yfree
yfree(char *a)
{
	printf("%o\n", a);
	free(a);
}
#endif
#ifdef malloc
#undef malloc
char *ymalloc(unsigned u)
{	char *p;
	p = malloc(u);
	printf("%o %o\n", u, p);
	return(p);
}
#endif
