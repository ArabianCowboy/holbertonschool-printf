#include "main.h"

/**
 * print_c - prints a character
 * @ap: variadic args list
 * Return: number of chars printed or -1 on error
 */
int print_c(va_list ap)
{
	char c = (char)va_arg(ap, int);

	if (_putchar(c) == -1)
		return (-1);
	return (1);
}

/**
 * print_s - prints a string (handles NULL)
 * @ap: variadic args list
 * Return: number of chars printed or -1 on error
 */
int print_s(va_list ap)
{
	char *s = va_arg(ap, char *);
	int n = 0;

	if (!s)
		s = "(null)";
	while (*s)
	{
		if (_putchar(*s++) == -1)
			return (-1);
		n++;
	}
	return (n);
}

/**
 * print_pct - prints a literal percent sign
 * @ap: unused
 * Return: 1 on success, -1 on error
 */
int print_pct(va_list ap)
{
	(void)ap;
	if (_putchar('%') == -1)
		return (-1);
	return (1);
}
