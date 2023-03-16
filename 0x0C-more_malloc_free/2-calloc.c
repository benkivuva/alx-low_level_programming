#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array
 * @nmemb: Number of elements to allocate memory for
 * @size: Size of each element in bytes
 *
 * Return: Pointer to the allocated memory, or NULL if allocation fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	if (nmemb == 0 || size == 0)
		return (NULL);

	void *ptr = malloc(nmemb * size);

	if (ptr != NULL)
	{
		char *p = ptr;
		for (unsigned int i = 0; i < nmemb * size; i++)
			*(p + i) = 0;
	}

	return (ptr);
}
