#include "main.h"

/**
 ** shell_exit - function that exits shell
 ** @args: arguments
 ** Return: 0 if successful
 **/
int shell_exit(char **argv)
{
	if (argv[1])
		return (atoi(argv[1]));
	else
		exit(EXIT_SUCCESS);
	return (0);
}