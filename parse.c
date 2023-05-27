#include "main.h"

/**
 ** parse - fuction that parses user commands
 ** @input: commands from user
 ** @av: array to hold parsed commands
 ** Return: Nothing
 **/

void parse(char *input, char ***av)
{
	const char *delim = " \t\r\n\a\"";
	char *tk;
	int i;
	int tk_num = 0;
	char *input_copy = NULL;


	input_copy = malloc((len(input) + 1) * sizeof(char));
	if (input_copy == NULL)
	{
		perror("Error: Memory allocation failed\n");
		return;
	}
	copy(input_copy, input);
	tk = strtok(input_copy, delim);
	for (; tk != NULL; tk_num++)
		tk = strtok(NULL, delim);
	tk_num++;
	*av = malloc(sizeof(char *) * tk_num);
	if (*av == NULL)
	{
		perror("Error: Memory allocation failed");
		return;
	}
	tk = strtok(input, delim);
	for (i = 0; tk != NULL; i++)
	{
		if (tk[0] == '#')
		{
			break;
		}
	
		(*av)[i] = malloc(sizeof(char) * (len(tk) + 1));

		copy((*av)[i], tk);
		tk = strtok(NULL, delim);
	}
	(*av)[i] = NULL;
	free(input_copy);
}
