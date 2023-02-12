
#include "turtle.h"
#include "main.h"

void move_outwards(size_t num, PLANE plane, turtle_t *turtle, canvas_t *canvas)
{
	size_t i, size;
	size_t *cur_pos = turtle->pos;

	if (plane == X)
		size = canvas->rows;
	else
		size = canvas->cols;

	for (i = 0; i < num && cur_pos[plane] < size; i++)
	{
		if (turtle->pen)
			canvas->floor[cur_pos[0]][cur_pos[1]] = '*';
		else
			canvas->floor[cur_pos[0]][cur_pos[1]] = ' ';

		cur_pos[plane] = unsigned_add(cur_pos[plane], 1);
	}
	positive_bound(cur_pos[plane], cur_pos, size, canvas);
}

void move_inwards(size_t num, PLANE plane, turtle_t *turtle, canvas_t *canvas)
{
	size_t i, n;
	size_t *cur_pos = turtle->pos;

	for (i = 0; i < num; i++)
	{
		if (turtle->pen)
			canvas->floor[cur_pos[0]][cur_pos[1]] = '*';
		else
			canvas->floor[cur_pos[0]][cur_pos[1]] = ' ';

		n = negative_bound(cur_pos[plane], 1, cur_pos);
		if (n)
			break;
		else
			cur_pos[plane]--;
	}
}

void move_to_pos(size_t row, size_t col, turtle_t *turtle, const canvas_t *canvas)
{
	if (row >= canvas->rows || col >= canvas->cols)
	{
		puts("Invalid position");
		return;
	}

	turtle->pos[0] = row;
	turtle->pos[1] = col;

	printf("%s[%lu, %lu]\n", "Position changed ", row, col);
}
