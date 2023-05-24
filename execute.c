#include "main.h"
/**
 ** exec - function to execute commands in an array
 ** @av: array of strings to execute from
 ** Return: Nothing
 **/
void exec(char **av)
{
	pid_t pid;
	int status;

	if (av)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error: Forked failed");
			return;
		}
		else if (pid == 0)
		{
			if (av[1] != NULL)
			{
				perror("./test1: No such file or directory");
				exit(0);
			}
			if (execve(av[0], av, NULL) == -1)
			{
				perror("./test1");
				exit(0);
			}
		}
		else
			waitpid(pid, &status, 0);
	}
}
