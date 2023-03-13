#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a new string which is a duplicate of the
 *           string str
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if insufficient memory
 *         was available or str is NULL
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int len, i;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)

	dup = malloc(sizeof(char) * (len + 1));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup[i] = str[i];

	return (dup);
}

