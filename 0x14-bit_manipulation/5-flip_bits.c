#include "main.h"

/**
 * flip_bits - returns the number of bits to change
 * @n: 1st number.
 * @m: 2nd number.
 *
 * Return: number of bits for changing.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int num_of_bits;

	for (num_of_bits = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			num_of_bits++;
	}

	return (num_of_bits);
}
