#ifndef __LIBBB_TINY_H__
#define __LIBBB_TINY_H__

typedef signed char smallint;
typedef unsigned char smalluint;
#define bool smalluint

#define ALIGN1
#define ALIGN2
#define ALWAYS_INLINE
#define NORETURN
#define FAST_FUNC
#define ENABLE_DESKTOP 0
#define NOINLINE
#define TRUE 1
#define FALSE 0
#define ENABLE_LOCALE_SUPPORT 0
#define ENABLE_FEATURE_AWK_LIBM 0
#define ENABLE_FEATURE_ALLOW_EXEC 0
#define MAIN_EXTERNALLY_VISIBLE
#define RETURNS_MALLOC
#define ENABLE_DEBUG 0
#define ENABLE_FEATURE_PREFER_APPLETS 0
#define ENABLE_HUSH 0
#define CONFIG_FEATURE_COPYBUF_KB 2

#define OFF_FMT "l"
#define ENABLE_FEATURE_CLEAN_UP 1

#define PUSH_AND_SET_FUNCTION_VISIBILITY_TO_HIDDEN
#define POP_SAVED_FUNCTION_VISIBILITY

#define ARRAY_SIZE(x) ((unsigned)(sizeof(x) / sizeof((x)[0])))

struct globals *const ptr_to_globals;

#define SET_PTR_TO_GLOBALS(x) do { \
	(*(struct globals**)&ptr_to_globals) = (void*)(x); \
	} while (0)


#include <ctype.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
#include <time.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/socket.h>
#include <setjmp.h>
#include <stdarg.h>


#include <xregex.h>

void *malloc_or_warn(size_t size) FAST_FUNC RETURNS_MALLOC;
void *xmalloc(size_t size) FAST_FUNC RETURNS_MALLOC;
void *xzalloc(size_t size) FAST_FUNC RETURNS_MALLOC;
void *xrealloc(void *old, size_t size) FAST_FUNC;

extern char bb_process_escape_sequence(const char **ptr) FAST_FUNC;

//Import from: libbb.c
extern void bb_error_msg(const char *s, ...) __attribute__ ((format (printf, 1, 2))) FAST_FUNC;
extern void bb_error_msg_and_die(const char *s, ...) __attribute__ ((noreturn, format (printf, 1, 2))) FAST_FUNC;
extern void bb_perror_msg(const char *s, ...) __attribute__ ((format (printf, 1, 2))) FAST_FUNC;
extern void bb_simple_perror_msg(const char *s) FAST_FUNC;
extern void bb_perror_msg_and_die(const char *s, ...) __attribute__ ((noreturn, format (printf, 1, 2))) FAST_FUNC;
extern void bb_simple_perror_msg_and_die(const char *s) NORETURN FAST_FUNC;
extern void bb_herror_msg(const char *s, ...) __attribute__ ((format (printf, 1, 2))) FAST_FUNC;
extern void bb_herror_msg_and_die(const char *s, ...) __attribute__ ((noreturn, format (printf, 1, 2))) FAST_FUNC;
extern void bb_perror_nomsg_and_die(void) NORETURN FAST_FUNC;
extern void bb_perror_nomsg(void) FAST_FUNC;
extern void bb_info_msg(const char *s, ...) __attribute__ ((format (printf, 1, 2))) FAST_FUNC;
extern void bb_verror_msg(const char *s, va_list p, const char *strerr) FAST_FUNC;


//Import from: skip_whitespace.c
char* FAST_FUNC skip_whitespace(const char *s);

//Import from: wfopen.c
FILE* FAST_FUNC fopen_for_read(const char *path);

//Import from: wfopen_input.c
FILE* FAST_FUNC xfopen_stdin(const char *filename);

//import from: xfuncs.c
char* FAST_FUNC itoa(int n);

/* Returns a pointer past the formatted number, does NOT null-terminate */
char *utoa_to_buf(unsigned n, char *buf, unsigned buflen) FAST_FUNC;
char *itoa_to_buf(int n, char *buf, unsigned buflen) FAST_FUNC;

