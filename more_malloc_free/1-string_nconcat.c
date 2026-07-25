#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: maximum number of bytes copied from s2
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int length1;
	unsigned int length2;
	unsigned int copy_length;
	unsigned int index;

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

	if (n >= length2)
		copy_length = length2;
	else
		copy_length = n;

	result = malloc(sizeof(char) * (length1 + copy_length + 1));
	if (result == NULL)
		return (NULL);

	index = 0;
	while (index < length1)
	{
		result[index] = s1[index];
		index++;
	}

	index = 0;
	while (index < copy_length)
	{
		result[length1 + index] = s2[index];
		index++;
	}

	result[length1 + copy_length] = '\0';

	return (result);
}
