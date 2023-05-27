#include "main.h"


/**
 ** _getline - function that reads input
 ** @ptr: pointer to buffere to where input is stored
 ** @n: The size of buffer
 ** @stream: where to read input from
 ** Return: size of bytes to read
 **/
ssize_t _getline(char **ptr, size_t *n, FILE *stream)
{
	ssize_t ret;
	char ch = 'x'; 
	char *buffer;
	static ssize_t count;
	int read_status = 1;

	if (count == 0)
		fflush(stream);
	else
		return (-1);
	count = 0;
	buffer = malloc(sizeof(char) * 120 + 1);
	if (!buffer)
		return (-1);
	for (; ch != '\n'; count++)
	{
		read_status = read(STDIN_FILENO, &ch, 1);
		if (read_status == -1 || (read_status == 0 && count == 0))
		{
			free(buffer);
			return (-1);
		}
		if (read_status == 0 && count != 0)
		{
			count++;
			break;
		}
		if (count >= 120)
			buffer = _allocate(buffer, count, count + 1);
		buffer[count] = ch;
	}
	buffer[count] = '\0';
	buffer_assign(ptr, buffer, n, count);
	ret = count;
	if (read_status != 0)
		count = 0;
	return (ret);
}
