#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array using linear search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value if found, -1 if not found or array is NULL
 */
int linear_search(int *array, size_t size, int value)
{
	int index = 0;

	while (array && size--)
	{
		printf("Value checked array[%d] = [%d]\n", index, *array);
		if (*array++ == value)
		return (index);
		index++;
	}
	return (-1);
}
