/**
 * _strcmp - Compares 2 strings
 * @s1: First string to compare
 * @s2: Second string to compare
 *
 * Return: 0 if the strings are equal, a negative number if s1 is less than s2,
 *         or a positive number if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	/* Compare each character in s1 and s2 */
	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			/* Strings are different, return the difference*/
			return (s1[i] - s2[i]);
		}
	}

	/* Strings are the same up to the end of one or both */
	if (s1[i] == '\0' && s2[i] == '\0')
	{
		return (0);
	}
	else if (s1[i] == '\0')
	{
		/* s1 is shorter than s2 */
		return (-s2[i]);
	}
	else
	{
		/* s1 is longer than s2 */
		return (s1[i]);
	}
}
