#include "main.h"

void execute_command_file(size_t command, FILE *input, turtle_t *turtle, canvas_t *canvas)
{
	size_t num, row, col;
	char c, filename[11];

	switch (command)
	{
	case 7:
		fscanf(input, ",%lu", &num);
		move(num, turtle, canvas);
		break;
	case 8:
		fscanf(input, "%c", &c);
		fill_canvas(canvas, c);
		break;
	case 9:
		fscanf(input, "%lu, %lu", &row, &col);
		move_to_pos(row, col, turtle, canvas);
		break;
	case 10:
                fscanf(input, "%10s", filename);
	        write_canvas(canvas, filename);
		break;
	case 11:
                fscanf(input, "%10s", filename);
		load_new_canvas(&canvas, filename);
		break;
	}
}
