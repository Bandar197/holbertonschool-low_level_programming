#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array initialized with a specific character
 * @size: number of characters in the array
 * @c: character used to initialize the array
 *
 * Return: pointer to the array, or NULL on failure
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int index;

	if (size == 0)
		return (NULL);

	array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);

	index = 0;
	while (index < size)
	{
		array[index] = c;
		index++;
	}

	return (array);
}
