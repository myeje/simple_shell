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
		prompt();
		read_cmd = getline(&readline, &i, stdin);
		if (read_cmd == -1)
		{
			write(STDOUT_FILENO, "\nQuiting Shell...\n", 17);
			return (-1);
		}
		parse(readline, &argv);
		exec(argv);
	}
	free(argv);
	free(readline);
	return (0);
}
