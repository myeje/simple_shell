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
 ** copy - function copies chars from one pointer to another
 ** @destination: pointer to where the new copy should be stroed
 ** @original: pointer to string to copy
 ** Return: copied chars
 **/
char *copy(char *destination, const char *original)
{
	char *ptr = destination;

	while (*original != '\0')
	{
		*destination = *original;
		destination++;
		original++;
	}
	*destination = '\0';
	return (ptr);
}

/**
 ** _compare - function that compares the content of 2 pointers
 ** @s1: compare with
 ** @s2: compare with
 ** Return: 0 if successful
 **/
int _compare(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == s2)
			return (0);
		return ((s1 == NULL) ? -1 : 1);
	}
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

/**
 ** concate - function that conctenates
 ** @dest: destination file to concate to
 ** @src: character to be added
 ** Return: pointer to destination file
 **/
char *concate(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ret);
}
