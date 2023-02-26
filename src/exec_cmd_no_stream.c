#include "main.h"

void execute_command_no_stream(size_t command, turtle_t *turtle, canvas_t *canvas)
{
	switch (command)
	{
	case 0:
		clear_canvas(canvas);
		break;
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
		print_canvas(canvas);
		break;
	case 6:
		turn_opposite(turtle);
		break;
        }
}