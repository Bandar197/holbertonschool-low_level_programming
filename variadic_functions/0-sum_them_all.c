#include <stdarg.h>
#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of all its parameters
 * @n: number of parameters
 *
 * Return: sum of all parameters, or 0 if n is 0
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list arguments;
	unsigned int i;
	int sum = 0;

	if (n == 0)
		return (0);

	va_start(arguments, n);

	for (i = 0; i < n; i++)
		sum += va_arg(arguments, int);

	va_end(arguments);

	return (sum);
}
