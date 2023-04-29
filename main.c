#include "main.h"

/**
 * main - main entry with infinite loop
 * @argc: No use
 * @argv: No use
 * Return: 0
 **/
int main(int argc, char *argv[])
{
	int pl;
	sh_t data;

	(void)argc, (void)argv;
	my_memset((void *)&data, 0, sizeof(data));
	signal(SIGINT, hdl_signal);
	while (1)
	{
		cm_index(&data);
		if (ln_read(&data) < 0)
		{
			if (isatty(STDIN_FILENO))
				PRINT("\n");
			break;
		}
		if (ln_split(&data) < 0)
		{
			my_free_data(&data);
			continue;
		}
		pl = ln_parse(&data);
		if (pl == 0)
		{
			my_free_data(&data);
			continue;
		}
		if (pl < 0)
		{
			err_print(&data);
			continue;
		}
		if (cm_process(&data) < 0)
		{
			err_print(&data);
			break;
		}
		my_free_data(&data);
	}
	my_free_data(&data);
	exit(EXIT_SUCCESS);
}

/**
 * hdl_signal - handles process signal.
 * @signo: Signal identifier
 *
 * Return: void
 **/
void hdl_signal(int signo)
{
	if (signo == SIGINT)

	{
		PRINT("\n");

		PRINT(PROMPT);
	}
}
