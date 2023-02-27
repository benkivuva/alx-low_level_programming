#include <unistd.h>

/**
 * _puts - prints a string followed by a new line to stdout
 * @str: a pointer to the string
 *
 * Return: void
 */
void _puts(char *str)
{
	int length = 0;

	while (*(str + length) != '\0')
	{
		length++;
	}

	write(STDOUT_FILENO, str, length);
	write(STDOUT_FILENO, "\n", 1);
}
