#include "main.h"

/**
 * main - Check description
 * Description: It prints the word _putchar followed by a new line
 * Return: Always 0
 */
int main(void)
{
	char word[8] = "_putchar";
	int i;

	for(i=1; i < 8; i++)
		_putchar(word[8]);
	_putchar ('\n');

	return (0);
}
