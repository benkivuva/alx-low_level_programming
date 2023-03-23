#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints a variable number of strings separated by a separator
 *
 * @separator: a string used to separate the strings being printed
 *             if separator is NULL, no separator will be printed
 * @n: the number of string arguments to print
 * @...: a variable number of string arguments to print
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
	str = va_arg(args, char *);
	if (str == NULL)
		printf("(nil)");
	else
		printf("%s", str);

	if (separator != NULL && i != n - 1)
		printf("%s", separator);

	va_end(args);
	}

	printf("\n");
}
