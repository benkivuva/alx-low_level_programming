#include "search_algos.h"

/**
 * jump_search - Searches for a value in sorted integer array using Jump search
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: (int) First index where the value is located, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	int jump = (int) sqrt(size);
	int l = 0, r = 0;

	while (array)
	{
		if (r >= (int) size || array[r] >= value)
		{
			printf("Value found between indexes [%d] and [%d]\n", l, r);
			break;
		}
		printf("Value checked array[%d] = [%d]\n", r, array[r]);
		l = r;
		r += jump;
	}
	for (; l <= r && l < (int) size; l++)
	{
		printf("Value checked array[%d] = [%d]\n", l, array[l]);
		if (array[l] == value)
			return (l);
	}
	return (-1);
}
