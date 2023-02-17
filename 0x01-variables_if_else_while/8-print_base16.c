#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num = 0;
	char hex;

	while (num < 16)
	{
	if (num < 10)
	{
		hex = num + '0';
	}
	else
	{
		hex = num - 10 + 'a';
	}
	putchar(hex);
	num++;
	}
	putchar('\n');
	return (0);
}
