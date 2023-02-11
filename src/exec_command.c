#include "main.h"

void executeCommand(size_t command, size_t *pen, size_t *pos, DIRECTION *direction, char floor[][FLOOR_SIZE])
{
	void (*move)(size_t, size_t, size_t *, char [][FLOOR_SIZE]);
	size_t num;

	switch (command)
	{
		case 1:
			pen_up(pen);
			break;
		case 2:
			pen_down(pen);
			break;
		case 3:
			turn_right(direction);
			break;
		case 4:
			turn_left(direction);
			break;
		case 5:
			scanf(",%lu", &num);
			move = move_forward(*direction);
			move(*pen, num, pos, floor);
			break;
		case 6:
			print_floor(floor);
			break;
	}
}

// TODO : Add capability to clear floor
// TODO : Add capability to change floor size
// TODO : Add capability to change pen character
// TODO : Add capability to write floor to file
// TODO : Add capability to read floor from file
