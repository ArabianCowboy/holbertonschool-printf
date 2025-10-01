#include "main.h"

/**
 * handle_spec - dispatch a single format specifier
 * @sp: specifier character
 * @ap: variadic argument list
 *
 * Return: number of chars printed, or -1 on error
 */
static int handle_spec(char sp, va_list ap)
{
	if (sp == 'c')
		return (print_c(ap));
	if (sp == 's')
		return (print_s(ap));
	if (sp == '%')
		return (print_pct(ap));

	/* Unknown for Task 0: print literally as "%X" */
	if (_putchar('%') == -1)
		return (-1);
	if (_putchar(sp) == -1)
		return (-1);
	return (2);
}

/**
 * print_literal_char - print a single non-'%' character
 * @ch: character to print
 *
 * Return: 1 on success, -1 on error
 */
static int print_literal_char(char ch)
{
	if (_putchar(ch) == -1)
		return (-1);
	return (1);
}

/**
 * process_format - core loop over the format string
 * @format: format string
 * @ap: variadic argument list
 *
 * Return: total chars printed, or -1 on error
 */
static int process_format(const char *format, va_list ap)
{
	int i = 0;
	int total = 0;
	int r = 0;

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			r = print_literal_char(format[i]);
			if (r == -1)
				return (-1);
			total += r;
			i++;
			continue;
		}

		i++;
		if (format[i] == '\0')
			return (-1);

		r = handle_spec(format[i], ap);
		if (r == -1)
			return (-1);
		total += r;
		i++;
	}
	return (total);
}

/**
 * _printf - produces output according to a format
 * @format: format string (Task 0: %c, %s, %%)
 *
 * Return: number of printed chars, or -1 on error
 */
int _printf(const char *format, ...)
{
	int total;
	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	total = process_format(format, ap);
	va_end(ap);

	return (total);
}
