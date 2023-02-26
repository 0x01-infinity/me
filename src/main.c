#include "main.h"
#include "turtle.h"
#include "canvas.h"

int main(void)
{
	size_t command;
	canvas_t *canvas;
	turtle_t *turtle;

	startup(&canvas, &turtle);

	print_pos(turtle->pos, turtle->direction);

	scanf("%lu", &command);

	while (command != 9)
	{
		executeCommand(command, turtle, canvas);

		print_pos(turtle->pos, turtle->direction);
		scanf("%lu", &command);
	}
	free(turtle);
	destroy_canvas(canvas);

	return (0);
}
