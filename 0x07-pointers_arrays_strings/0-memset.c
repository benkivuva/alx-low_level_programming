/**
 * _memset - fills memory with a constant byte
 *
 * @s: pointer to the memory area to be filled
 * @b: constant byte to fill the memory with
 * @n: number of bytes to fill
 *
 * Return: pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *ptr = s;

	while (n-- > 0)
	{
		*ptr++ = b;
	}

	return (s);
}
