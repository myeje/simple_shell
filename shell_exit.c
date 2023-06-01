#include "main.h"

/**
 ** shell_exit - function that exits shell
 ** @argv: arguments
 ** Return: 0 if successful
 **/
int shell_exit(char **argv)
{
	if (argv[1])
	{
		return (_atoi(argv[1]));
	}

	exit(EXIT_SUCCESS);
	return (0);
}
