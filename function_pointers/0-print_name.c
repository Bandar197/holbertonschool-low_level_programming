#include "function_pointers.h"

/**
 * print_name - prints a name using a callback function
 * @name: pointer to the name
 * @f: pointer to the function used to print the name
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (f != 0)
		f(name);
}
