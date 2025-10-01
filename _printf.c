#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing directives
 *
 * Description:
 *   Handles the following conversion specifiers for Task 0:
 *     - %c : character
 *     - %s : string (prints "(null)" if the string is NULL)
 *     - %% : prints a literal percent sign
 *
 * Return: number of characters printed (excluding the null byte),
 *         or -1 if an error occurs or if format is NULL
 *         or if a trailing '%' is present with no specifier.
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list ap;

	if (!format)
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

		/* Encountered '%' */
		i++;

		/* Lone trailing '%' => error per project checker */
		if (format[i] == '\0')
		{
			va_end(ap);
			return (-1);
		}

		if (format[i] == 'c')
		{
			char c = (char)va_arg(ap, int);

			if (_putchar(c) == -1)
			{
				va_end(ap);
				return (-1);
			}
			count++;
		}
		else if (format[i] == 's')
		{
			char *s = va_arg(ap, char *);
			int j = 0;

			if (!s)
				s = "(null)";
			while (s[j] != '\0')
			{
				if (_putchar(s[j]) == -1)
				{
					va_end(ap);
					return (-1);
				}
				count++;
				j++;
			}
		}
		else if (format[i] == '%')
		{
			if (_putchar('%') == -1)
			{
				va_end(ap);
				return (-1);
			}
			count++;
		}
		else
		{
			/* Unknown specifier for Task 0: print literally as "%X" */
			if (_putchar('%') == -1 || _putchar(format[i]) == -1)
			{
				va_end(ap);
				return (-1);
			}
			count += 2;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
