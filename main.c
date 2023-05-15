#include "main.h"

/**
 * main - simple shell
 * @argc: Number of arguments in argv
 * @argv: Arguments to pass to the program
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	char *prompt = "QueenShell$ ";
	char *readline;
	ssize_t read_cmd;
	size_t i = 0;

	(void)argc;
	(void)argv;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 13);
		read_cmd = getline(&readline, &i, stdin);
		if (read_cmd == -1)
		{
			write(STDOUT_FILENO, "\nQuitting Shell...\n", 17);
			return (-1);
		}
		write(STDOUT_FILENO, readline, i);
	}
	free(readline);
	return (0);
}
