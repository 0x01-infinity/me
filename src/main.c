#include "main.h"
#include "turtle.h"
#include "canvas.h"

int main(void)
{
	size_t command, row, col;

	printf("%s", "Enter the size of the canvas (rows, columns): ");
	scanf("%lu, %lu", &row, &col);

	canvas_t *canvas = new_canvas(row, col);

	printf("%s", "Enter the starting position of the turtle: ");
	scanf("%lu, %lu", &row, &col);

	turtle_t *turtle = new_turtle(row, col);

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
