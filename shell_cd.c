#include "main.h"

/**
 ** shell_cd - function that changes directory
 ** @argv: arguments
 ** Return: 1 if successful and 0 otherwise
 **/
int shell_cd(char **argv)
{
	int ret = chdir(argv[1]);

	if (argv[1] == NULL)
	{
		perror("Error: Expected argument to \"cd\"\n");
	}
	else
	{
		if (ret != 0)
		{
			perror("Error: changing dir\n");
		}
	}
	return (-1);
}
