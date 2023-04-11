i#include "main.h"
i
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

	*n = ((1 << index) | *n);

	return (1);
}
