#include "main.h"

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: The times table to print.
 */
void print_times_table(int n)
{
	int i, j, k;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{
		_putchar('0');

		for (j = 1; j <= n; j++)
		{
			k = i * j;

			_putchar(',');
			_putchar(' ');

			if (k < 100)
				_putchar(' ');

			if (k < 10)
				_putchar(' ');

			if (k >= 100)
			{
				_putchar(k / 100 + '0');
				_putchar((k / 10) % 10 + '0');
			}
			else if (k >= 10)
			{
				_putchar(k / 10 + '0');
			}

			_putchar(k % 10 + '0');
		}

		_putchar('\n');
	}
}
