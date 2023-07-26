#include "main.h"

/**
 * print_b - print in binary
 * @ap: arg list
 * @c: specifier
 * Return: char count
 */
int print_b(char c, va_list ap)
{
	unsigned int value, bin, i, sum;
	unsigned int a[32];
	int b_count;

	NOTUSED(c);

	value = va_arg(ap, unsigned int);
	bin = 2147483648; /* (2 ^ 31) */
	a[0] = value / bin;
	for (i = 1; i < 32; i++)
	{
		bin /= 2;
		a[i] = (value / bin) % 2;
	}
	for (i = 0, sum = 0, b_count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char b = '0' + a[i];
			write(1, &b, 1);
			b_count++;
		}
	}
	return (b_count);
}

