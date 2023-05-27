#include "main.h"

/**
 ** main - simple shell
 ** @argc: Number of arguments in argv
 ** @argv: Arguments to pass to the program
 ** Return: 0 if successful
 **/
int main(int argc, char **argv)
{
	char *input;
	int execute_stat = -1;

	(void)argc;

	if (isatty(STDIN_FILENO) == 1)
	{
		while (execute_stat == -1)
		{
			prompt();
			input = read_cmd();
			parse(input, &argv);
			execute_stat = exec(argv);
			free(input);
			free(argv);
			if (execute_stat >= 0)
				exit(execute_stat);
		}
	}
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
