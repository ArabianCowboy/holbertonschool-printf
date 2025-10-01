#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format (Task 0: %c, %s, %%)
 * @format: The format string
 *
 * Return: Number of characters printed (excluding the null byte),
 *         or -1 on error.
 */
int _printf(const char *format, ...);

/**
 * _putchar - Writes a single character to stdout
 * @c: The character to print
 *
 * Return: 1 on success, or -1 on error.
 */
int _putchar(char c);

#endif /* MAIN_H */
