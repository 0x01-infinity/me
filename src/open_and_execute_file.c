#include "main.h"

void open_and_exec_file(char *filename)
{
	canvas_t *canvas;
	turtle_t *turtle;
	FILE *input;
	size_t command;

	input = fopen(filename, "r");
	if (!input)
		die("Cannot open file");

	startup_from_file(input, &canvas, &turtle);
	print_pos(turtle->pos, turtle->direction);

	fscanf(input, "%lu", &command);

	while (command != 1111)
	{
		if (command <= 6)
			exec_command_no_stream(command, turtle, canvas);
		else
			exec_command_file(command, input, turtle, canvas);

		print_pos(turtle->pos, turtle->direction);
		fscanf(input, "%lu", &command);
	}
	fclose(input);
	free(turtle);
	destroy_canvas(canvas);
}