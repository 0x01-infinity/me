#include "main.h"

void (*move_forward(DIRECTION direction))(size_t, size_t, size_t *, char [][FLOOR_SIZE])
{
	if (direction == RIGHT)
		return (move_right);
	else if (direction == DOWN)
		return (move_down);
	else if (direction == LEFT)
		return (move_left);
	else
		return (move_up);
}

void move_right(size_t pen, size_t num, size_t *pos, char floor[][FLOOR_SIZE])
{
	size_t i;

	for (i = 0; i < num && pos[1] < FLOOR_SIZE; i++)
	{
		if (pen)
			floor[pos[0]][pos[1]] = '*';
		else
			floor[pos[0]][pos[1]] = ' ';

		pos[1] = unsigned_add(pos[1], 1);
	}
	positive_bound(pos[1], pos);
}

void move_down(size_t pen, size_t num, size_t *pos, char floor[][FLOOR_SIZE])
{
	size_t i;

	for (i = 0; i < num && pos[0] < FLOOR_SIZE; i++)
	{
		if (pen)
			floor[pos[0]][pos[1]] = '*';
		else

			floor[pos[0]][pos[1]] = ' ';

		pos[0] = unsigned_add(pos[0], 1);
	}
	positive_bound(pos[0], pos);
}

void move_left(size_t pen, size_t num, size_t *pos, char floor[][FLOOR_SIZE])
{
	size_t i, n;

	for (i = 0; i < num; i++)
	{
		if (pen)
			floor[pos[0]][pos[1]] = '*';
		else
			floor[pos[0]][pos[1]] = ' ';

		n = negative_bound(pos[1], 1, pos);
		if (n)
			break;
		else
			pos[1]--;
	}
}

void move_up(size_t pen, size_t num, size_t *pos, char floor[][FLOOR_SIZE])
{
	size_t i, n;

	for (i = 0; i < num; i++)
	{
		if (pen)
			floor[pos[0]][pos[1]] = '*';
		else
			floor[pos[0]][pos[1]] = ' ';

		n = negative_bound(pos[0], 1, pos);
		if (n)
			break;
		else
			pos[0]--;
	}
}