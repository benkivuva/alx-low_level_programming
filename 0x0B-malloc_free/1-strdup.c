#include <stdlib.h>

/**
 * _strdup - returns a pointer to a new string which is a duplicate of the
 *           string str
 * @str: the string to duplicate
 *
 * Return: a pointer to the newly allocated memory, which contains a duplicate
 *         of the string str, or NULL if str is NULL or if memory allocation
 *         fails
 */
char *_strdup(char *str)
{
	char *dup_str;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	/* determine length of str */
	while (str[len] != '\0')
		len++;

	/* allocate memory for duplicate string */
	dup_str = malloc((len + 1) * sizeof(char));

	if (dup_str == NULL)
		return (NULL);

	/* copy str to dup_str */
	for (i = 0; i <= len; i++)
		dup_str[i] = str[i];

	return (dup_str);
}
