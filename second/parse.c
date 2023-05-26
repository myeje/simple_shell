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
		
	token = malloc((len(input) + 1) * sizeof(char));
	if (token == NULL)
	{
		perror("Error: Memory allocation failed\n");
		return (0);
	}
	tk = strtok(input, delim);
	
	for (; tk != NULL; i++)
	{
		if (tk[0] == '#')
		{
			break;
		}
		token[i] = tk;
		tk = strtok(NULL, delim);
	}
	i++;
	token[i] = NULL;
	return (token);
}
