#include "main.h"

/**
 ** buffer_assign - function that assigns the pointer value for getline
 ** @ptr: A buffer
 ** @str: The string to assign to buffer.
 ** @a: size of buffer
 ** @b: size of string
 **/

void buffer_assign(char **ptr, char *str, size_t *a, size_t b)
{
	if (*a < b)
	{
		if (b > 120)
			*a = b;
		else
			*a = 120;
		*ptr = str;
	}
	else if (*ptr == NULL)
	{
		if (b > 120)
			*a = b;
		else
			*a = 120;
		*ptr = str;
	}
	else
	{
		copy(*ptr, str);
		free(str);
	}
}
