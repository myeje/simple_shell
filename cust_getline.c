#include "main.h"

void *_expan_mem(void *ptr, unsigned int pre_size, unsigned int add_size);
void give_linptr(char **lineptr, size_t *n, char *buff, size_t q);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/**
 * _expan_mem - Expand/Reallocate memory using malloc and free
 * @ptr: Pointer to previous memory
 * @pre_size: Size of bytes allocated in memory
 * @add_size: Size of bytes for new memory
 *
 * Return: if add_size == Pre_size - ptr
 * If add_size == 0 and ptr is not NULL - NULL,
 * else pointer reallocates memory
 */
void *_expan_mem(void *ptr, unsigned int pre_size, unsigned int add_size)
{
	void *stor;
	char *ptr_copy, *fila;
	unsigned int ind;

	if (add_size == pre_size)
		return (ptr);

	if (ptr == NULL)
	{
		stor = malloc(add_size);
		if (stor == NULL)
			return (NULL);

		return (stor);
	}

	if (add_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	fila = stor;

	for (ind = 0; ind < pre_size && ind < add_size; ind++)
		fila[ind] = *ptr_copy++;

	free(ptr);
	return (stor);
}

/**
 * give_linptr - lineptr variable re-assigned for getline
 * @lineptr: Buffer to store input
 * @n: size of lineptr
 * @buff: String for lineptr
 * @q: size of buffer
 */
void give_linptr(char **lineptr, size_t *n, char *buff, size_t q)
{
	if (*lineptr == NULL)
	{
		if (q > 120)
		{
			*n = q;
		}
		else
		{
			*n = 120;
			*lineptr = buff;
		}
	}
	else if (*n < q)
	{
		if (q > 120)
		{
			*n = q;
		}
		else
		{
			*n = 120;
			*lineptr = buff;
		}
	}
		else
		{
			strcpy(*lineptr, buff);
			free(buff);
		}
}

/**
 * _getline - Reads input from stream
 * @lineptr: Buffer to store input
 * @n: Size of lineptr
 * @stream: read from stream
 *
 * Return: Number of bytes read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t insert;
	ssize_t rect;
	char m = 'y', *buff;
	int q;

	if (insert == 0)
		fflush(stream);
	else
		return (-1);
	insert = 0;

	buff = malloc(sizeof(char) * 120);
	if (!buff)
		return (-1);

	while (m != '\n')
	{
		q = read(STDIN_FILENO, &m, 1);
		if (q == -1 || (q == 0 && insert ==0))
		{
			free(buff);
			return (-1);
		}
		if (q == 0 && insert != 0)
		{
			insert++;
			break;
		}

		if (insert >= 120)
			buff = _expan_mem(buff, insert, insert + 1);

		buff[insert] = m;
		insert++;
	}
	buff[insert] = '\0';

	give_linptr(lineptr, n, buff, insert);

	rect = insert;
	if (q != 0)
		insert = 0;
	return (rect);
}
