#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Prints the key/value pairs in a hash table.
 * @ht: The hash table to print.
 *
 * Description: This function prints the key/value pairs in the order they appear in the hash table,
 * following the format: `{array index}: key: value`
 * If the hash table is NULL, nothing is printed.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int first_pair = 1;
	hash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			if (!first_pair)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			first_pair = 0;
			node = node->next;
		}
	}
	printf("}\n");
}
