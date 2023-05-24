#include "main.h"
/**
 ** exec - function to execute commands in an array
 ** @av: array of strings to execute from
 ** Return: Nothing
 **/
void exec(char **av)
{
	char *user_command = NULL;

	if (av)
	{
		user_command = av[0];
		if (execve(user_command, av, NULL) == -1)
		{
			perror("./test1");
		}
	}
}
