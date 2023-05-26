#include "main.h"

/**
 ** shell_env - function that shows enviroment
 ** @args: arguments
 ** Return: 1 if successful and 0 otherwise
 **/
int shell_env(char **argv)
{
	int i = 0;
	int ret = 0;
	(void)argv;
        
	while (environ[i])
	{
		ret = write(STDOUT_FILENO, environ[i], len(environ[i]));
		if (ret == -1)
			return (-1);
		
		ret = write(STDOUT_FILENO, "\n", 1);
		if (ret == -1)
			return (-1);
		i++;
	}
	return (-1);
}

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
