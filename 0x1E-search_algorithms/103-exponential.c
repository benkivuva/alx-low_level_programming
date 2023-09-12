#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted integer array using
 * the Exponential search algorithm.
 *
 * @array: Pointer to the first element of the sorted array.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index of the first occurrence of 'value' in the array,
 * or -1 if 'value' is not present or 'array' is NULL.
 */
int exponential_search(int *array, size_t size, int value)
{
	int l = 0, r = 1;

	if (!array)
		return (-1);

	while (r < (int) size - 1)
	{
		if (array[r] >= value)
			break;

		printf("Value checked array[%d] = [%d]\n", r, array[r]);
		l = r;
		r = r * 2 <= (int) size - 1 ? r * 2 : (int) size - 1;
	}

	printf("Value found between indexes [%d] and [%d]\n", l, r);
	return (binary_search_exp(array, l, r, value));
}

/**
 * binary_search_exp - Searches for a value in a sorted integer array using
 * the Binary search algorithm.
 *
 * @array: Pointer to the first element of the sorted array.
 * @l: The left bound of the search range.
 * @r: The right bound of the search range.
 * @value: The value to search for.
 *
 * Return: The index of the first occurrence of 'value' in the array,
 * or -1 if 'value' is not present or 'array' is NULL.
 */
int binary_search_exp(int *array, int l, int r, int value)
{
	int mid;

	while (array && l <= r)
	{
		print_array_bs_exp(array, l, r);
		mid = (l + r) / 2;

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			l = mid + 1;
		else
			r = mid - 1;
	}

	return (-1);
}

/**
 * print_array_bs_exp - Prints the elements within the specified range of array
 *
 * @array: The array to print.
 * @l: The left bound of the range.
 * @r: The right bound of the range.
 */
void print_array_bs_exp(int *array, int l, int r)
{
	printf("Searching in array: ");
	while (l < r)
		printf("%d, ", *(array + l++));
	printf("%d\n", *(array + r));
}
