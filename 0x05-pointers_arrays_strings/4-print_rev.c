#include "main.h"

/**
 * print_rev - prints a string in reverse order followed by a new line
 * @s: a pointer to the string
 *
 * Return: void
 */
void print_rev(char *s)
{
	int length = 0;

	/* Find the length of the string */
	while (*(s + length) != '\0')
	{
		length++;
	}

	/* Print the string in reverse order */
	for (int i = length - 1; i >= 0; i--)
	{
		_putchar(*(s + i));
	}

	_putchar('\n');
}
