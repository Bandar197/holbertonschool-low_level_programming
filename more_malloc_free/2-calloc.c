#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates zero-initialized memory for an array
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: pointer to allocated memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned char *memory;
	unsigned int total;
	unsigned int index;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total = nmemb * size;
	memory = malloc(total);

	if (memory == NULL)
		return (NULL);

	index = 0;
	while (index < total)
	{
		memory[index] = 0;
		index++;
	}

	return (memory);
}
