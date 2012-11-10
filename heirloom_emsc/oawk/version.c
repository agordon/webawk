#if __GNUC__ >= 3 && __GNUC_MINOR__ >= 4 || __GNUC__ >= 4
#define	USED	__attribute__ ((used))
#elif defined __GNUC__
#define	USED	__attribute__ ((unused))
#else
#define	USED
#endif
static const char sccsid[] USED = "@(#)oawk.sl  2.31 (gritter) 12/25/06";
/* SLIST */
/*
awk.def: *	Sccsid @(#)awk.def	1.19 (gritter) 12/25/06
awk.g.y:	Sccsid @(#)awk.g.y	1.5 (gritter) 7/24/03>	
awk.lx.l:	Sccsid @(#)awk.lx.l	1.13 (gritter) 6/18/05>	
b.c:	Sccsid @(#)b.c	1.10 (gritter) 3/31/03>	
freeze.c:	Sccsid @(#)freeze.c	1.3 (gritter) 3/31/03>	
lib.c:	Sccsid @(#)lib.c	1.16 (gritter) 7/16/04>	
main.c:	Sccsid @(#)main.c	1.11 (gritter) 12/12/04>	
parse.c:	Sccsid @(#)parse.c	1.5 (gritter) 4/21/04>	
proc.c:	Sccsid @(#)proc.c	1.8 (gritter) 12/25/06>	
run.c:	Sccsid @(#)run.c	1.20 (gritter) 12/25/06>	
tran.c:	Sccsid @(#)tran.c	1.7 (gritter) 3/31/03>	
*/
