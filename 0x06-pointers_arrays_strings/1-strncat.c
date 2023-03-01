#include <main.h>

/**
 * _strncat - Concatenates two strings up to n bytes
 * @dest: Pointer to destination string
 * @src: Pointer to source string
 * @n: Maximum number of bytes to concatenate from src
 *
 * Return: Pointer to concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	/* Find the end of the destination string */
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}

	/* Append the source string to the destination string */
	j = 0;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Add a null terminator to the end of the concatenated string */
	dest[i] = '\0';

	/* Return a pointer to the concatenated string */
	return (dest);
}
