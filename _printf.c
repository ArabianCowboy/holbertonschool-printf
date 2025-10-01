#include "main.h"

/**
 * handle_spec - dispatches a single format specifier
 * @sp: specifier character
 * @ap: variadic argument list
 *
 * Return: number of chars printed, or -1 on error
 */
static int handle_spec(char sp, va_list ap)
{
	if (sp == 'c')
		return (print_c(ap));
	else if (sp == 's')
		return (print_s(ap));
	else if (sp == '%')
		return (print_pct(ap));

	/* Unknown specifier in Task 0: print literally as "%X" */
	if (_putchar('%') == -1)
		return (-1);
	if (_putchar(sp) == -1)
		return (-1);
	return (2);
}

/**
 * _printf - produces output according to a format
 * @format: format string containing directives
 *
 * Handles Task 0 specifiers: %c, %s, %%
 * Return: number of printed chars, or -1 on error/invalid trailing '%'
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	int r = 0;
	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			if (_putchar(format[i]) == -1)
			{
				va_end(ap);
				return (-1);
			}
			count++;
			i++;
			continue;
		}

		i++; /* skip '%' */
		if (format[i] == '\0') /* lone trailing '%' */
		{
			va_end(ap);
			return (-1);
		}

		r = handle_spec(format[i], ap);
		if (r == -1)
		{
			va_end(ap);
			return (-1);
		}
		count += r;
		i++;
	}
	va_end(ap);
	return (count);
}
