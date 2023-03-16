#include <stdlib.h>

/**
 * malloc_checked - Allocate memory dynamically
 * @b: Number of bytes to allocate
 *
 * Return: Pointer to the allocated memory
 *         If malloc fails, the malloc_checked function
 *         terminates the program with a status value of 98
 */
void *malloc_checked(unsigned int b)
{
	void *p;

	p = malloc(b);
	if (p == NULL)
	{
		exit(98);
	}
	return (p);
}
