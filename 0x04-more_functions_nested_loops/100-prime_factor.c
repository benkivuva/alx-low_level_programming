#include <stdio.h>

/**
 * main - finds and prints the largest prime factor of the number 612852475143
 *
 * Return: 0 on success
 */
int main(void)
{
	long n = 612852475143;
	long factor = 2;
	long largest_factor = 1;

	while (n > 1)
	{
	if (n % factor == 0)
	{
		largest_factor = factor;
		n /= factor;
		while (n % factor == 0)
			n /= factor;
	}
	factor++;
	}

	printf("%ld\n", largest_factor);

	return (0);
}
