#include "main.h"


/**
 * cm_process - command executor
 * @data: Pointer to data Structure.
 *
 * Return: +ve on success, -ve otherwise.
 **/
int cm_process(sh_t *data)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve((*data).cmd, (*data).args, environ) < 0)
			(*data).error_msg = my_strdup("Command Not Found\n");
		return (FAIL);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}
	return (0);
}

/**
 * cm_index - indexed command
 * @data: Pointer to data Structure.
 *
 * Return: void
 **/
void cm_index(sh_t *data)
{
	(*data).index += 1;
}
