#include <stddef.h>

/**
 * int_index - searches for an integer in an array
 * @array: pointer to the array to search
 * @size: number of elements in the array
 * @cmp: pointer to the comparison function
 *
 * Return: index of first  element for which cmp does not return 0,
 *		or -1 if no match
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (-1);
}
