#include "main.h"

/**
 * char_p - handles c format
 *
 * @ap: arg list
 * @c: specifier
 *
 * Return: 1
 */
int char_p(char c, va_list ap)
{
	int cha = va_arg(ap, int);

	NOTUSED(c);

	_putchar(cha);

	return (1);
}

