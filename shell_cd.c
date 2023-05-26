#include "main.h"

/**
 ** shell_cd - function that changes directory
 ** @args: arguments
 ** Return: 1 if successful and 0 otherwise
 **/
int shell_cd(char **argv)
{
	int ret = chdir(argv[1]);
	
	if (ret != 0)
		perror("Error: Cannot change directory");
	if (argv[1] == NULL)
		perror("Error: Specify directory");
	return (-1);
}
