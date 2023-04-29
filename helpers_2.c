#include "main.h"


/**
 * hist_write - Displays history
 * @data: Pointer to data structur
 *
 * Return: +ve on success, -ve otherwise
 **/
int hist_write(sh_t *data __attribute__((unused)))
{
	ssize_t fd, w;
	char *line_of_history = "this is a line of history";
	int len;
	char *filename = "history";

	if (!filename)
		return (-1);

	fd = open(filename, O_RDWR | O_APPEND);

	if (fd < 0)
		return (-1);
	if (line_of_history)
	{
		while (line_of_history[len])
			len++;
		w = write(fd, line_of_history, len);
		if (w < 0)
			return (-1);
	}

	return (1);
}

/**
 * my_env - PATH
 * @path_name: Pointer to PATH
 *
 * Return: +ve on success, -ve otherwis
 **/
char *my_env(char *path_name)
{
	char **environ_cursor;
	char *env_ptr;
	char *name_ptr;

	environ_cursor = environ;

	while (*environ_cursor)
	{
		env_ptr = *environ_cursor;
		name_ptr = path_name;
		while (*env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if ((*env_ptr == '=') && (*name_ptr == '\0'))
			return (env_ptr + 1);
		environ_cursor++;
	}

	return (NULL);
}


/**
 * err_print - Displays error.
 * @data: Pointer to data structure
 *
 * Return: +ve on success, -ve otherwise
 **/
int err_print(sh_t *data)
{
	char *idx = my_itoa((*data).index);

	PRINT("hsh: ");

	PRINT(idx);

	PRINT(": ");

	PRINT((*data).args[0]);

	PRINT(": ");

	PRINT((*data).error_msg);

	free(idx);
	return (0);
}

/**
 * array_populate - populates an array
 * @a: array
 * @el: element
 * @len: array lenth.
 *
 * Return: Pointer
 **/
void *array_populate(void *a, int el, unsigned int len)
{
	unsigned int i = 0;
	char *p = a;

	while (i < len)
	{
		*p = el;
		i++;
		p++;
	}
	return (a);
}

/**
 * reverse_arr - Reverses an array.
 * @arr: array
 * @len: length.
 *
 * Return: void
 **/
void reverse_arr(char *arr, int len)
{
	char tmp;
	int i;

	for (i = 0; i < (len / 2); i++)

	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}
