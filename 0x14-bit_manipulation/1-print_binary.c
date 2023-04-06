#include "main.h"

/**
 * print_binary - Function that prints the binary representation of a number
 * @n: The number to print in binary form
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int print = 0;

	while (mask)
	{
		if (n & mask)
	{
		_putchar('1');
		print = 1;
	}
	else if (print)
	{
		_putchar('0');
	}

	mask >>= 1;
	}

	if (!print)
	{
	_putchar('0');
	}
}
