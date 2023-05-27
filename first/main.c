#include "main.h"

/**
 * main - simple shell
 * @argc: Number of arguments in argv
 * @argv: Arguments to pass to the program
 * Return: 0 if successful
 */
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
			exit(EXIT_SUCCESS);
		}
		parse(readline, &argv);
		if (_compare(argv[0], "exit") == 0)
		{
			for (i = 0; argv[i] != NULL; i++)
				free(argv[i]);
			free(argv);
			free(readline);
			exit(EXIT_SUCCESS);
		}
		if (_compare(argv[0], "env") == 0)
		{
			shell_env();
			for (i = 0; argv[i] != NULL; i++)
				free(argv[i]);
			free(argv);
			continue;
		}
		exec(argv);
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free(argv);
	}
	free(readline);
	return (0);
}
<<<<<<< HEAD
=======

/**
 ** array_free - function that frees an array
 ** @argv: array to free
 **/
void array_free(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
}


/**
 ** prompt - function that prompt the simple shell
 ** Return: prompt
 **/
char prompt(void)
{
	char ret;

	ret = write(STDOUT_FILENO, "QueenShell$ ", 13);
	return (ret);
}
>>>>>>> 308fe72b32da175bea21729a3541cac91472ea4a
