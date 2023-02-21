#include "main.h"

/**
 * _islower - Checks for lowercase character
 *
 * @c: An input character
 * Return: 1 if c is lowercase, 0 if  otherwise
 */
int _islower(int c)
{
	char i;
	int loower = 0;

	for (i = 'a'; i <= 'z'; i++)
	{
		if (i == c)
			loower = 1;
	}
	return (loower);
}
