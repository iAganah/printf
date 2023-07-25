#include "main.h"
#include <string.h>

/**
 * string_p - prints a given string
 *
 * @ap: arguments from _printf
 * @c: specifier
 * Return: printed char count
 */
int string_p(char c, va_list ap)
{
	int len = 0;
	char *string = va_arg(ap, char *);

	NOTUSED(c);

	if (string == NULL)
		string = "(null)";

	while (string[len] != '\0')
		len++;
	return (write(1, string, len));
}

