/**
 * get_endianness - checks the endianness of the system.
 *
 * Return: 0 if big endian and  1 if little endian.
 */
int get_endianness(void)
{
	unsigned int e = 1;
	char *c = (char *)&e;

	if (*c)
		return (1); /* little endian */
	else
		return (0); /* big endian */
}
