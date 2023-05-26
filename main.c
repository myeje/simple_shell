#include "main.h"

/**
 ** main - simple shell
 ** @argc: Number of arguments in argv
 ** @argv: Arguments to pass to the program
 ** Return: 0 if successful
 **/
int main(int argc, char **argv)
{
	ssize_t read_cmd;
	char *readline = NULL;
	size_t i = 0;
	int execute_stat = -1;

	(void)argc;

	if (isatty(STDIN_FILENO) == 1)
	{
		while (execute_stat == -1)
		{
			prompt();
			read_cmd = getline(&readline, &i, stdin);
	
			if (read_cmd == -1)

			{
				if (feof(stdin))
				{
					free(readline);
					exit(EXIT_SUCCESS);
				}
				else{
					free(readline);
					perror("Error");
					exit(EXIT_FAILURE);
				}
			}
			argv = parse(readline);
			execute_stat = exec(argv);
			if (execute_stat >= 0)
				exit(execute_stat);
			free(readline);
			free(argv);
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
