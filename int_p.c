#include "main.h"

/**
* int_p - Print int
*
* @ap: arg list
* @c: specifier
*
* Return: value after specifier action
*/

int int_p(char c, va_list ap)
{
	int a[10];
	int j, pof_10, value, sum, i_count;

	NOTUSED(c);
	value = va_arg(ap, int);
	i_count = 0;
	pof_10 = 1000000000;
	a[0] = value / pof_10;

	for (j = 1; j < 10; j++)
	{
		pof_10 /= 10;
		a[j] = (value / pof_10) % 10;
	}
	if (value < 0)
	{
		_putchar('-');
		i_count++;

		for (j = 0; j < 10; j++)
			a[j] *= -1;
	}
	for (j = 0, sum = 0; j < 10; j++)
	{
		sum += a[j];

		if (sum != 0 || j == 9)
		{
			_putchar('0' + a[j]);
			i_count++;
		}
	}
	return (i_count);
}

