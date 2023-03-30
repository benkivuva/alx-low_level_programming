#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - prints numbers, followed by a new line
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	/* Initialize argument list */
	va_start(args, n);

	/* Print each argument */
	for (i = 0; i < n; i++)
	{
	printf("%d", va_arg(args, int));

	/* Print separator if not last argument */
	if (i != n - 1 && separator != NULL)
		printf("%s", separator);

	}

	/* Clean up argument list */
	va_end(args);

	printf("\n");
}