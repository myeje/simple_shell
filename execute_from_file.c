#include "main.h"

/**
 * execute_from_file - function that executes commands from a file
 * @filename: file storing commands
 * Return: Nothing
 */
void execute_from_file(char *filename)
{
	char *cmd_line = NULL;
	size_t i = 0;
	FILE *file;
	ssize_t read;
	char **argv;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		perror("Error: Cannot open file");
		exit(1);
	}
	while ((read = getline(&cmd_line, &i, file)) != -1)
	{
		cmd_line[strcspn(cmd_line, "\n")] = '\0';
		argv = parse(cmd_line);
		exec(argv);
		free(argv);
	}
	free(cmd_line);
	fclose(file);
}
