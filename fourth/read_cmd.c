#include "main.h"

/**
 ** read_cmd - function that reads command
 ** Return: pointer to where the command is stored
 **/
char *read_cmd(void)
{
	char *readline = NULL;
	size_t i = 0;


	if (getline(&readline, &i, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(readline);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(readline);
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	return (readline);
}
