#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - allocates a two-dimensional array of integers
 * @width: number of columns
 * @height: number of rows
 *
 * Return: pointer to the grid, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int row;
	int column;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	row = 0;
	while (row < height)
	{
		grid[row] = malloc(sizeof(int) * width);

		if (grid[row] == NULL)
		{
			while (row > 0)
			{
				row--;
				free(grid[row]);
			}

			free(grid);
			return (NULL);
		}

		column = 0;
		while (column < width)
		{
			grid[row][column] = 0;
			column++;
		}

		row++;
	}

	return (grid);
}
