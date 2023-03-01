#include <main.h>

/**
 * _strncpy - Copies a string up to n bytes
 * @dest: Pointer to destination string
 * @src: Pointer to source string
 * @n: Maximum number of bytes to copy from src
 *
 * Return: Pointer to copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	/* Copy up to n characters from src to dest */
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	/* Pad dest with null bytes if necessary */
	for ( ; i < n; i++)
	{
		dest[i] = '\0';
	}

	/* Return a pointer to the copied string */
	return (dest);
}
