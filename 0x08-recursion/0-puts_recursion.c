#include "main.h"

/**
 * _puts_recursion - prints a string followed by a new line
 * @s: the string to print
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n'); /* Print a new line */
		return;        /* Return to the calling function*/
	}
	_putchar(*s);     /* Print the current character */
	_puts_recursion(s + 1);  /* Call the function recursively */
}
