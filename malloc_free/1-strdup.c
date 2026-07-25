#include "main.h"
#include <stdlib.h>

/**
 * _strdup - creates a dynamically allocated copy of a string
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *copy;
	unsigned int length;
	unsigned int index;

	if (str == NULL)
		return (NULL);

	length = 0;
	while (str[length] != '\0')
		length++;

	copy = malloc(sizeof(char) * (length + 1));
	if (copy == NULL)
		return (NULL);

	index = 0;
	while (index < length)
	{
		copy[index] = str[index];
		index++;
	}

	copy[index] = '\0';

	return (copy);
}
