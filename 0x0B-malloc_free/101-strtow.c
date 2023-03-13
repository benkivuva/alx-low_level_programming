#include <stdio.h>
#include <stdlib.h>

/**
 * count_words - count the number of words in a string
 * @str: the input string
 *
 * Return: the number of words in the string
 */
int count_words(char *str)
{
	int count = 0;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}

	return count;
}

/**
 * strtow - split a string into words
 * @str: the input string
 *
 * Return: a pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, n, count;

	if (str == NULL || str[0] == '\0')
		return NULL;

	count = count_words(str);

	words = malloc((count + 1) * sizeof(char *));

	if (words == NULL)
	return NULL;

	for (i = 0, k = 0; i < count; i++)
	{
		while (str[k] == ' ')
			k++;

		n = 0;
		while (str[k + n] != ' ' && str[k + n] != '\0')
			n++;

		words[i] = malloc((n + 1) * sizeof(char));

		if (words[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(words[j]);

		free(words);
		return NULL;
		}

		for (j = 0; j < n; j++)
			words[i][j] = str[k + j];

		words[i][j] = '\0';

		k += n;
	}

	words[i] = NULL;

	return words;
}
