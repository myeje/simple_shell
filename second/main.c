#include "main.h"

int main(int argc, char **argv)
{
	char *read_cmd;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			prompt();
	
		read_cmd = get_input();

		argv = parse(read_cmd);
		if (_compare(argv[0], "exit") == 0)
		{
			free(read_cmd);
			array_free(argv);
			exit(EXIT_SUCCESS);
		}															exec(argv);
		array_free(argv);
		free(read_cmd);
	}
	return (0);
}


void prompt(void)
{
	write(STDOUT_FILENO, "QueenShell$ ", 13);
}


char *get_input(void)
{
	char *input = NULL;
	size_t i = 0;

	if (getline(&input, &i, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
	}
	else
	{
		free(input);
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	return (input);
}

void array_free(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}
