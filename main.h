#ifndef _MAIN_H_
#define _MAIN_H_

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

void cmd_exec(char **args);
int sshell_built_ins(void);
char *line_read(void);
char **line_split(char *line);
void my_env(char **args);
void sshell_exit(char **args);
void sshell_cd(char **args);
void sshell_help(char **args);

int _strlen(const char *s);
int _strcmp(char *s1, char *s2);

/**
 * struct builtin - typedef
 * struct - my struct
 * builtin - builtin instance
 * @name: First member
 * @func: Second member
 */
struct builtin
{
	char *name;
	void (*func)(char **args);
};

#endif
