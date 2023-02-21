#include "main.h"

/**
 * print_alphabet - prints alphabet in lowercase
 *
 * Return: Always 0
 */
void print_alphabet(void)
{
	char low;

	for (low = 'a'; low <= 'z'; low++)
	_putchar(low);
	_putchar('\n');
}
