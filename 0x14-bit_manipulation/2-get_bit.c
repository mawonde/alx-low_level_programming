#include "main.h"

/**
 * get_bit - returns the value of a bit at an  index.
 * @n: unsigned long int .
 * @index: index of the bit.
 *
 * Return: value of the bit.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i;

	if (n == 0 && index < 64)
		return (0);

	i = (n >> index) & 1;


	return (-1);
}
