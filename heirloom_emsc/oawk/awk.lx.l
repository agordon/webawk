%{
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

/*	from 4.4BSD /usr/src/old/awk/awk.lx.l	4.5 (Berkeley) 4/17/91	*/
/*	Sccsid @(#)awk.lx.l	1.13 (gritter) 6/18/05>	*/
%}

%X str chc reg esc comment

%{
#include	<string.h>
#include	<unistd.h>
#include	"awk.h"
#include	"awk.def"
extern void	*yylval;
extern int	mustfld;
extern int	ldbg;
extern char	*lexprog;

#define	cast	(void *)(intptr_t)

#ifdef	FLEX_SCANNER
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size)				\
{								\
	if ( lexprog )						\
		{						\
		result = strlen( lexprog );			\
		if ( result > max_size )			\
			{					\
			result = max_size;			\
			strncpy( buf, lexprog, result );	\
			}					\
		else						\
			strcpy( buf, lexprog );			\
		lexprog += result;				\
		}						\
	else							\
		result = read( fileno(yyin), buf, max_size );	\
}
#else	/* !FLEX_SCANNER */
#undef	input
int	input(void)
{
	register int c;
	extern char	*lexprog;

	if (yysptr > yysbuf)
		c = U(*--yysptr) & 0377;
	else if (yyin == NULL)
		c = *lexprog++ & 0377;
	else
		c = getc(yyin);
	if (c == '\n')
		yylineno++;
	else if (c == EOF)
		c = 0;
	return(c);
}
#endif	/* !FLEX_SCANNER */

long long	lineno	= 1;
#define	RETURN(x)	{if (ldbg) ptoken(x); return(x); }
#define	CADD	cbuf[clen++]=yytext[0]; if(clen>=CBUFLEN-1) {yyerror("string too long"); BEGIN INITIAL;}
#define	CBUFLEN	800
char	cbuf[CBUFLEN];
int	clen, cflag;

static void	ptoken(int);
%}

A	[a-zA-Z_]
B	[a-zA-Z0-9_]
D	[0-9]
WS	[ \t]

%%
	static int sc_flag = 0;

	if ( sc_flag ) {
		BEGIN INITIAL;
		sc_flag = 0;
		RETURN('}');
	}

^\n		lineno++;
^{WS}*#.*\n	lineno++;	/* strip comment lines */
{WS}		;
<INITIAL,reg>"\\"\n	lineno++;
"||"		RETURN(BOR);
BEGIN	RETURN(XBEGIN);
END		RETURN(XEND);
PROGEND	RETURN(EOF);
"&&"		RETURN(AND);
"!"		RETURN(NOT);
"!="		{ yylval = cast NE; RETURN(RELOP); }
"~"		{ yylval = cast MATCH; RETURN(MATCHOP); }
"!~"		{ yylval = cast NOTMATCH; RETURN(MATCHOP); }
"<"		{ yylval = cast LT; RETURN(RELOP); }
"<="		{ yylval = cast LE; RETURN(RELOP); }
"=="		{ yylval = cast EQ; RETURN(RELOP); }
">="		{ yylval = cast GE; RETURN(RELOP); }
">"		{ yylval = cast GT; RETURN(RELOP); }
">>"		{ yylval = cast APPEND; RETURN(RELOP); }
"++"		{ yylval = cast INCR; RETURN(INCR); }
"--"		{ yylval = cast DECR; RETURN(DECR); }
"+="		{ yylval = cast ADDEQ; RETURN(ASGNOP); }
"-="		{ yylval = cast SUBEQ; RETURN(ASGNOP); }
"*="		{ yylval = cast MULTEQ; RETURN(ASGNOP); }
"/="		{ yylval = cast DIVEQ; RETURN(ASGNOP); }
"%="		{ yylval = cast MODEQ; RETURN(ASGNOP); }
"="		{ yylval = cast ASSIGN; RETURN(ASGNOP); }

"$"{D}+	{	if (atoi(yytext+1)==0) {
				yylval = lookup("$record", symtab, 0);
				RETURN(STRING);
			} else {
				yylval = fieldadr(atoi(yytext+1));
				RETURN(FIELD);
			}
		}
"$"{WS}*	{ RETURN(INDIRECT); }
NF		{ mustfld=1; yylval = setsymtab(yytext, EMPTY, 0.0, NUM, symtab); RETURN(VAR); }
({D}+("."?){D}*|"."{D}+)((e|E)("+"|-)?{D}+)?	{
		yylval = setsymtab(yytext, EMPTY, atof(yytext), CON|NUM, symtab); RETURN(NUMBER); }
