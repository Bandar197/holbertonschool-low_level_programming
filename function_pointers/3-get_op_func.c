#include "3-calc.h"

/**
 * get_op_func - selects the function associated with an operator
 * @s: operator received by the program
 *
 * Return: pointer to the matching function, or NULL
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op != NULL &&
	       !(ops[i].op[0] == s[0] && s[1] == '\0'))
		i++;

	return (ops[i].f);
}
