#include "main.h"

void print_floor(char floor[][50])
{
	size_t i, j;

	for (i = 0; i < 50; i ++)
	{
		for (j = 0; j < 50; j ++)
			putchar(floor[i][j]);
		putchar('\n');
	}
}

void print_pos(size_t *pos, DIRECTION direction)
{
	printf("\nCurrently at pos: [%lu, %lu]\n", pos[0], pos[1]);

	if (direction == RIGHT)
		puts("Pointing right ➡️");
	if (direction == LEFT)
		puts("Pointing left ⬅️");
	if (direction == UP)
		puts("Pointing up ⬆️");
	if (direction == DOWN)
		puts("Pointing down ⬇️");
}

void initialize(char floor[][FLOOR_SIZE])
{
	int i, j;

	for (i = 0; i < FLOOR_SIZE; i++)
	{
		for (j = 0; j < FLOOR_SIZE; j++)
			floor[i][j] = ' ';
	}
}