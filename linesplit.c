#include "main.h"
#define DELIMITER " \n\t\r\a\v"
/**
 * ln_split - tokenizes a line
 * @data: Pointer to data structure.
 *
 * Return: +ve on success, -ve otherwise
 **/
int ln_split(sh_t *data)
{
	size_t size = TOKENSIZE, new_size, i = 0;
	char *token;

	if (my_strcmp((*data).line, "\n") == 0)
		return (FAIL);
	(*data).args = malloc(size * sizeof(char *));
	if ((*data).args == NULL)
		return (FAIL);
	token = strtok((*data).line, DELIMITER);
	if (token == NULL)
		return (FAIL);
	while (token)
	{
		(*data).args[i++] =  token;
		if (i + 2 >= size)
		{
			new_size = size * 2;
			(*data).args = my_realloc((*data).args, size * sizeof(char *),
					new_size * sizeof(char *));
			if ((*data).args == NULL)
				return (FAIL);
			size = new_size;
		}
		token = strtok(NULL, DELIMITER);
	}
	(*data).args[i] = NULL;
	return (0);
}
#undef DELIMITER

#define DELIMITER ":"
/**
 * ln_parse - parses arguments to valid command
 * @data: Pointer to data structure.
 *
 * Return: +ve on success, -ve otherwise
 **/
int ln_parse(sh_t *data)
{
	if (path_seq(data) > 0)
		return (SUCCESS);
	if (_builtin(data) > 0)
	{
		if (builtin_hdl(data) < 0)
			return (FAIL);
		return (NEUTRAL);
	}
	short_seq(data);
	return (SUCCESS);
}
#undef DELIMITER

/**
 * path_seq - chekc if the given fikenname is a path
 * @data: Pointer to data structure.
 *
 * Return: +ve on success, -ve otherwise
 **/
int path_seq(sh_t *data)
{
	if (my_strchr((*data).args[0], '/') != 0)
	{
		(*data).cmd = my_strdup((*data).args[0]);
		return (SUCCESS);
	}
	return (FAIL);
}
#define DELIMITER ":"
/**
 * short_seq - chekc if the given fikenname is short form
 * @data: Pointer to data structure.
 *
 * Return: +ve on success, -ve otherwise
 **/
void short_seq(sh_t *data)
{
	int exist_flag = 0;
	char *path, *token, *_path;
	struct stat st;

	path = my_env("PATH");
	_path = my_strdup(path);
	token = strtok(_path, DELIMITER);
	while (token)
	{
		(*data).cmd = my_strcat(token, (*data).args[0]);
		if (stat((*data).cmd, &st) == 0)
		{
			exist_flag += 1;
			break;
		}
		free((*data).cmd);
		token = strtok(NULL, DELIMITER);
	}
	if (exist_flag == 0)
	{
		(*data).cmd = my_strdup((*data).args[0]);
	}
	free(_path);
}
#undef DELIMITER
/**
 * _builtin - checks if the command is builtin
 * @data: Pointer to data structure.
 *
 * Return: +ve on success, -ve otherwise
 **/
int _builtin(sh_t *data)
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
			return (SUCCESS);
		i++;
	}
	return (NEUTRAL);
}
