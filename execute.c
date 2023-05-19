#include "main.h"

/**
 ** exec - function that executes user command
 ** @argv: array of commands to execute
 ** Return: Nothing
 **/
void exec(char **argv)
{
	char *cmd = NULL;

	if (argv)
	{
		cmd = argv[0];

		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
