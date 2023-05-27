#include "main.h"

/**
 ** parse - fuction that parses user commands
 ** @input: commands from user
 ** @av: array to hold parsed commands
 ** Return: Nothing
 **/

char **parse(char *input)
{
	const char *delim = " \t\r\n\a\"";
	char **token;
	char *tk;
	int i = 0;
	int buffer = 64;
	
	token = malloc(buffer * sizeof(char));
	if (token == NULL)
	{
		perror("Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	tk = strtok(input, delim);
						    
	for (; tk != NULL; i++)
	{
		if (tk[0] == '#')
			break;
		token[i] = tk;
		if (i >= buffer)
		{
			buffer += buffer;
			token = realloc(token, buffer * sizeof(char *));
			if (token != NULL)
			{
				perror("Error: Memory reallocation failed");
				exit(EXIT_FAILURE);
			}
		}
		tk = strtok(NULL, delim);
	}
	token[i] = NULL;
	return (token);
}
