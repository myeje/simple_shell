#include "main.h"

/**
 ** path_finder - function that finds the path of commands
 ** @command: passed command to the path_finder
 ** Return: path to the command
 **/
char *path_finder(char *command)
{
	char *path, *path_copy, *dir, *cmd_path, *finish_line, *bin = "/bin/";

	if (access(command, X_OK) == 0)
		return (strdup(command));
	path = getenv("PATH");
	if (path == NULL)
		perror("ERROR: ");
	path_copy = strdup(path);
	dir = strtok(path_copy, ":");
	cmd_path = NULL;
	while (dir != NULL && cmd_path == NULL)
	{
		finish_line = malloc(len(dir) + len(command) + 2);
		if (finish_line == NULL)
			exit(-1);
		full_path(finish_line, dir, command);
		if (access(finish_line, X_OK) == 0)
			cmd_path = strdup(finish_line);
		free(finish_line);
		dir = strtok(NULL, ":");
	}
	if (cmd_path == NULL)
	{
		finish_line = malloc(len("/bin") + len(command) + 2);
		if (finish_line == NULL)
		{
			perror("Error: failed to allocate memory.\n");
			exit(-1);
		}
		copy(finish_line, bin);
		concate(finish_line, command);
		if (access(finish_line, X_OK) == 0)
			cmd_path = strdup(finish_line);
		free(finish_line);
	}
	free(path_copy);
	return (cmd_path);
}

/**
 ** full_path - function that gets the full path
 ** @fp: file to copy to
 ** @d: first file to copy to fp
 ** @cmd: second filr to copy to fp
 ** Return: Nothing
 **/
void full_path(char *fp, char *d, char *cmd)
{
	copy(fp, d);
	concate(fp, "/");
	concate(fp, cmd);
}
