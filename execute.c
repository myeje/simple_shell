#include "main.h"

/**
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
 ** @argv: array of commands to execute
 ** Return: Nothing
 **/
int exec_external(char **argv)
{
	pid_t pid;
	int status;
	
	pid = fork();
	if (pid < 0)
		perror("Error: Fork failed");
	else if (pid ==  0)
	{
		char *path = path_finder(argv[0]);
		if (execve(path, argv, NULL) == -1)
		{
			perror("error in new_process: child process");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
	return (-1);
}
