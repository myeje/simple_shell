#include "main.h"

/**
 ** non_int_read - function that reads a line from the stream
 ** Return: pointer to the read line
 **/
char *non_int_read(void)
{
	int i = 0;
	int buffer = 1024;
	char *read_line = malloc(sizeof(char) * buffer);
	int charData;

	if (read_line == NULL)
	{
		perror("Error: Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		charData = getchar();
		if (charData == EOF)
		{
			free(read_line);
			exit(EXIT_SUCCESS);
		}
		else if (charData == '\n')
		{
			read_line[i] = '\0';
			return (read_line);
	
		}
		else
			read_line[i] = charData;
		i++;
		if (i >= buffer)
		{
			buffer += buffer;
			read_line = realloc(read_line, buffer);
			if (read_line == NULL)
			{
				perror("Error: Memory reallocation failed");
				exit(EXIT_FAILURE);
			}
		}
	}
}
