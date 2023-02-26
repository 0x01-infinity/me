#include "main.h"

void read_and_exec_stdin(void)
{
	canvas_t *canvas;
	turtle_t *turtle;
	size_t command;

	startup_from_stdin(&canvas, &turtle);
	print_pos(turtle->pos, turtle->direction);
	scanf("%lu", &command);

	while (command != 1111)
	{
		if (command <= 6)
			exec_command_no_stream(command, turtle, canvas);
		else
			exec_command_stdin(command, turtle, canvas);
		print_pos(turtle->pos, turtle->direction);
		scanf("%lu", &command);
	}
	free(turtle);
	destroy_canvas(canvas);
}