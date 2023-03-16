#include <stdlib.h>

/**
 * array_range - Creates an array of integers
 * @min: Minimum value in the array
 * @max: Maximum value in the array
 *
 * Return: Pointer to the newly created array,
 *         or NULL if allocation fails or min > max
 */
int *array_range(int min, int max)
{
	int *arr, i, j;

	if (min > max)
	{
		return (NULL);
	}

	arr = malloc(sizeof(int) * (max - min + 1));

	if (arr == NULL)
	{
		return (NULL);
	}

	for (i = min, j = 0; i <= max; i++, j++)
	{
		arr[j] = i;
	}
	return (arr);
}
