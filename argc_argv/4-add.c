#include <stdio.h>
#include <stdlib.h>

/**
 * main - Adds positive numbers
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 1 if an argument contains a non-digit
 */
int main(int argc, char *argv[])
{
	int argument_index;
	int character_index;
	int sum;

	argument_index = 1;
	sum = 0;

	while (argument_index < argc)
	{
		character_index = 0;

		while (argv[argument_index][character_index] != '\0')
		{
			if (argv[argument_index][character_index] < '0' ||
			    argv[argument_index][character_index] > '9')
			{
				printf("Error\n");
				return (1);
			}

			character_index++;
		}

		sum += atoi(argv[argument_index]);
		argument_index++;
	}

	printf("%d\n", sum);

	return (0);
}
