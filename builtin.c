#include "main.h"

/**
 ** builtin_struct - Function that return amout of builting functions
 ** Return: Amount of builtin functions in integer
 **/
int builtin_struct(void)
{
	char *builtins[] = {
		"exit",
		"env",
		"cd"
	};

	return (sizeof(builtins) / (sizeof(char *)));
}
