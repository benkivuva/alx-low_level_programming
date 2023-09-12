#include "search_algos.h"

void print_search_range(int *array, int left, int right);

/**
 * binary_search - Search for a value in sorted integer array using binary s
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: Index where the value is located or -1 if not found or invalid input
 */
int binary_search(int *array, size_t size, int value)
{
	int l = 0, r = size - 1, mid;

	while (array && l <= r)
	{
		print_search_range(array, l, r);
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
 * print_search_range - Prints the elements in the specified range of an array
 * @array: Array to print.
 * @left: Left bound (start index).
 * @right: Right bound (end index).
 */
void print_search_range(int *array, int left, int right)
{
	printf("Searching in array: ");
	while (left < right)
	{
		printf("%d, ", array[left]);
		left++;
	}
	printf("%d\n", array[right]);
}
