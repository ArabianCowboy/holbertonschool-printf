#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Core API */
int _printf(const char *format, ...);

/* Low-level */
int _putchar(char c);

/* Handlers (Task 0) */
int print_c(va_list ap);
int print_s(va_list ap);
int print_pct(va_list ap);

#endif /* MAIN_H */

/* Task 1: integers */
int print_int(va_list ap);
int print_number(long n);
