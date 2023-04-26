#include "main.h"

/**
 * line_read - func with infinite loop
 *
 * Return: read line
 **/
char *line_read(void)
{
	ssize_t streamlen;
	char *line = NULL;
	size_t buflen = 0;

	errno = 0;

	streamlen = getline(&line, &buflen, stdin);
	if (streamlen < 0)
	{
		if (errno)
			perror("./simple_shell");
		exit(1);
	}
	return (line);
}
