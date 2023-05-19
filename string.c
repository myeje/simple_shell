#include "main.h"

/**
 ** len - function that counts the length of string
 ** @str: string to count
 ** Return: string count
 **/
int len(const char *str)
{
	int i = 0;

	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

/**
 ** copy - function that copies content from one location to another
 ** @original: copy from
 ** Return: pointer to location of copy
 **/
char *copy(const char *original)
{
	size_t length = len(original);
	char *destination;
	char *ptr;

	destination = malloc((length + 1) * sizeof(char));
	if (destination == NULL)
	{
		perror("Error: Memory allocation failed.\n");
		return (NULL);
	}

	ptr = destination;

	while (*original != '\0')
	{
		*ptr = *original;
		ptr++;
		original++;
	}
	*ptr = '\0';
	return (destination);
}

/**
 ** _compare - function that compares the content of 2 pointers
 ** @s1: compare with
 ** @s2: compare with
 ** Return: 0 if successful
 **/
int _compare(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return ((*s1 < *s2) ? -1 : 1);
}
