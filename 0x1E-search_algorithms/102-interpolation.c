#include "search_algos.h"

/**
 * interpolation_search - Searches for a value using Interpolation search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: First index where the value is located, or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	int l = 0, r = size - 1, p;

	while (array && l < r && array[l] != array[r])
	{
		p = l + (
			(double)(r - l) / (array[r] - array[l]) * (value - array[l])
		);
		if (p >= (int) size)
		{
			printf("Value checked array[%d] is out of range\n", p);
			break;
		}
		printf("Value checked array[%d] = [%d]\n", p, array[p]);
		if (array[p] == value)
			return (p);
		if (array[p] < value)
			l = p + 1;
		else
			r = p - 1;
	}
	return (array && array[l] == value ? l : -1);
}
