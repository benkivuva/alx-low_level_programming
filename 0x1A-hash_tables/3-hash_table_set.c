#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - Adds an element to the hash table.
 * @ht: Pointer to the hash table.
 * @key: The key.
 * @value: The value.
 *
 * Return: 1 if succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *newNode = NULL, *ptr = NULL;

	if (!ht || !key || *key == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	ptr = ht->array[index];

	/* Check if key already exists */
	while (ptr)
	{
		if (!strcmp(ptr->key, key))
		{
			/* Update value if key already exists */
			if (ptr->value)
				free(ptr->value);
			ptr->value = strdup(value);
			return (1);
		}
		ptr = ptr->next;
	}

	/* Add new key entry */
	newNode = malloc(sizeof(*newNode));
	if (!newNode)
		return (0);

	newNode->key = strdup(key);
	newNode->value = strdup(value);

	if (!newNode->key || !newNode->value)
	{
		free(newNode->key);
		free(newNode->value);
		free(newNode);
		return (0);
	}

	newNode->next = ht->array[index] ? ht->array[index] : NULL;
	ht->array[index] = newNode;

	return (1);
}
