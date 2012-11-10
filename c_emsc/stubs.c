#include <stdlib.h>
#include <stdio.h>
#include <wctype.h>

/* These stubs will be called, do nothing and return a meaningful value */

int __locale_mb_cur_max()
{
	return 1;
}

char *setlocale(int category, const char *locale)
{
	return locale;
}



/* These are stubs that should never be called */

void ems_stub_error(const char* func_name)
{
	fprintf(stderr,"emscripten-stub error: '%s' called\n",func_name);
	abort();
}

wint_t btowc(int c)
{
	ems_stub_error("btowc");
	return 0;
}

int iswctype(wint_t wc, wctype_t desc)
{
	ems_stub_error("iswctype");
	return 0;
}

int iswalnum(wint_t wc)
{
	ems_stub_error("iswalnum");
	return 0;
}

wint_t towlower(wint_t wc)
{
	ems_stub_error("towlower");
	return 0;
}

wint_t towupper(wint_t wc)
{
	ems_stub_error("towupper");
	return 0;
}

wctype_t wctype(const char *name)
{
	ems_stub_error("wctype");
	return 0;
}


