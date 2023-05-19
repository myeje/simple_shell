#include "main.h"

/**
 ** prompt - function that prompt the simple shell
 ** Return: Nothing
 **/
void prompt(void)
{
	write(STDOUT_FILENO, "QueenShell$ ", 13);
}
