#include "hash_tables.h"

/**
 * hash_djb2 - Implements the djb2 hashing algorithm.
 * @str: The hash key.
 *
 * Return: The hash table index.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	while (str && (c = *str++))
		hash = ((hash << 5) + hash) + c;

	return (hash);
}
