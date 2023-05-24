#include "main.h"

/**
 ** main - simple shell
 ** @argc: Number of arguments in argv
 ** @argv: Arguments to pass to the program
 ** Return: 0 if successful
 **/
int main(int argc, char **argv)
{
	char *readline;
	ssize_t read_cmd;
	size_t i = 0;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		read_cmd = getline(&readline, &i, stdin);
		if (read_cmd == -1)
		{
			free(readline);
			exit(0);
		}
		parse(readline, &argv);
		exec(argv);
		array_free(argv);
	}
	free(readline);
	return (0);
}


/**
 ** array_free - function that frees an array
 ** @argv: array to free
 **/
void array_free(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}


/**
 ** prompt - function that prompt the simple shell
 ** Return: Nothing
 **/
void prompt(void)
{
	write(STDOUT_FILENO, "QueenShell$ ", 13);
}
