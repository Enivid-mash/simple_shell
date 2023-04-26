#include "main.h"

/**
 * main - main entry with infinite loop
 * @argc: No use
 * @argv: No use
 * Return: 0
 **/
int main(int argc, char *argv[])
{
	char *line = NULL;
	char **tokens = NULL;
	(void)argc;
	(void)argv;

	while (true)
	{
		write(1, "$ ", 2);
		line = line_read();
		tokens = line_split(line);

		if (tokens[0] != NULL)
			cmd_exec(tokens);

		free(tokens);
		free(line);
	}
}
