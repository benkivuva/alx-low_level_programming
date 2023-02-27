#include "main.h"

/**
 * rev_string - reverses a string
 * @s: a pointer to the string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int length = 0;
	char *begin, *end, temp;

	/* Find the length of the string */
	while (*(s + length) != '\0')
	{
		length++;
	}

	/* Set pointers to the beginning and end of the string */
	begin = s;
	end = s + length - 1;

	/* Swap characters from the beginning and end of the string */
	while (end > begin)
	{
		temp = *begin;
		*begin = *end;
		*end = temp;

		begin++;
		end--;
	}
}
