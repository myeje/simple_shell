#include "main.h"

/**
 ** shell_env - function that shows environment
 ** Return: Nothing
 **/
void shell_env(void)
{
	char **env = environ;

	while (*env)
	{
		write(1, *env, len(*env));
		write(1, "\n", 1);
		env++;
	}
}
