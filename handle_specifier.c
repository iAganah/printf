#include "main.h"
#include <string.h>
/**
 * handle_specifier - handle printf specifiers
 * @format: The character to print
 *
 * @format_i: index;
 * @ap: va_list
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int handle_specifier(const char *format, int format_i, va_list ap)
{
	int i, char_count = 0;
	char invalid_specifier = format[format_i];

	spec_func specifier_type[] = {
		{'c', char_p}, {'s', string_p}
	};

	if (ap == NULL)
		char_count = (write(1, format, strlen(format)));

	for (i = 0; specifier_type[i].spfr != '\0'; i++)
	{
		if (format[format_i] == specifier_type[i].spfr)
		{
			char_count = (specifier_type[i].fptr(format[format_i], ap));
			break;
		}
	}
	if (specifier_type[i].spfr == '\0')
	{
		_putchar('%');
		_putchar(invalid_specifier);
		char_count += 2;
	}
	return (char_count);
}

