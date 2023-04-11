i#include "main.h"

/**
 * set_bit - sets the bit value  to 1 at a given index.
 * @n: pointer of the unsigned long int.
 * @index: index of the bit.
 *
 * Return: 1 if success, otherwise -1 if failed.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int m;

	if (index > 63)
		return (-1);

	o = 1 << index;
	*n = ( *n | o);

	return (1);
}
