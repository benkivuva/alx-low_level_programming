/**
 * string_toupper - changes all lowercase letters of a string to uppercase
 * @str: pointer to a string
 * Return: pointer to the resulting string
 */
char *string_toupper(char *str)
{
	char *ptr = str;

	while (*ptr != '\0')
	{
		/* If the current character is lowercase, subtract 32 to make it uppercase */
		if (*ptr >= 'a' && *ptr <= 'z')
		{
			*ptr -= 32;
		}

		/* Move to the next character in the string */
		ptr++;
	}

	return (str);
}
