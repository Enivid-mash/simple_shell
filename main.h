#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define EXIT -3
#define END_OF_FILE -2

extern char **environ;

#define PRINT(c) (write(STDOUT_FILENO, c, my_strlen(c)))
#define PROMPT "$ "
#define BUFSIZE 256
#define TOKENSIZE 64
#define SUCCESS (1)
#define NEUTRAL (0)
#define FAIL (-1)

/**
 * struct sh_data - Global data structure
 *
 * @line: line input
 * @args: arguments token
 * @error_msg: global path
 * @cmd: parsed command
 * @index: command index
 * @oldpwd: old path visited
 * @env: environnment
 *
 * Description: All variables to manage
 **/
typedef struct sh_data
{
	char *line;
	char **args;
	char *cmd;
	char *error_msg;
	char *oldpwd;
	unsigned long int index;
	char *env;
} sh_t;

/**
 * struct builtin - for builtin functions
 * @cmd: command line on string form
 * @f: associated function
 *
 * Description: for managing the builtins commands
 */
typedef struct builtin
{
	char *cmd;
	int (*f)(sh_t *data);
} blt_t;

int ln_split(sh_t *);
int ln_parse(sh_t *);
int ln_read(sh_t *);
int cm_process(sh_t *);
int my_strlen(char *str);
char *my_strchr(char *str, char c);
int my_strcmp(char *s1, char *s2);
void *array_populate(void *a, int el, unsigned int len);
void hdl_signal(int signo);
char *my_env(char *path_name);
char *my_strdup(char *str);
char *my_strcat(char *first, char *second);
char *my_strcpy(char *dest, char *source);
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *my_memset(char *s, char byt, unsigned int n);
char *my_memcpy(char *dest, char *src, unsigned int n);
int my_free_data(sh_t *);
void cm_index(sh_t *data);
int my_isalpha(int c);
int prg_abort(sh_t *data);
int dir_chg(sh_t *data);
int hlp_display(sh_t *data);
void reverse_arr(char *arr, int len);
char *my_itoa(unsigned int n);
int my_intlen(int num);
int my_atoi(char *c);
int err_print(sh_t *data);
int hist_write(sh_t *data);
int builtin_hdl(sh_t *data);
int path_seq(sh_t *data);
void short_seq(sh_t *data);
int _builtin(sh_t *data);

#endif
