#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_char - prints a character
 * @arguments: list of variadic arguments
 *
 * Return: Nothing
 */
void print_char(va_list arguments)
{
	printf("%c", va_arg(arguments, int));
}

/**
 * print_integer - prints an integer
 * @arguments: list of variadic arguments
 *
 * Return: Nothing
 */
void print_integer(va_list arguments)
{
	printf("%d", va_arg(arguments, int));
}

/**
 * print_float - prints a floating-point number
 * @arguments: list of variadic arguments
 *
 * Return: Nothing
 */
void print_float(va_list arguments)
{
	printf("%f", va_arg(arguments, double));
}

/**
 * print_string - prints a string
 * @arguments: list of variadic arguments
 *
 * Return: Nothing
 */
void print_string(va_list arguments)
{
	char *string;
	char *values[2];

	string = va_arg(arguments, char *);
	values[0] = "(nil)";
	values[1] = string;

	printf("%s", values[string != NULL]);
}

/**
 * print_all - prints arguments according to a format string
 * @format: list of argument types
 *
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	unsigned int i = 0;
	unsigned int j;
	char *separator = "";
	va_list arguments;
	printer_t printers[] = {
		{'c', print_char},
		{'i', print_integer},
		{'f', print_float},
		{'s', print_string}
	};

	va_start(arguments, format);

	while (format != NULL && format[i] != '\0')
	{
		j = 0;

		while (j < 4)
		{
			if (format[i] == printers[j].symbol)
			{
				printf("%s", separator);
				printers[j].print(arguments);
				separator = ", ";
				j = 4;
			}

			j++;
		}

		i++;
	}

	va_end(arguments);
	printf("\n");
}
