#include "main.h"
#include "turtle.h"
#include "canvas.h"

int main(void)
{
	size_t command;
	turtle_t *turtle = Turtle_new();
	canvas_t *canvas = new_canvas(FLOOR_SIZE, FLOOR_SIZE);

	print_pos(turtle->pos, turtle->direction);
	puts("\nEnter commands");

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
