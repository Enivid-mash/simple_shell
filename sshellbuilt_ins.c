#include "main.h"


/**
 * prg_abort - program exit
 * @data: A pointer to data structure
 *
 * Return: 0 on success, -ve otherwise
 **/
int prg_abort(sh_t *data __attribute__((unused)))
{
	int i = 0;
	int code;

	if ((*data).args[1] == NULL)
	{
		my_free_data(data);
		exit(errno);
	}
	while ((*data).args[1][i])
	{
		if (my_isalpha((*data).args[1][i++]) < 0)
		{
			(*data).error_msg = my_strdup("illegal number\n");
			return (FAIL);
		}
	}
	code = my_atoi((*data).args[1]);
	my_free_data(data);
	exit(code);
}


#define SETOWD(V) (V = my_strdup(my_env("OLDPWD")))

/**
 * dir_chg - Change directory.
 * @data: A pointer to data structure
 *
 * Return: 0 on success, -ve otherwise
 **/
int dir_chg(sh_t *data)
{
	char *home;

	home = my_env("HOME");
	if ((*data).args[1] == NULL)
	{
		SETOWD((*data).oldpwd);
		if (chdir(home) < 0)
			return (FAIL);
		return (SUCCESS);
	}
	if (my_strcmp((*data).args[1], "-") == 0)
	{
		if ((*data).oldpwd == 0)
		{
			SETOWD((*data).oldpwd);
			if (chdir(home) < 0)
				return (FAIL);
		}
		else
		{
			SETOWD((*data).oldpwd);
			if (chdir((*data).oldpwd) < 0)
				return (FAIL);
		}
	}
	else
	{
		SETOWD((*data).oldpwd);
		if (chdir((*data).args[1]) < 0)
			return (FAIL);
	}
	return (SUCCESS);
}
#undef SETOWD

/**
 * builtin_hdl - Managing builtins commands
 * @data: A pointer to data structure
 *
 * Return: 0 on success, -ve otherwise
 **/
int builtin_hdl(sh_t *data)
{
	blt_t blt[] = {
		{"exit", prg_abort},
		{"cd", dir_chg},
		{"help", hlp_display},
		{NULL, NULL}
	};
	int i = 0;

	while ((blt + i)->cmd)
	{
		if (my_strcmp((*data).args[0], (blt + i)->cmd) == 0)
			return ((blt + i)->f(data));
		i++;
	}
	return (FAIL);
}


/**
 * hlp_display - menu help data
 * @data: A pointer to data structure
 *
 * Return: 0 on success, -ve otherwise
 **/
int hlp_display(sh_t *data)
{
	char c;
	int fd, fw, rd = 1;

	fd = open((*data).args[1], O_RDONLY);
	if (fd < 0)
	{
		(*data).error_msg = my_strdup("Help topic unmatch\n");
		return (FAIL);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			(*data).error_msg = my_strdup("Permission denied\n");
			return (FAIL);
		}
	}
	PRINT("\n");
	return (SUCCESS);
}
