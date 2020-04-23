#include "menger.h"

/**
 * menger - draws 2D menger sponge
 * @x: index for rows
 * @y: index for columns
 *
 * Return: '#' or ' '
 */
char sponge(int x, int y)
{
	while (x || y)
	{
		if (y % 3 == 1 && x % 3 == 1)
			return (' ');
		x = x / 3;
		y = y / 3;
	}
	return ('#');
}

/**
 * menger - draws 2D menger sponge
 * @level: levels of sponge
 **/
void menger(int level)
{
	int x, y, the_level;

	if (level < 0)
		return;
	the_level = pow(3, level);
	for (x = 0; x < the_level; x++)
	{
		for (y = 0; y < the_level; y++)
			putchar(sponge(x, y));
		putchar('\n');
	}
}
