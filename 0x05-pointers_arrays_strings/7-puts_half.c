#include "main.h"

/**
 * puts_half - prints the second half of a string, followed by a newline.
 * @str: input string.
 *
 * Return: nothing.
 */
void puts_half(char *str)
{
	int len = 0, n;

	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		n = len / 2;
	else
		n = (len + 1) / 2;

	for (; str[n] != '\0'; n++)
		_putchar(str[n]);

	_putchar('\n');
}
