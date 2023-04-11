#include "main.h"

/**
 * clear_bit - sets the value of a supplied bit to 0.
 * @n: pointer of the number.
 * @index: index of the bit for clearance.
 *
 * Return: 1 if success, -1 if failed.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{

	if (index > 63)
		return (-1);

	*n = (~(1 << index) & *n );
	return (1);
}
