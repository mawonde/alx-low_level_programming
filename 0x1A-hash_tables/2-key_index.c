#include "hash_tables.h"

/**
 * key_index - A function that generates an index
 * according to  hash
 *
 * @key: key passed
 * @size: size of tables
 * Return: key index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (key == NULL || size == 0)
		return (0);
	return (hash_djb2(key) % size);
}
