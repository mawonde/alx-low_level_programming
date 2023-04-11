#include "main.h"

/**
 * binary_to_uint - transforms  binary number to an unsigned int.
 * @b: binary number.
 *
 * Return: unsigned int.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i = 0;
	int length, bi;

	if (!b)
		return (0);


	for (length = 0; b[length] != '\0'; length++);
		

	for (length--, bi = 1; len >= 0; length--, bi *= 2)
	{
		if (b[length] != '0' && b[length] != '1')
		{
			return (0);
		}

		if (b[length] & 1)
		{
			i += bi;
		}
	}

	return (i);
}
