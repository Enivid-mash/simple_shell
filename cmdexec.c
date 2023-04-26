#include "main.h"

/**
 * struct builtin - kkdl dd
 * struct builtin builtins[] - kkkkk kkkk
 * @sshell_help: First member
 * @sshell_exit: Second member
 * @sshell_cd: Third member
 * @my_env: Fourth member
 */
struct builtin builtins[] = {
	{"help", sshell_help},
	{"exit", sshell_exit},
	{"cd", sshell_cd},
	{"env", my_env},
};

/**
 * sshell_built_ins - executes commands
 * Return: integer value of registered commands.
 **/
int sshell_built_ins(void)
{
	return (sizeof(builtins) / sizeof(struct builtin));
}

/**
 * cmd_exec - executes commands
 * @args: argument from parser
 **/
void cmd_exec(char **args)
{
	int i;
	pid_t child_pid = fork();

	for (i = 0; i < sshell_built_ins(); i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return;
		}
	}
	if (child_pid == 0)
	{
		execve(args[0], args, environ);
		perror("./simple_shell");
		exit(1);
	}
	else if (child_pid > 0)
	{
		int status;

		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
		perror("./simple_shell");
}
