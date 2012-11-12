#include "libbb.h"

unsigned int xatou_range(const char* str, unsigned int min, unsigned int max)
{
	return xstrtou_range(str,10,min,max,NULL);
}

ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
		                            const struct sockaddr *dest_addr, socklen_t addrlen)
{
bb_simple_perror_msg_and_die("sendto called");
	return -1;
}

char *mktemp(char *template)
{
bb_simple_perror_msg_and_die("mktemp called");
return NULL;
}

int mkstemp(char *template)
{
bb_simple_perror_msg_and_die("mkstemp called");
return -1;
}

int _ZNSt9exceptionD2Ev_XXXX()
{
bb_simple_perror_msg_and_die("__ZNSt9exceptionD2Ev called");
return -1;
}

void xregcomp(regex_t *preg, const char *regex, int cflags)
{
bb_simple_perror_msg_and_die("xregcomp called");
}

const char *applet_name = "BusyBoxAwk";

// from busybox/applets/individual.c
void bb_show_usage(void)
{
	fputs("(BusyBox AWK Usage)\n",stdout);
	exit(EXIT_FAILURE);
}
