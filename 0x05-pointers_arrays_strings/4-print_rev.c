#include <unistd.h>

/**
 * print_rev - prints a string in reverse order followed by a new line
 * @s: a pointer to the string
 *
 * Return: void
 */
void print_rev(char *s)
{
	int length = 0;

	while (*(s + length) != '\0')
	{
		length++;
	}

	for (int i = length - 1; i >= 0; i--)
	{
		write(STDOUT_FILENO, s + i, 1);
	}

	write(STDOUT_FILENO, "\n", 1);
}
