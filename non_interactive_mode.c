#include "main.h"

/**
 ** non_interactive_mode - function runs on the unix command line
 ** Return: Nothing
 **/
void non_interactive_mode(void)
{
	int execute_stat = -1;
	char *input;
	char **argv;

	while (execute_stat == -1)
	{
		input = non_int_read();
		argv = parse(input);
		execute_stat = exec(argv);
		free(input);
		free(argv);
		if (execute_stat >= 0)
			exit(execute_stat);
	}
}
