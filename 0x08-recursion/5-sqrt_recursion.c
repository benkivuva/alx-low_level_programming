#include "main.h"

/**
 * _sqrt_helper - helper function for _sqrt_recursion
 * @n: the number to find the square root of
 * @guess: a guess for the square root of n
 * Return: the square root of n, or -1 if n does not have a natural square root
 */
int _sqrt_helper(int n, int guess)
{
	if (guess * guess > n)
		return (-1);
	else if (guess * guess == n)
		return (guess);
	else
		return (_sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find the square root of
 * Return: the square root of n, or -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
	return (_sqrt_helper(n, 0));
}
