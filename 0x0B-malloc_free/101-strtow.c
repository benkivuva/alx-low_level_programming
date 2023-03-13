#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: String to count.
 *
 * Return: Number of words in @str.
 */
int count_words(char *str)
{
	int count = 0, i, is_word = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && !is_word)
		{
			is_word = 1;
			count++;
		}
		else if (str[i] == ' ')
			is_word = 0;
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: String to split.
 *
 * Return: Pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	int i, j, k = 0, len = 0, words = 0;
	char **arr;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	words = count_words(str);
	if (words == 0)
		return (NULL);

	arr = malloc(sizeof(char *) * (words + 1));
	if (arr == NULL)
		return (NULL);

	for (i = 0; str[i] && k < words; i++)
	{
		if (str[i] != ' ')
		{
			len = 1;
			for (j = i + 1; str[j] && str[j] != ' '; j++)
				len++;
			arr[k] = malloc(sizeof(char) * (len + 1));
			if (arr[k] == NULL)
			{
				for (k--; k >= 0; k--)
					free(arr[k]);
				free(arr);
				return (NULL);
			}
			for (j = 0; j < len; j++, i++)
				arr[k][j] = str[i];
			arr[k++][j] = '\0';
		}
	}

	arr[k] = NULL;
	return (arr);
}