void die_if_ferror(FILE *file, const char *msg) FAST_FUNC;
void die_if_ferror_stdout(void) FAST_FUNC;
int fflush_all(void) FAST_FUNC;
void fflush_stdout_and_exit(int retval) NORETURN FAST_FUNC;
int fclose_if_not_stdin(FILE *file) FAST_FUNC;
FILE* xfopen(const char *filename, const char *mode) FAST_FUNC;
FILE* fopen_or_warn(const char *filename, const char *mode) FAST_FUNC;
FILE* xfopen_stdin(const char *filename) FAST_FUNC;
FILE* fopen_or_warn_stdin(const char *filename) FAST_FUNC;
FILE* fopen_for_read(const char *path) FAST_FUNC;
FILE* xfopen_for_read(const char *path) FAST_FUNC;
FILE* fopen_for_write(const char *path) FAST_FUNC;
FILE* xfopen_for_write(const char *path) FAST_FUNC;
FILE* xfdopen_for_read(int fd) FAST_FUNC;
FILE* xfdopen_for_write(int fd) FAST_FUNC;

//Import from:?
int fflush_all(void) FAST_FUNC;

//Import from: xfuncs_printf.c
char* FAST_FUNC xasprintf(const char *format, ...);

extern void xfunc_die(void) NORETURN FAST_FUNC;

extern const char bb_msg_standard_input[] ALIGN1;
extern const char bb_msg_standard_output[] ALIGN1;
extern const char bb_msg_memory_exhausted[] ALIGN1;

#define LONE_DASH(s)     ((s)[0] == '-' && !(s)[1])
#define NOT_LONE_DASH(s) ((s)[0] != '-' || (s)[1])
#define LONE_CHAR(s,c)     ((s)[0] == (c) && !(s)[1])
#define NOT_LONE_CHAR(s,c) ((s)[0] != (c) || (s)[1])
#define DOT_OR_DOTDOT(s) ((s)[0] == '.' && (!(s)[1] || ((s)[1] == '.' && !(s)[2])))

enum {
LOGMODE_NONE = 0,
LOGMODE_STDIO = (1 << 0),
//LOGMODE_SYSLOG = (1 << 1) * ENABLE_FEATURE_SYSLOG,
//LOGMODE_BOTH = LOGMODE_SYSLOG + LOGMODE_STDIO,
};

extern const char *applet_name;

extern ssize_t full_write(int fd, const void *buf, size_t count) FAST_FUNC;

char *xstrdup(const char *s) FAST_FUNC RETURNS_MALLOC;
char *xstrndup(const char *s, int n) FAST_FUNC RETURNS_MALLOC;
void overlapping_strcpy(char *dst, const char *src) FAST_FUNC;
char *safe_strncpy(char *dst, const char *src, size_t size) FAST_FUNC;

extern ssize_t safe_read(int fd, void *buf, size_t count) FAST_FUNC;
extern ssize_t safe_write(int fd, const void *buf, size_t count) FAST_FUNC;

extern off_t bb_copyfd_eof(int fd1, int fd2) FAST_FUNC;
extern off_t bb_copyfd_size(int fd1, int fd2, off_t size) FAST_FUNC;
extern void bb_copyfd_exact_size(int fd1, int fd2, off_t size) FAST_FUNC;

#define bb_msg_read_error "read error"
#define bb_msg_write_error "write error"

/* NB: (bb_hexdigits_upcase[i] | 0x20) -> lowercase hex digit */
extern const char bb_hexdigits_upcase[];

#define awk_main main

/* Last element is marked by mult == 0 */
struct suffix_mult {
char suffix[4];
unsigned mult;
};

/* Having next pointer as a first member allows easy creation
 * of "llist-compatible" structs, and using llist_FOO functions
 * on them.
 */
typedef struct llist_t {
	struct llist_t *link;
	char *data;
} llist_t;
void llist_add_to(llist_t **old_head, void *data) FAST_FUNC;
void llist_add_to_end(llist_t **list_head, void *data) FAST_FUNC;
void *llist_pop(llist_t **elm) FAST_FUNC;
void llist_unlink(llist_t **head, llist_t *elm) FAST_FUNC;
void llist_free(llist_t *elm, void (*freeit)(void *data)) FAST_FUNC;
llist_t *llist_rev(llist_t *list) FAST_FUNC;
llist_t *llist_find_str(llist_t *first, const char *str) FAST_FUNC;

#endif
