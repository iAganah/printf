#include "main.h"
#include <string.h>

/**
 * _printf - replicating standard printf
 *
 * @format: required string;
 *
 * Return: the_count
 */
int _printf(const char *format, ...)
{
	int i = 0, the_count = 0, count = 0;

	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			 the_count++;
		}
		else
		{
			if (format[i + 1] == '\0')
			{
				va_end(ap);
				return (-1);
			}
			count = handle_specifier(format, i + 1, ap);

			if (count <= 0)
				count = 0;
			the_count += count;
			i++;
		}
	}
	va_end(ap);
	return (the_count);
}

