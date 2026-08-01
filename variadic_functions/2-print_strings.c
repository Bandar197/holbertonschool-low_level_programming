#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_strings - prints strings separated by a string
 * @separator: string printed between strings
 * @n: number of strings passed to the function
 *
 * Return: Nothing
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list arguments;
	unsigned int i;
	char *string;

	va_start(arguments, n);

	for (i = 0; i < n; i++)
	{
		string = va_arg(arguments, char *);

		if (string == NULL)
			printf("(nil)");
		else
			printf("%s", string);

		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	va_end(arguments);
	printf("\n");
}
