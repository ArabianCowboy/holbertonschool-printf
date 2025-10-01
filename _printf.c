#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing directives
 *
 * Handles Task 0 specifiers: %c, %s, %%
 * Return: number of printed chars, or -1 on error/invalid trailing '%'
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0, r;
	va_list ap;

	if (!format)
		return (-1);

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			if (_putchar(format[i++]) == -1)
			{ va_end(ap); return (-1); }
			count++;
			continue;
		}

		i++; /* skip '%' */
		if (!format[i]) /* lone trailing '%' is an error */
		{ va_end(ap); return (-1); }

		if (format[i] == 'c')
			r = print_c(ap);
		else if (format[i] == 's')
			r = print_s(ap);
		else if (format[i] == '%')
			r = print_pct(ap);
		else /* Unknown specifier in Task 0: print literally as "%X" */
		{
			if (_putchar('%') == -1 || _putchar(format[i]) == -1)
			{ va_end(ap); return (-1); }
			r = 2;
		}

		if (r == -1)
		{ va_end(ap); return (-1); }
		count += r;
		i++;
	}
	va_end(ap);
	return (count);
}
