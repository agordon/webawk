all: awk

awk: awk.g.o awk.lx.o b.o main.o token.o tran.o lib.o run.o parse.o proctab.o version.o
	$(LD) $(LDFLAGS) awk.g.o awk.lx.o b.o main.o token.o tran.o lib.o run.o parse.o proctab.o version.o $(LUXRE) -lm $(LCOMMON) $(LWCHAR) $(LIBS) -o awk

awk.g.c: awk.g.y
	$(YACC) -d awk.g.y
	mv -f y.tab.c awk.g.c
	mv -f y.tab.h awk.g.h

token.c: awk.h
	echo '#include "awk.h"' > $@
	echo 'struct toke' >> $@
	echo '{ char *tnm;' >> $@
	echo 'int yval;' >> $@
	echo '} tok[] = {' >> $@
	sed 's/#[ 	]*define[ 	]\{1,\}\([^ 	]*\)[ 	]\{1,\}\(.*\)/{ "\1", \2 },/' \
	    < awk.h >> $@
	echo '};' >> $@
	echo 'char *tokname(int n)' >> $@
	echo '{' >> $@
	echo '	if (n < FIRSTTOKEN || n >= LASTTOKEN)' >> $@
	echo '		n = FIRSTTOKEN;' >> $@
	echo '	return(tok[n - FIRSTTOKEN].tnm);' >> $@
	echo '}' >> $@

proctab.c: awk.h proc.c token.c
	$(HOSTCC) -o proc proc.c
	-./proc > proctab.c

awk.h: awk.g.c
	grep '^#[ 	]*define[ 	]*[^Yy][^Yy]' awk.g.h >awk.h

awk.g.o: awk.g.c
	$(CC) $(CFLAGSS) $(CPPFLAGS) $(XO5FL) $(LARGEF) $(IUXRE) $(ICOMMON) $(IWCHAR) -c awk.g.c

awk.lx.o: awk.lx.c awk.h
	$(CC) $(CFLAGSS) $(CPPFLAGS) $(XO5FL) $(LARGEF) $(IUXRE) $(ICOMMON) $(IWCHAR) -c awk.lx.c

b.o: b.c awk.h
	$(CC) $(CFLAGSS) $(CPPFLAGS) $(XO5FL) $(LARGEF) $(IUXRE) $(ICOMMON) $(IWCHAR) -c b.c

lib.o: lib.c awk.h
	$(CC) $(CFLAGSS) $(CPPFLAGS) $(XO5FL) $(LARGEF) $(IUXRE) $(ICOMMON) $(IWCHAR) -c lib.c

main.o: main.c awk.h
	$(CC) $(CFLAGSS) $(CPPFLAGS) $(XO5FL) $(LARGEF) $(IUXRE) $(ICOMMON) $(IWCHAR) -c main.c

parse.o: parse.c awk.h
	$(CC) $(CFLAGSS) $(CPPFLAGS) $(XO5FL) $(LARGEF) $(IUXRE) $(ICOMMON) $(IWCHAR) -c parse.c

proctab.o: proctab.c
	$(CC) $(CFLAGSS) $(CPPFLAGS) $(XO5FL) $(LARGEF) $(IUXRE) $(ICOMMON) $(IWCHAR) -c proctab.c

run.o: run.c awk.h
	$(CC) $(CFLAGSS) $(CPPFLAGS) $(XO5FL) $(LARGEF) $(IUXRE) $(ICOMMON) $(IWCHAR) -c run.c

tran.o: tran.c awk.h
	$(CC) $(CFLAGSS) $(CPPFLAGS) $(XO5FL) $(LARGEF) $(IUXRE) $(ICOMMON) $(IWCHAR) -c tran.c

token.o: token.c
	$(CC) $(CFLAGSS) $(CPPFLAGS) $(XO5FL) $(LARGEF) $(IUXRE) $(ICOMMON) $(IWCHAR) -c token.c

version.o: version.c
	$(CC) $(CFLAGSS) $(CPPFLAGS) $(XO5FL) $(LARGEF) $(IUXRE) $(ICOMMON) $(IWCHAR) -c version.c

clean:
	rm -f awk.g.o awk.lx.o b.o main.o token.o tran.o lib.o run.o \
		parse.o proctab.o version.o proc.o proc \
		proctab.c token.c awk.h \
		awk.lx.c awk.g.c awk.g.h awk token.c core log *~

install: all
	$(UCBINST) -c awk $(ROOT)$(DEFBIN)/oawk
	$(STRIP) $(ROOT)$(DEFBIN)/oawk
	$(MANINST) -c -m 644 oawk.1 $(ROOT)$(MANDIR)/man1/oawk.1

awk.g.o: awk.def
awk.g.o: awk.def
awk.lx.o: awk.def
b.o: awk.def
lib.o: awk.def
main.o: awk.def
parse.o: awk.def
proc.o: awk.def
proctab.o: awk.def
run.o: awk.def
tran.o: awk.def
