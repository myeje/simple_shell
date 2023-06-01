#include "main.h"

/**
 ** shell_exit - function that exits shell
 ** @argv: arguments
 ** Return: 0 if successful
 **/
int shell_exit(char **argv)
{
	int exit_status = 0;
	int i = 0;

	if (argv[1] != NULL)
	{
		exit_status = _atoi(argv[1]);
		if (exit_status == -1)
		{
			perror("Error: Incorrect exit status\n");
			return (-1);
		}
	}
	for (; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
	exit(exit_status);
}
