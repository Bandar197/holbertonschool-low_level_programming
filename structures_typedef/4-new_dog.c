#include "dog.h"
#include <stdlib.h>

/**
 * copy_string - creates a dynamically allocated copy of a string
 * @source: string to copy
 *
 * Return: pointer to the copied string, or NULL on failure
 */
char *copy_string(char *source)
{
	char *copy;
	unsigned int length;
	unsigned int index;

	if (source == 0)
		return (0);

	length = 0;
	while (source[length] != '\0')
		length++;

	copy = malloc(sizeof(char) * (length + 1));
	if (copy == 0)
		return (0);

	index = 0;
	while (index < length)
	{
		copy[index] = source[index];
		index++;
	}

	copy[index] = '\0';
	return (copy);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: name of the dog's owner
 *
 * Return: pointer to the new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(dog_t));
	if (dog == 0)
		return (0);

	dog->name = copy_string(name);
	if (dog->name == 0)
	{
		free(dog);
		return (0);
	}

	dog->owner = copy_string(owner);
	if (dog->owner == 0)
	{
		free(dog->name);
		free(dog);
		return (0);
	}

	dog->age = age;
	return (dog);
}
