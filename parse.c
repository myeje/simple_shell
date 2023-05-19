#include "main.h"

/**
 ** parse - fuction that parses user commands
 ** @input: commands from user
 ** @av: array to hold parsed commands
 ** Return: Nothing
 **/
void parse(char *input, char ***av)
{
	const char *delim = " \n";
	char *tk;
	int i = 0;
	int tk_num = 0;
	char *input_copy = NULL;

	input_copy = copy(input);
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
	for (; tk != NULL; i++)
	{
		(*av)[i] = copy(tk);
		tk = strtok(NULL, delim);
	}
	(*av)[i] = NULL;
	free(input_copy);
}
