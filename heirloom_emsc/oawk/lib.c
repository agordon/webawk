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

/*	from 4.4BSD /usr/src/old/awk/lib.c	4.11 (Berkeley) 5/26/93	*/
/*	Sccsid @(#)lib.c	1.16 (gritter) 7/16/04>	*/

#include <stdarg.h>
#include "stdio.h"
#include "awk.def"
#include "awk.h"
#include "ctype.h"

extern FILE	*yyin;	/* lex input file */
extern char	*lexprog;	/* points to program argument if it exists */
FILE	*infile	= NULL;
char	*file;
int	RECSIZE;		/* record size */
char	*record;
char	*fields;
char	EMPTY[] = "";

int	MAXFLD;		/* number of allocated fields in fldtab */
int	donefld;	/* 1 = implies rec broken into fields */
int	donerec;	/* 1 = record is valid (no flds have changed) */
int	mustfld;	/* 1 = NF seen, so always break*/

static cell	field0 = {
	"$record", /*record*/EMPTY, 0.0, STR|FLD
};
static cell	FINIT = {
	EMPTY, EMPTY, 0.0, FLD|STR
};

static cell	**fldtab;
int	maxfld	= 0;	/* last used field */

void
growrec(void)
{
	const int	incr = 128;

	record = realloc(record, (RECSIZE + incr + 1) * sizeof *record);
	fields = realloc(fields, (RECSIZE + incr + 1) * sizeof *fields);
	if (record == NULL || fields == NULL)
		error(FATAL, "record `%.20s...' too long", record);
	fldtab[0]->sval = record;
	recloc->sval = record;
	RECSIZE += incr;
}

static void morefields(void)
{
	int	i;
	const int	incr = 32;

	fldtab = realloc(fldtab, (MAXFLD + incr + 1) * sizeof *fldtab);
	if (fldtab == NULL)
		error(FATAL, "record `%.20s...' has too many fields", record);
	for (i = MAXFLD; i < MAXFLD + incr; i++) {
		fldtab[i] = malloc(sizeof **fldtab);
		if (fldtab[i] == NULL)
			error(FATAL,
				"record `%.20s...' has too many fields",
				record);
		*fldtab[i] = FINIT;
	}
	MAXFLD += incr;
}

void
fldinit(void)
{
	morefields();
	*fldtab[0] = field0;
}

int
getrec(void)
{
	register char *rr;
	extern int svargc;
	extern char **svargv;
	register int c, sep, k, m, n;
	wchar_t wc;

	dprintf("**RS=%o, **FS=%o\n", **RS, **FS);
	donefld = 0;
	donerec = 1;
	record[0] = 0;
	while (svargc > 0) {
		dprintf("svargc=%d, *svargv=%s\n", svargc, *svargv);
		if (infile == NULL) {	/* have to open a new file */
			if (member('=', *svargv)) {	/* it's a var=value argument */
				setclvar(*svargv);
				svargv++;
				svargc--;
				continue;
			}
			*FILENAME = file = *svargv;
			dprintf("opening file %s\n", file);
			if (*file == '-') {
				if (yyin == stdin && ! lexprog)
					error(FATAL, "standard input already used for reading commands");
				else
					infile = stdin;
			}
			else if ((infile = fopen(file, "r")) == NULL)
				error(FATAL, "can't open %s", file);
		}
		next(wc, *RS, n);
		if ((sep = **RS) == 0)
			sep = '\n';
		for (rr = record; ; ) {
		cont:	for (; (c=getc(infile)) != sep && c != EOF; *rr++ = c) {
				if (rr >= record+RECSIZE-n-3) {
					size_t	diff = rr - record;
					growrec();
					rr = &record[diff];
				}
			}
			if (c != EOF) {
				/*
				 * Note: This code does not restrict occurences
				 * of the multibyte sequence in RS to the start
				 * of an input character.
				 */
				for (m = 1; m < n; m++) {
					if ((c = getc(infile)) == EOF ||
							c != (*RS)[m]) {
						for (k = 0; k < m; k++)
							*rr++ = (*RS)[k];
						if (c == EOF)
							break;
						*rr++ = c;
						goto cont;
					}

				}
			}
			if (**RS == sep || c == EOF)
				break;
			if ((c = getc(infile)) == '\n' || c == EOF)	/* 2 in a row */
				break;
			if (rr >= record+RECSIZE-n-3) {
				size_t	diff = rr - record;
				growrec();
				rr = &record[diff];
			}
			*rr++ = '\n';
			*rr++ = c;
		}
		*rr = 0;
		if (mustfld)
			fldbld();
		if (c != EOF || rr > record) {	/* normal record */
			recloc->tval &= ~NUM;
			recloc->tval |= STR;
			++nrloc->fval;
			nrloc->tval &= ~STR;
			nrloc->tval |= NUM;
			return(1);
		}
		/* EOF arrived on this file; set up next */
		if (infile != stdin)
			fclose(infile);
		infile = NULL;
		svargc--;
		svargv++;
	}
	return(0);	/* true end of file */
}

void
setclvar(char *s)	/* set var=value from s */
{
	char *p;
	cell *q;

	for (p=s; *p != '='; p++)
		;
	*p++ = 0;
	q = setsymtab(s, tostring(p), 0.0, STR, symtab);
	setsval(q, p);
	dprintf("command line set %s to |%s|\n", s, p);
}

