#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieves the value asociated wit given key from hash table
 * @ht: The hash table.
 * @key: The key to search for.
 *
 * Return: The value associated with the key, or NULL if the key does not exist
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *ptr = NULL;

	if (!ht || !key || *key == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	/* Traverse the linked list at calculated index to find matching key */
	for (ptr = ht->array[index]; ptr; ptr = ptr->next)
	{
		if (!strcmp(ptr->key, key))
			return (ptr->value);
	}

	return (NULL);
}
