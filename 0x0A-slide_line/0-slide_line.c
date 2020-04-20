#include "slide_line.h"


/**
 * reverse - reverse the array
 * @line: pointer to the array
 * @size: size of the array
 **/
void reverse(int *line, size_t size)
{
	size_t a, b;

	a = 0;
	b = size - 1;
	while (a < b)
	{
		int temp = line[a];

		line[a] = line[b];
		line[b] = temp;
		a++;
		b--;
	}
}

/**
 * slide_zero - moves zeros
 * @line: pointer to the array
 * @size: size of the array
 **/
void slide_zero(int *line, size_t size)
{
	size_t x;
	size_t zero = 0;

	x = 0;
	while (x < size)
	{
		if (line[x] == 0)
			zero++;
		else if (zero)
			line[x - zero] = line[x];
		x++;
	}
	while (zero > 0)
	{
		line[x - 1] = 0;
		zero--;
		x--;
	}
}

/**
 * slide_non_zero - moves non zero ints
 * @line: pointer to the array
 * @size: size of the array
 **/
void slide_non_zero(int *line, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
		i += 2;
	}
}

/**
 * slide_line - slides the array
 * @line: pointer to the array
 * @size: size of the array
 *
 * Return: 1 if success or 0
 **/
int slide_line(int *line, size_t size, int direction)
{

	if (direction == SLIDE_LEFT)
	{
		slide_zero(line, size);
		slide_non_zero(line, size);
		slide_zero(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		reverse(line, size);
		slide_zero(line, size);
		slide_non_zero(line, size);
		slide_zero(line, size);
		reverse(line, size);
		return (1);
	}
	return (0);
}
