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

#ifdef	notdef
char copyright[] =
"Copyright (c) 1991 The Regents of the University of California.\n\
 All rights reserved.\n";
#endif

/*	from 4.4BSD /usr/src/old/awk/main.c	4.6 (Berkeley) 4/17/91	*/
/*	Sccsid @(#)main.c	1.11 (gritter) 12/12/04>	*/

#include "stdio.h"
#include "ctype.h"
#include "awk.def"
#include "awk.h"
#include <libgen.h>
#include <locale.h>
#include <langinfo.h>

int	dbg	= 0;
int	ldbg	= 0;
#ifdef	notdef
int	svflg	= 0;
#endif
int	rstflg	= 0;
int	svargc;
char	**svargv, **xargv;
extern FILE	*yyin;	/* lex input file */
char	*lexprog;	/* points to program argument if it exists */
extern	int errorflag;	/* non-zero if any syntax errors; set by yyerror */

int filefd, symnum, ansfd, mb_cur_max;
const char *radixchar = ".";
int radixcharlen = 1;
char *filelist;
char *progname;
extern int maxsym;
int
main(int argc, char **argv) {
	setlocale(LC_COLLATE, "");
	setlocale(LC_CTYPE, "");
	setlocale(LC_NUMERIC, "C");
	mb_cur_max = MB_CUR_MAX;
	progname = tostring(basename(argv[0]));
	if (argc == 1)
		error(FATAL, "Usage: %s [-f source | 'cmds'] [files]",
				progname);
	fldinit();
	syminit();
	growrec();
	while (argc > 1) {
		argc--;
		argv++;
		/* this nonsense is because gcos argument handling */
		/* folds -F into -f.  accordingly, one checks the next */
		/* character after f to see if it's -f file or -Fx.
		*/
		if (argv[0][0] == '-' && argv[0][1] == 'f' &&
				argv[0][2] == '\0') {
			if (argv[1] == NULL)
				error(FATAL, "no argument for -f");
			if (argv[1][0] == '-' && argv[1][1] == '\0')
				yyin = stdin;
			else {
				yyin = fopen(argv[1], "r");
				if (yyin == NULL)
					error(FATAL, "can't open %s", argv[1]);
			}
			argc--;
			argv++;
			break;
		} else if (argv[0][0] == '-' && argv[0][1] == 'F') {	/* set field sep */
			if (argv[0][2] == 't')	/* special case for tab */
				**FS = '\t';
			else
				*FS = tostring(&argv[0][2]);
			continue;
		} else if (argv[0][0] != '-') {
			dprintf("cmds=|%s|\n", argv[0]);
			yyin = NULL;
			lexprog = argv[0];
			argv[0] = argv[-1];	/* need this space */
			break;
		} else if (strcmp("-d", argv[0])==0) {
			dbg = 1;
#ifdef	notdef
		}
		else if (strcmp("-l", argv[0])==0) {
			ldbg = 1;
		}
		else if(strcmp("-S", argv[0]) == 0) {
			svflg = 1;
		}
		else if(strncmp("-R", argv[0], 2) == 0) {
			if(thaw(argv[0] + 2) == 0)
				rstflg = 1;
			else {
				fprintf(stderr, "not restored\n");
				exit(1);
			}
#endif	/* !notdef */
		}
	}
	if (argc <= 1) {
		argv[0][0] = '-';
		argv[0][1] = '\0';
		argc++;
		argv--;
	}
	svargc = --argc;
	svargv = ++argv;
	dprintf("svargc=%d svargv[0]=%s\n", svargc, svargv[0]);
	*FILENAME = *svargv;	/* initial file name */
	if(rstflg == 0)
		yyparse();
	dprintf("errorflag=%d\n", errorflag);
	if (errorflag)
		exit(errorflag);
#ifdef	notdef
	if(svflg) {
		svflg = 0;
		if(freeze("awk.out") != 0)
			fprintf(stderr, "not saved\n");
		exit(0);
	}
#endif
	setlocale(LC_NUMERIC, "");
	if (*(radixchar = nl_langinfo(RADIXCHAR)) != '\0')
		radixchar = tostring(radixchar);
	else
		radixchar = ".";
	radixcharlen = strlen(radixchar);
	run();
	exit(errorflag);
}

int
yywrap(void)
{
	return(1);
}
