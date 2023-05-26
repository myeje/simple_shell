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
