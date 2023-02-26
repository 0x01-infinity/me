#include "main.h"

void executeCommand(size_t command, turtle_t *turtle, canvas_t *canvas)
{
	size_t num, row, col;
	char c, filename[11];

	switch (command)
	{
	case 7:
		scanf(",%lu", &num);
		move(num, turtle, canvas);
		break;
	case 8:
		printf("%s", "Enter character to fill: ");
		flush();
		scanf("%c", &c);
		fill_canvas(canvas, c);
		break;
	case 9:
		printf("%s[%lu, %lu]: ", "Enter new position [0, 0] -> ", canvas->rows - 1, canvas->cols - 1);
		flush();
		scanf("%lu, %lu", &row, &col);
		move_to_pos(row, col, turtle, canvas);
		break;
	case 10:
		printf("%s", "Enter filename to save canvas: ");
        	scanf("%10s", filename);
		write_canvas(canvas, filename);
		break;
	case 11:
		printf("Enter file to load: ");
		scanf("%10s", filename);
		load_new_canvas(&canvas, filename);
		break;
	}
}

// TODO : Add capability to change floor size
// TODO : Add capability to change pen character
// TODO : Add capability to write floor to file
// TODO : Add capability to read floor from file
