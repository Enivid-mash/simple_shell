#include "main.h"

/**
 * my_env - env builtin command
 * @args: argument
 **/
void my_env(char **args)
{
	char **envp = environ;

	(void)args;

	while (*envp != NULL)
	{
		write(1, *envp, _strlen(*envp));
		write(1, "\n", 1);
		envp++;
	}
}


/**
 * sshell_exit - exit builtin command
 * @args: argument
 **/
void sshell_exit(char **args)
{

	(void)args;

	exit(0);
}


/**
 * sshell_cd - cd builtin command
 * @args: argument
 **/
void sshell_cd(char **args)
{

	(void)args;

	if (args[1] == NULL)
	{
		write(2, "./simple_shell: cd: not implemented\n", 35);
		write(1, "\n", 1);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("./simple_shell: cd");
		}
	}
}

/**
 * sshell_help - help builtin command
 * @args: argument
 **/
void sshell_help(char **args)
{
	char *helptext =
		"The following commands are built in:\n"
		"  cd       Change the working directory.\n"
		"  exit     Exit the shell.\n"
		"  help     Print this help text.\n"
		;

	(void)args;

	write(1, helptext, _strlen(helptext));
}
