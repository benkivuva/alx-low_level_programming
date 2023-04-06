/**
 * flip_bits - This function returns the number of bits needed to flip to
 *             convert one number to another
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xresult = n ^ m;
	unsigned int count = 0;

	while (xresult)
	{
		if (xresult & 1)
			count++;

		xresult >>= 1;
	}

	return (count);
}
