#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size of the allocated space for ptr, in bytes
 * @new_size: new size, in bytes, of the new memory block
 *
 * Return: pointer to the newly allocated memory block
 *         NULL if new_size is 0 and ptr is not NULL, or if malloc fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	/* If new size is zero, free the old pointer and return NULL */
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* If the pointer is NULL, allocate new memory and return it */
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}

	/* Allocate new memory block */
	new_ptr = malloc(new_size);

	/* If allocation fails, return NULL */
	if (new_ptr == NULL)
	{
		return (NULL);
	}

	/* Copy old data to new memory block */
	if (new_size > old_size)
	{
		/* Only copy up to old_size bytes */
		memcpy(new_ptr, ptr, old_size);
	}
	else
	{
		memcpy(new_ptr, ptr, new_size);
	}

	/* Free old memory block */
	free(ptr);

	/* Return pointer to new memory block */
	return (new_ptr);
}
