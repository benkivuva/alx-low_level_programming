/**
 * get_bit - Returns the value of a bit at a given index
 * @n: A number containing the bit
 * @index: The index of the bit to get starting from 0
 *
 * Return: The value of the bit at index index
 *         or return -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	return ((n >> index) & 1);
}