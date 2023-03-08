#include "main.h"

/**
 * _pow_recursion - returns the value of x raised to the power of y
 * @x: the base number
 * @y: the exponent
 *
 * Return: x raised to the power of y, or -1 if y is negative
 */
int _pow_recursion(int x, int y)
{
	/* Base case: if y is less than 0, return -1 to indicate an error */
	if (y < 0)
	{
		return (-1);
	}
	/* Base case: if y is 0, x^0 is 1 */
	else if (y == 0)
	{
		return (1);
	}
	/* Recursive case: return x times x^(y-1) */
	else
	{
		return (x * _pow_recursion(x, y - 1));
	}
}
