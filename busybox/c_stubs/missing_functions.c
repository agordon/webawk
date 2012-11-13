#include "libbb.h"

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

//void xregcomp(regex_t *preg, const char *regex, int cflags)
//{
//bb_simple_perror_msg_and_die("xregcomp called");
//}

const char *applet_name = "BusyBoxAwk";

// from busybox/applets/individual.c
void bb_show_usage(void)
{
	fputs("(BusyBox AWK Usage)\n",stdout);
	exit(EXIT_FAILURE);
}

int fixed_getopt32(const char* argv[], const char* options,
			/* output*/  char* opt_F,
			/* output*/  llist_t* list_v,
			/* output*/  llist_t* list_f)
{
	if (strcmp(options,"F:v:f:W:")!=0) {
		bb_simple_perror_msg_and_die("internal error in fixed_getopt32");

	}

	int argc = 1;
	while (argv[argc]) {
		node_js_debug("==== getopt32: argv[%d] = '%s'\n", argc, argv[argc]);
		argc++;
	}

	int c;
	int flags=0;

	while ( (c=getopt(argc,argv,options)) != -1 ) {
		node_js_debug("==== getopt32: getopt returned '%c'\n", c);
		switch(c)
		{
		case 'F':
			flags ^= 1;
			opt_F = optarg;
			node_js_debug("==== getopt32: setting -F = '%s'\n", opt_F);
			break;

		case 'v':
			flags ^= 2;
			node_js_debug("==== getopt32: adding -V = '%s'\n", optarg);
			llist_add_to_end(list_v,optarg);
			break;

		case 'f':
			flags ^= 4;
			node_js_debug("==== getopt32: adding -f = '%s'\n", optarg);
			llist_add_to_end(list_f,optarg);
			break;

		case 'W':
			flags ^= 8;
			node_js_debug("==== getopt32: setting -W\n");
			break;

		default:
			bb_simple_perror_msg_and_die("invalid command-line argument");
		}
	}

	return flags;
}

