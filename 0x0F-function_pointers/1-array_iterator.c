#include <stddef.h>

/**
 * array_iterator - Executes a function on each element of an array
 *
 * @array: Pointer to the integer array
 * @size: Size of the array
 * @action: Pointer to a function that takes an integer as argument
 *
 * Return: void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array != NULL && action != NULL)
	{
		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
}
