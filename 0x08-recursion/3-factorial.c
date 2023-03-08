#include "main.h"

/**
 * factorial - returns the factorial of a given number
 * @n: the number to find the factorial of
 *
 * Return: the factorial of n, or -1 if n is negative
 */
int factorial(int n)
{
	/* Base case: if n is less than 0, return -1 to indicate an error */
	if (n < 0)
	{
		return (-1);
	}
	/* Base case: if n is 0 or 1, its factorial is 1 */
	else if (n == 0 || n == 1)
	{
		return (1);
	}
	/* Recursive case: return n times the factorial of n-1 */
	else
	{
		return (n * factorial(n - 1));
	}
}
