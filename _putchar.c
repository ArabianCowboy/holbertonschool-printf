#include "main.h"

/**
 * _putchar - writes a single character to stdout
 * @c: character to print
 *
 * Return: 1 on success, or -1 on error.
 */
int _putchar(char c)
{
	return (int)write(1, &c, 1);
}
