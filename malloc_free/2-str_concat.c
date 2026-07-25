#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings into newly allocated memory
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *result;
	unsigned int length1;
	unsigned int length2;
	unsigned int index;
	unsigned int position;

	length1 = 0;
	length2 = 0;

	if (s1 != NULL)
	{
		while (s1[length1] != '\0')
			length1++;
	}

	if (s2 != NULL)
	{
		while (s2[length2] != '\0')
			length2++;
	}

	result = malloc(sizeof(char) * (length1 + length2 + 1));
	if (result == NULL)
		return (NULL);

	position = 0;
	index = 0;
	while (index < length1)
	{
		result[position] = s1[index];
		position++;
		index++;
	}

	index = 0;
	while (index < length2)
	{
		result[position] = s2[index];
		position++;
		index++;
	}

	result[position] = '\0';

	return (result);
}
