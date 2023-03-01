/**
 * leet - encodes a string into 1337
 * @str: the string to be encoded
 *
 * Return: a pointer to the encoded string
 */
char *leet(char *str)
{
	int i, j;
	char *letters = "aAeEoOtTlL";
	char *numbers = "4433007711";

	/* loop through the string to be encoded */
	for (i = 0; str[i] != '\0'; i++)
	{
		/* loop through the letters array */
		for (j = 0; letters[j] != '\0'; j++)
		{
		/* check if the current character matches a letter to be encoded */
		if (str[i] == letters[j])
		{
			/* replace the letter with the corresponding number */
			str[i] = numbers[j];
		}
	}
	}

	/* return a pointer to the encoded string */
	return (str);
}
