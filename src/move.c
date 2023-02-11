
#include "turtle.h"
#include "main.h"

void move_outwards(size_t num, PLANE plane, turtle_t *turtle, char **floor)
{
	size_t i;
	size_t *cur_pos = turtle->pos;

	for (i = 0; i < num && cur_pos[plane] < FLOOR_SIZE; i++)
	{
		if (turtle->pen == 1)
			floor[cur_pos[0]][cur_pos[1]] = '*';
		else
			floor[cur_pos[0]][cur_pos[1]] = ' ';

		cur_pos[plane] = unsigned_add(cur_pos[plane], 1);
	}
	positive_bound(cur_pos[plane], cur_pos);
}

void move_inwards(size_t num, PLANE plane, turtle_t *turtle, char **floor)
{
	size_t i, n;
	size_t *cur_pos = turtle->pos;

	for (i = 0; i < num; i++)
	{
		if (turtle->pen)
			floor[cur_pos[0]][cur_pos[1]] = '*';
		else
			floor[cur_pos[0]][cur_pos[1]] = ' ';

		n = negative_bound(cur_pos[plane], 1, cur_pos);
		if (n)
			break;
		else
			cur_pos[plane]--;
	}
}
