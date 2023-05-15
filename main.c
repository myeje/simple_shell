#include "main.h"

int main(int argc, char **argv)
{
	char *prompt = "SimpleShell$ ";
	char *readline;
	size_t i = 0;

	(void)argc; (void)argv;
	
	write(STDOUT_FILENO, prompt, 13);
	getline(&readline, &i, stdin);
	write(STDOUT_FILENO, readline, i);

	free(readline);
	return (0);
}
