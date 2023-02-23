#include "main.h"

/**
 * mul - multiplies two integers
 * @a: the first integer
 * @b: the second integer
 *
 * Return: the result of multiplying a and b
 */
int mul(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return (0);
	}

	int result = a * b;

	return (result);
}
