#include "main.h"
#include "turtle.h"
#include "canvas.h"

void executeCommand(size_t command, turtle_t *turtle, canvas_t *canvas)
{
	size_t num, row, col;
	char c;

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
			scanf(",%lu", &num);
			move(num, turtle, canvas);
			break;
		case 6:
			print_canvas(canvas);
			break;
		case 7:
			turn_opposite(turtle);
			break;
		case 8:
			printf("%s", "Enter character to fill: ");
			flush();
			scanf("%c", &c);
			fill_canvas(canvas, c);
			break;
		case 10:
			printf("%s[%lu, %lu]: ", "Enter new position [0, 0] -> ", canvas->rows - 1, canvas->cols - 1);
			flush();
			scanf("%lu, %lu", &row, &col);
			move_to_pos(row, col, turtle, canvas);
			break;
	}
}

// TODO : Add capability to change floor size
// TODO : Add capability to change pen character
// TODO : Add capability to write floor to file
// TODO : Add capability to read floor from file
