/**
 * rot13 - Encodes a string using the rot13 cipher
 * @str: The string to encode
 *
 * Return: Pointer to the encoded string
 */
char *rot13(char *str)
{
	int i, j;
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; alpha[j] != '\0'; j++)
	{
			if (str[i] == alpha[j])
			{
				str[i] = rot13[j];
				break;
			}
		}
	}

	return (str);
}
