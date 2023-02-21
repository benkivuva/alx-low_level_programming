#include <stdio.h>

/**
 * main - Entry point
 * Description: prints first 98 Fibonacci numbers
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;
	unsigned long int fib1 = 1, fib2 = 2, sum = 0;
	unsigned long int fib1_prev = 0, fib2_prev = 1;
	unsigned long int carry, fib1_new, fib2_new;

	printf("%lu, %lu", fib1, fib2);

	for (i = 2; i < 98; i++)
	{
	if (sum > 0)
		printf(", ");
	carry = 0;
	fib1_new = fib1_prev + fib1;
	fib2_new = fib2_prev + fib2;

	if (fib2_new > 1000000000000000000)
	{
		carry = fib2_new / 1000000000000000000;
		fib2_new %= 1000000000000000000;
	}
		sum = carry + fib1_new + fib2_new;
		printf("%lu", sum);
		fib1_prev = fib1;
		fib2_prev = fib2;
		fib1 = fib1_new;
		fib2 = fib2_new;
	}
	printf("\n")
	return (0)
}

