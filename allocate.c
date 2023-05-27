#include "main.h"

/**
 ** _allocate - Function for allocating memory
 ** @buffer: buffer
 ** @size_prev: former size of buffer
 ** @size_new: new size of buffer
 ** Return: buffer or NULL
 **/

void *_allocate(void *buffer, unsigned int size_prev, unsigned int size_new)
{
	char *buffer_copy;
	char *fill;
	void *temp;
	unsigned int i;

	if (buffer == NULL)
	{
		temp = malloc(size_new);
		if (temp == NULL)
			return (NULL);
		return (temp);
	}
	if (size_new == size_prev)
		return (buffer);
	if (size_new == 0 && buffer != NULL)
	{
		free(buffer);
		return (NULL);
	}
	buffer_copy = buffer;
	temp = malloc(sizeof(buffer_copy) * size_new);
	if (temp == NULL)
	{
		free(buffer);
		return (NULL);
	}
	fill = temp;
	for (i = 0; i < size_prev && i < size_new; i++)
		fill[i] = *buffer_copy++;
	free(buffer);
	return (temp);
}
