#include "main.h"

/**
<<<<<<< HEAD
 ** exec - function that executes user command
=======
 ** exec - function that checks if command is bulitin
 ** @argv: array of commands to execute
 ** Return: 1 if successful
 **/

int exec(char **argv)
{
	int a = 0;
	char *builtins[] = {
		"exit",
		"env",
		"cd"
	};
	int (*builtin_functions[])(char **) = {

		&shell_exit,
		&shell_env,
		&shell_cd
	};

	if (argv[0] == NULL)
	{
		perror("Error");
		return (-1);
	}

	while (a < builtin_struct())
	{
		if (_compare(argv[0], builtins[a]) == 0)
			return ((*builtin_functions[a])(argv));
		a++;
	}
	return (exec_external(argv));
}

/**
 ** exec_external - function that executes user command
>>>>>>> 308fe72b32da175bea21729a3541cac91472ea4a
 ** @argv: array of commands to execute
 ** Return: Nothing
 **/
void exec(char **argv)
{
	int status;
	pid_t pid;
<<<<<<< HEAD
	char *path;

	if (argv && argv[0])
	{
		pid = fork();
		if (pid < 0)
=======
	int stat;

	pid = fork();
	if (pid < 0)
		perror("Error: Fork failed");
	else if (pid ==  0)
	{
		char *path = path_finder(argv[0]);

		if (execve(path, argv, NULL) == -1)
>>>>>>> 308fe72b32da175bea21729a3541cac91472ea4a
		{
			perror("Error: Fork failed");
			return;
		}
		else if (pid == 0)
		{
			path = path_finder(argv[0]);
			if (path == NULL)
			{
				perror("Error: Command not found\n");
				exit(EXIT_FAILURE);
			}
			execve(path, argv, NULL);
			perror("Error: Execution failed");
			exit(EXIT_FAILURE);
		}
<<<<<<< HEAD
		else
=======
	}
	else
	{
		while (1)
>>>>>>> 308fe72b32da175bea21729a3541cac91472ea4a
		{
			if (waitpid(pid, &status, 0) == -1)
				perror("Error: Wait failed");
			else if (!WIFEXITED(status))
			perror("Error: Child process did not exit properly\n");
		}
	}
}
