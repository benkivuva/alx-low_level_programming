/**
 * set_bit - sets the value of a bit at a given index
 * @n: A pointer to the number.
 * @index: Index of the bit to be  set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n |= (1ul << index);
	return (1);
}
