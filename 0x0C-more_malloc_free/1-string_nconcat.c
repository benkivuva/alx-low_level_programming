#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - Concatenates two strings using at most n bytes from s2
 * @s1: The first string
 * @s2: The second string
 * @n: The maximum number of bytes to use from s2
 *
 * Return: Pointer to the concatenated string, or NULL if allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = strlen(s1);
	len2 = strlen(s2);

	if (n < len2)
		len2 = n;

	concat = malloc(len1 + len2 + 1);

	if (concat != NULL)
	{
		memcpy(concat, s1, len1);
		memcpy(concat + len1, s2, len2);
		concat[len1 + len2] = '\0';
	}

	return (concat);
}
