#include <stdio.h>

/**
 * main - prints the sum of even fibonacci numbers whose values dont exceed 4m
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long int sum = 0, current = 1, prev = 0, temp;

	while (current <= 4000000)
	{
		temp = current;
		current += prev;
		prev = temp;
		if (current % 2 == 0)
			sum += current;
	}
	printf("%lu\n", sum);
	return (0);
}
