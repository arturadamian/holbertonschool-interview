#include "slide_line.h"

/**
 * reverse - reverses the array
 * @line: pointer to the array
 * @size: size of the array
 **/
void reverse(int *line, size_t size)
{
	for (size_t low = 0, high = size - 1; low < high; low++, high--)
	{
		int temp = line[low];

		line[low] = line[high];
		line[high] = temp;
	}
}

/**
 * findTarget - finds the target
 * @line: pointer to the array
 * @x: index of the array
 * @stop: stop position
 *
 * Return: the index of the array
 **/
int findTarget(int *line, int x, int stop)
{
	int t;

	if (x == 0)
	{
		return (x);
	}
	for (t = x - 1;; t--)
	{
		if (line[t] != 0)
		{
			if (line[t] != line[x])
			{
				return (t + 1);
			}
			return (t);
		}
		else
		{
			if (t == stop)
			{
				return (t);
			}
		}
	}
	return (x);
}

/**
 * slide_it - slides the array
 * @line: pointer to the array
 * @size: size of the array
 *
 * Return: 1 if success or 0
 **/
int slide_it(int *line, size_t size)
{
	int success = 1;
	size_t x, t, stop = 0;

	for (x = 0; x < size; x++)
	{
		if (line[x] != 0)
		{
			t = findTarget(line, x, stop);
			if (t != x)
			{
				if (line[t] == 0)
				{
					line[t] = line[x];
				}
				else if (line[t] == line[x])
				{
					line[t] += line[t];
					stop = t + 1;
				}
				line[x] = 0;
				success = 1;
			}
		}
	}
	return (success);
}

/**
 * slide_line - slide the input array to the left or right
 * @line: pointer to the array
 * @size: size of the array
 * @direction: left or right
 *
 * Return: 1 if success or 0
 **/
int slide_line(int *line, size_t size, int direction)
{
	int success = 0;

	if (direction == SLIDE_RIGHT)
	{
		reverse(line, size);
		success = slide_it(line, size);
		reverse(line, size);
		return (success);
	}
	else if (direction == SLIDE_LEFT)
	{
		return (slide_it(line, size));
	}
	else if (direction != SLIDE_LEFT || direction != SLIDE_RIGHT)
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
