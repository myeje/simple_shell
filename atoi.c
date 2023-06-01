#include "main.h"

/**
 * _atoi - converts string to int
 * @a: string to convert
 * Return: converted integer
 */
int _atoi(char *a)
{
	unsigned int sum = 0;
	char flag = 0;
	int num = 1;

	if (a == NULL)
		return (0);
	while (*a)
	{
		if (*a == '-')
			num *= -1;
		if (*a >= '0' && *a <= '9')
		{
			flag = 1;
			sum = sum * 10 + (*a - '0');
		}
		else if (*a < '0' || *a > '9')
		{
			if (flag == 1)
				break;
		}
		a++;
	}
	if (num < 0)
		sum = (-1 * (sum));
	return (sum);
}
