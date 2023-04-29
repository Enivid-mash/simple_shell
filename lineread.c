#include "main.h"


/**
 * ln_read - reads line.
 * @data: Pointer to data structure.
 *
 * Return: +ve on success, -ve otherwise
 **/
int ln_read(sh_t *data)
{
	size_t size = BUFSIZE, read_st, length, new_size;
	char *csr_ptr, *end_ptr, c;

	(*data).line = malloc(size * sizeof(char));
	if ((*data).line == NULL)
	{
		return (FAIL);
	}
	if (isatty(STDIN_FILENO))
	{
		PRINT(PROMPT);
	}
	for (csr_ptr = (*data).line, end_ptr = (*data).line + size;;)
	{
		read_st = read(STDIN_FILENO, &c, 1);
		if (read_st == 0)
			return (FAIL);
		*csr_ptr++ = c;
		if (c == '\n')
		{
			*csr_ptr = '\0';
			return (SUCCESS);
		}
		if (csr_ptr + 2 >= end_ptr)
		{
			new_size = size * 2;
			length = csr_ptr - (*data).line;
			(*data).line = my_realloc((*data).line, size * sizeof(char),
					new_size * sizeof(char));
			if ((*data).line == NULL)
				return (FAIL);
			size = new_size;
			end_ptr = (*data).line + size;
			csr_ptr = (*data).line + length;
		}
	}
}
