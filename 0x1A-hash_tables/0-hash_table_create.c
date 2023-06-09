#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - Creates a hash table with a given size.
 * @size: The size of the hash table.
 *
 * Return: Pointer to the created hash table, NULL on error.
 *         If size is 0, an empty table of size 0 is created.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht = NULL;

	/* Check if size is not 0 */
	if (size != 0)
		ht = malloc(sizeof(*ht));

	/* Proceed if memory allocation is successful */
	if (ht != NULL)
	{
		ht->size = size;
		ht->array = malloc(sizeof(*ht->array) * size);

		/* Check if memory allocation for the array is successful */
		if (ht->array != NULL)
		{
			unsigned long int i;

			for (i = 0; i < size; i++)
				ht->array[i] = NULL;
		}
		else
		{
			free(ht);
			return (NULL);
		}
	}

	return (ht);
}