void
fldbld(void)
{
	register char *r, *fr;
	wchar_t wc, sep;
	int i, j, n;

	r = record;
	fr = fields;
	i = 0;	/* number of fields accumulated here */
	next(sep, *FS, n);
	if (sep == ' ')
		for (i = 0; ; ) {
			while (*r == ' ' || *r == '\t' || *r == '\n')
				r++;
			if (*r == 0)
				break;
			i++;
			if (i >= MAXFLD)
				morefields();
			if (!(fldtab[i]->tval&FLD))
				strfree(fldtab[i]->sval);
			fldtab[i]->sval = fr;
			fldtab[i]->tval = FLD | STR;
			next(wc, r, n);
			do {
				do
					*fr++ = *r++;
				while (--n);
				next(wc, r, n);
			} while (wc != ' ' && wc != '\t' && wc != '\n' &&
					wc != '\0');
			*fr++ = 0;
		}
	else if (*r != 0)	/* if 0, it's a null field */
		for (;;) {
			i++;
			if (i >= MAXFLD)
				morefields();
			if (!(fldtab[i]->tval&FLD))
				strfree(fldtab[i]->sval);
			fldtab[i]->sval = fr;
			fldtab[i]->tval = FLD | STR;
			while (next(wc, r, n),
					wc != sep && wc != '\n' && wc != '\0') {
					/* \n always a separator */
				do
					*fr++ = *r++;
				while (--n);
			}
			*fr++ = '\0';
			if (wc == '\0')
				break;
			r += n;
		}
	*fr = 0;
	for (j=MAXFLD-1; j>i; j--) {	/* clean out junk from previous record */
		if (!(fldtab[j]->tval&FLD))
			strfree(fldtab[j]->sval);
		fldtab[j]->tval = STR | FLD;
		fldtab[j]->sval = EMPTY;
	}
	maxfld = i;
	donefld = 1;
	for(i=1; i<=maxfld; i++)
		if(isanumber(fldtab[i]->sval)) {
			fldtab[i]->fval = atof(fldtab[i]->sval);
			fldtab[i]->tval |= NUM;
		}
	setfval(lookup("NF", symtab, 0), (awkfloat) maxfld);
	if (dbg)
		for (i = 0; i <= maxfld; i++)
			printf("field %d: |%s|\n", i, fldtab[i]->sval);
}

void
recbld(void)
{
	int i;
	register char *r, *p;

	if (donefld == 0 || donerec == 1)
		return;
	r = record;
	for (i = 1; i <= *NF; i++) {
		p = getsval(fldtab[i]);
		while (*r++ = *p++) {
			if (r >= record+RECSIZE) {
				size_t	diff = r - record;
				growrec();
				r = &record[diff];
			}
		}
		*(r-1) = **OFS;
	}
	*(r-1) = '\0';
	dprintf("in recbld FS=%lo, recloc=%lo\n", (long)**FS, (long)recloc);
	recloc->tval = STR | FLD;
	dprintf("in recbld FS=%lo, recloc=%lo\n", (long)**FS, (long)recloc);
	/*if (r > record+RECSIZE)
		error(FATAL, "built giant record `%.20s...'", record);*/
	dprintf("recbld = |%s|\n", record);
}

cell *fieldadr(int n)
{
	if (n < 0)
		error(FATAL, "trying to access field %d", n);
	while (n >= MAXFLD)
		morefields();
	return(fldtab[n]);
}

int	errorflag	= 0;

void
yyerror(const char *s) {
	fprintf(stderr, "%s: %s near line %lld\n", progname, s, lineno);
	errorflag = 2;
}

void
error(int isfatal, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	(void)fprintf(stderr, "%s: ", progname);
	(void)vfprintf(stderr, fmt, ap);
	va_end(ap);
	(void)fprintf(stderr, "\n");
	if (NR && *NR > 0)
		(void)fprintf(stderr, " record number %g\n", *NR);
	if (isfatal)
		exit(2);
}

void
PUTS(const char *s) {
	dprintf("%s\n", s/*, NULL, NULL*/);
}

#define	MAXEXPON	38	/* maximum exponenet for fp number */

int
isanumber(register const char *s)
{
	register int d1, d2;
	int point;
	const char *es;

	if (s == NULL) 
		return (0);
	d1 = d2 = point = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '\0')
		return(0);	/* empty stuff isn't number */
	if (*s == '+' || *s == '-')
		s++;
	if (!isdigit(*s & 0377) && *s != *radixchar && (radixcharlen == 1 ||
				strncmp(s, radixchar, radixcharlen) != 0))
		return(0);
	if (isdigit(*s & 0377)) {
		do {
			d1++;
			s++;
		} while (isdigit(*s & 0377));
	}
	if(d1 >= MAXEXPON)
		return(0);	/* too many digits to convert */
	if (*s == *radixchar && (radixcharlen == 1 ||
				strncmp(s, radixchar, radixcharlen) == 0)) {
		point++;
		s += radixcharlen;
	}
	if (isdigit(*s)) {
		d2++;
		do {
			s++;
		} while (isdigit(*s & 0377));
	}
	if (!(d1 || point && d2))
		return(0);
	if (*s == 'e' || *s == 'E') {
		s++;
		if (*s == '+' || *s == '-')
			s++;
		if (!isdigit(*s & 0377))
			return(0);
		es = s;
		do {
			s++;
		} while (isdigit(*s & 0377));
		if (s - es > 2)
			return(0);
		else if (s - es == 2 && 10 * (*es-'0') + *(es+1)-'0' >= MAXEXPON)
			return(0);
	}
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '\0')
		return(1);
	else
		return(0);
}
/*
isanumber(s) char *s; {return(0);}
*/
