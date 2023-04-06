/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: A pointer to the number to be modified
 * @index: The index of the bit to be set
 *
 * Return: 1 on success and  -1 if it fails
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int m;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	m = 1 << index;
	m = ~m;
	*n &= m;

	return (1);
}
