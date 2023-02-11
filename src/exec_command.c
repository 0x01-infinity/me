#include "main.h"
#include "turtle.h"

void executeCommand(size_t command, turtle_t *turtle, char floor[][FLOOR_SIZE])
{
	size_t num;

	switch (command)
	{
		case 1:
			pen_up(turtle);
			break;
		case 2:
			pen_down(turtle);
			break;
		case 3:
			turn_right(turtle);
			break;
		case 4:
			turn_left(turtle);
			break;
		case 5:
			scanf(",%lu", &num);
			move(num, turtle, floor);
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
