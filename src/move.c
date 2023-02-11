
#include "turtle.h"

void move_right(size_t num, turtle_t *turtle, char floor[][FLOOR_SIZE])
{
	size_t i;
	size_t *cur_pos = turtle->pos;

	for (i = 0; i < num && cur_pos[1] < FLOOR_SIZE; i++)
	{
		if (turtle->pen == 1)
			floor[cur_pos[0]][cur_pos[1]] = '*';
		else
			floor[cur_pos[0]][cur_pos[1]] = ' ';

		cur_pos[1] = unsigned_add(cur_pos[1], 1);
	}
	positive_bound(cur_pos[1], cur_pos);
}

void move_down(size_t num, turtle_t *turtle, char floor[][FLOOR_SIZE])
{
	size_t i;
	size_t *cur_pos = turtle->pos;

	for (i = 0; i < num && cur_pos[0] < FLOOR_SIZE; i++)
	{
		if (turtle->pen)
			floor[cur_pos[0]][cur_pos[1]] = '*';
		else

			floor[cur_pos[0]][cur_pos[1]] = ' ';

		cur_pos[0] = unsigned_add(cur_pos[0], 1);
	}
	positive_bound(cur_pos[0], cur_pos);
}

void move_left(size_t num, turtle_t *turtle, char floor[][FLOOR_SIZE])
{
	size_t i, n;
	size_t *cur_pos = turtle->pos;

	for (i = 0; i < num; i++)
	{
		if (turtle->pen)
			floor[cur_pos[0]][cur_pos[1]] = '*';
		else
			floor[cur_pos[0]][cur_pos[1]] = ' ';

		n = negative_bound(cur_pos[1], 1, cur_pos);
		if (n)
			break;
		else
			cur_pos[1]--;
	}
}

void move_up(size_t num, turtle_t *turtle, char floor[][FLOOR_SIZE])
{
	size_t i, n;
	size_t *cur_pos = turtle->pos;

	for (i = 0; i < num; i++)
	{
		if (turtle->pen)
			floor[cur_pos[0]][cur_pos[1]] = '*';
		else
			floor[cur_pos[0]][cur_pos[1]] = ' ';

		n = negative_bound(cur_pos[0], 1, cur_pos);
		if (n)
			break;
		else
			cur_pos[0]--;
	}
}