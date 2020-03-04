#include"sandpiles.h"
/**
 * print_grid - p[rints the grid
 * @grid: the grid
 **/
void printf_grid(int grid[3][3])
{
		int i, j;

		for (i = 0; i < 3; i++)
		{
				for (j = 0; j < 3; j++)
				{
						if (j)
								printf(" ");
						printf("%d", grid[i][j]);
				}
				printf("\n");
		}
}
/**
 * sandpiles_add - adds two  grids
 * @grid1: the first grid, in whic we store the result of sum
 * @grid2: the second grid, that we use later for toppling
 *
 * Return: 1 if unstable and 0 if stable
 **/
int sandpiles_add(int grid1[3][3], int grid2[3][3])
{
		int i = 0;
		int j = 0;
		int unstable = 0;

		for (i = 0; i <= 2; i++)
		{
				for (j = 0; j <= 2; j++)
				{
						grid1[i][j] += grid2[i][j], grid2[i][j] = 0;
						if (grid1[i][j] >= 4)
								unstable = 1;

				}
		}
		return (unstable);
}
/**
 * sandpiles_topple - topples the grid untill it becomes stable
 * @grid1: the grid to topple
 * @grid2: the empty grid using for storing "sand"
 **/
void sandpiles_topple(int grid1[3][3], int grid2[3][3])
{
		int i, j, unstable;

		unstable = 1;
		while (unstable == 1)
		{
				printf("=\n");
				printf_grid(grid1);
				for (i = 0; i < 3; i++)
				{
						for (j = 0; j < 3; j++)
						{
								if (grid1[i][j] >= 4)
								{
												grid1[i][j] -= 4
										i - 1 >= 0 ? grid2[i - 1][j] += 1 : 0;
										i + 1 < 3 ? grid2[i + 1][j] += 1 : 0;
										j - 1 >= 0 ? grid2[i][j - 1] += 1 : 0;
																				j + 1 < 3 ? grid2[i][j + 1] += 1 : 0;
								}
						}
				}
				unstable = sandpiles_add(grid1, grid2);
		}
}
/**
 * sandpiles_sum - main func that adds and stabilizes grids
 * @grid1: the first grid
 * @grid2: the second grid
 **/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
		if (sandpiles_add(grid1, grid2))
				sandpiles_topple(grid1, grid2);
}

