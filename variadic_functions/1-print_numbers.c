#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_numbers - prints numbers separated by a string
 * @separator: string printed between numbers
 * @n: number of integers passed to the function
 *
 * Return: Nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list arguments;
	unsigned int i;

	va_start(arguments, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(arguments, int));

		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	va_end(arguments);
	printf("\n");
}
