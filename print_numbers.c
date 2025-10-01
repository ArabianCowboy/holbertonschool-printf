#include "main.h"

/**
 * print_number - prints a signed long number in base 10
 * @n: number to print
 *
 * Return: number of characters printed, or -1 on error
 */
int print_number(long n)
{
	int count = 0;

	if (n < 0)
	{
		if (_putchar('-') == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n / 10)
	{
		int r = print_number(n / 10);

		if (r == -1)
			return (-1);
		count += r;
	}
	if (_putchar((char)('0' + (n % 10))) == -1)
		return (-1);
	return (count + 1);
}

/**
 * print_int - handles %d and %i specifiers
 * @ap: variadic args list
 *
 * Return: number of characters printed, or -1 on error
 */
int print_int(va_list ap)
{
	long n = (long)va_arg(ap, int);

	return (print_number(n));
}
