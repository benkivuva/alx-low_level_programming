#include <stdlib.h>
#include <string.h>

/**
 * _realloc - Reallocates a block of memory
 * @ptr: Pointer to the block of memory previously allocated
 * @old_size: Size of the old block of memory
 * @new_size: Size of the new block of memory
 *
 * Return: Pointer to the new block of memory, or NULL if allocation fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr = NULL;

	if (new_size == 0)
	{
	free(ptr);
	return (NULL);
	}

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}

	if (new_size <= old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	memcpy(new_ptr, ptr, old_size);
	free(ptr);

	return (new_ptr);
}
