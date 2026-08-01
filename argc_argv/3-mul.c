#include <stdio.h>
#include <stdlib.h>

/**
 * main - Multiplies two numbers
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 1 if argument count is incorrect
 */
int main(int argc, char *argv[])
{
	int first_number;
	int second_number;
	int result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	first_number = atoi(argv[1]);
	second_number = atoi(argv[2]);
	result = first_number * second_number;

	printf("%d\n", result);

	return (0);
}
