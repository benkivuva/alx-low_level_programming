#include <stdarg.h>

/**
 * sum_them_all - returns the sum of all its parameters
 * @n: number of parameters
 * Return: sum of all parameters
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	int sum = 0;
	unsigned int i;

	/* Initialize argument list */
	va_start(args, n);

	/* Add up all arguments */
	for (i = 0; i < n; i++)
		sum += va_arg(args, int);

	/* Clean up argument list */
	va_end(args);

	return (sum);
}
