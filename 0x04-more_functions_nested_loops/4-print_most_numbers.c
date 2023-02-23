#include "main.h"

/**
 * print_most_numbers - prints numbers between 0 to 9
 * (neither 2 nor 4).
 * Return: void.
 */
void print_most_numbers(void)
{
	int c;

	for (c = 48; c <= 58; c++)
	{
		if (c != 50 && c != 52)
			_putchar(c);
	}
	_putchar('\n');
}