"}"{WS}*\n	{ sc_flag = 1; lineno++; RETURN(';'); }
"}"		{ sc_flag = 1; RETURN(';'); }
;\n		{ lineno++; RETURN(';'); }
\n		{ lineno++; RETURN(NL); }
while	RETURN(WHILE);
for		RETURN(FOR);
if		RETURN(IF);
else		RETURN(ELSE);
next		RETURN(NEXT);
exit		RETURN(EXIT);
break	RETURN(BREAK);
continue	RETURN(CONTINUE);
print	{ yylval = cast PRINT; RETURN(PRINT); }
printf	{ yylval = cast PRINTF; RETURN(PRINTF); }
sprintf	{ yylval = cast SPRINTF; RETURN(SPRINTF); }
split	{ yylval = cast SPLIT; RETURN(SPLIT); }
substr	RETURN(SUBSTR);
index	RETURN(INDEX);
in		RETURN(IN);
getline	RETURN(GETLINE);
length	{ yylval = cast FLENGTH; RETURN(FNCN); }
log		{ yylval = cast FLOG; RETURN(FNCN); }
int		{ yylval = cast FINT; RETURN(FNCN); }
exp		{ yylval = cast FEXP; RETURN(FNCN); }
sqrt		{ yylval = cast FSQRT; RETURN(FNCN); }
{A}{B}*	{ yylval = setsymtab(yytext, tostring(""), 0.0, STR|NUM, symtab); RETURN(VAR); }
\"		{ BEGIN str; clen=0; }

#		{ BEGIN comment; }
<comment>\n	{ BEGIN INITIAL; lineno++; RETURN(NL); }
<comment>.	;

.		{ yylval = cast yytext[0]; RETURN(yytext[0]); }

<reg>"["	{ BEGIN chc; CADD; }
<reg>"[^"	{ BEGIN chc; CADD; }
<reg>"\\"	{ BEGIN esc; CADD; }
<reg>"/"	{ BEGIN INITIAL;
		  cbuf[clen] = 0;
		  yylval = tostring(cbuf);
		  unput('/');
		  RETURN(REGEXPR); }
<reg>\n		{ yyerror("newline in regular expression"); lineno++; BEGIN INITIAL; }
<reg>.		{ CADD; }

<str>\"		{ char *s; BEGIN INITIAL; cbuf[clen]=0; s = tostring(cbuf);
		cbuf[clen] = ' '; cbuf[++clen] = 0;
		yylval = setsymtab(cbuf, s, 0.0, CON|STR, symtab); RETURN(STRING); }
<str>\n		{ yyerror("newline in string"); lineno++; BEGIN INITIAL; }
<str>"\\\""	{ cbuf[clen++]='"'; }
<str>"\\"n	{ cbuf[clen++]='\n'; }
<str>"\\"t	{ cbuf[clen++]='\t'; }
<str>"\\"r	{ cbuf[clen++]='\r'; }
<str>"\\"b	{ cbuf[clen++]='\b'; }
<str>"\\"f	{ cbuf[clen++]='\f'; }
<str>"\\\\"	{ cbuf[clen++]='\\'; }
<str>.		{ CADD; }

<chc>"\\""]"	{ cbuf[clen++] = '\\'; cbuf[clen++]=']'; }
<chc>"]"	{ BEGIN reg; CADD; }
<chc>\n		{ yyerror("newline in character class"); lineno++; BEGIN INITIAL; }
<chc>.		{ CADD; }
<esc>.		{ BEGIN reg; CADD; }

%%

void
startreg(void)
{
	BEGIN reg;
	clen = 0;
}

static void
ptoken(int n)
{
	extern struct tok {
		char *tnm;
		int yval;
	} tok[];

	printf("lex:");
	if (n < 128) {
		printf(" %c\n",n);
		return;
	}
	if (n <= 256 || n >= LASTTOKEN) {
		printf("? %o\n",n);
		return;
	}
	printf(" %s",tok[n-257].tnm);
	switch (n) {

	case RELOP:
	case MATCHOP:
	case ASGNOP:
	case STRING:
	case FIELD:
	case VAR:
	case NUMBER:
	case FNCN:
		printf(" (%s)", yytext);
		break;

	case CHAR:
		printf(" (%lo)", (long)yylval);
		break;
	}
	putchar('\n');
}
