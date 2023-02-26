#include "main.h"

void execute_commands_stdin(void)
{
	canvas_t *canvas;
	turtle_t *turtle;
	size_t command;

	startup(&canvas, &turtle);
	print_pos(turtle->pos, turtle->direction);
	scanf("%lu", &command);

	while (command != 1111)
	{
		if (command <= 6)
			execute_command_no_stream(command, turtle, canvas);
		else
			executeCommand(command, turtle, canvas);
		print_pos(turtle->pos, turtle->direction);
		scanf("%lu", &command);
	}
	free(turtle);
	destroy_canvas(canvas);
}