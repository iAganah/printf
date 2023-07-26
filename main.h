#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

#define NOTUSED(arg) (void)(arg)

int _putchar(char c);
int _printf(const char *format, ...);
int handle_specifier(const char *format, int format_i, va_list ap);
int string_p(char c, va_list ap);
int char_p(char c, va_list ap);
int int_p(char c, va_list ap);

/**
 * struct spec_func - specificier structure
 * @spfr: first member
 * @fptr: second member
 *
 * datatype for specifier and their handlers
 */
typedef struct spec_func
{
	char spfr;
	int (*fptr)(char, va_list);
} spec_func;

#endif
