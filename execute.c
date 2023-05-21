#include "main.h"

/**
 ** exec - function that executes user command
 ** @argv: array of commands to execute
 ** Return: Nothing
 **/
void exec(char **argv)
{
	int status;
	pid_t pid;
	char *path;

	if (argv && argv[0])
	{
		pid = fork();
		if (pid < 0)
		{
			perror("Error: Fork failed");
			return;
		}
		else if (pid == 0)
		{
			path = path_finder(av[0]);
			if (path == NULL)
			{
				perror("Error: Command not found\n");
				exit(EXIT_FAILURE);
			}
			execve(path, argv, NULL);
			perror("Error: Execution failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			if (waitpid(pid, &status, 0) == -1)
				perror("Error: Wait failed");
			else if (!WIFEXITED(status))
			perror("Error: Child process did not exit properly\n");
		}
	}
}
