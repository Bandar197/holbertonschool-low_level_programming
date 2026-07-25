#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array containing values from min to max
 * @min: first value in the array
 * @max: final value in the array
 *
 * Return: pointer to the array, or NULL on failure
 */
int *array_range(int min, int max)
{
	int *array;
	int count;
	int index;

	if (min > max)
		return (NULL);

	count = max - min + 1;
	array = malloc(sizeof(int) * count);

	if (array == NULL)
		return (NULL);

	index = 0;
	while (index < count)
	{
		array[index] = min + index;
		index++;
	}

	return (array);
}
