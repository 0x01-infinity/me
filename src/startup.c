#include "main.h"
#include "canvas.h"
#include "turtle.h"

void get_turtle(turtle_t **turtle);
void get_canvas(canvas_t **canvas);

void startup(canvas_t **canvas, turtle_t **turtle)
{
	get_canvas(canvas);
	if (!*canvas)
		die("Failed allocation of canvas");
	
	get_turtle(turtle);
	if (!*turtle)
	{
		destroy_canvas(*canvas);
		die("Failed allocation of turtle");
	}
}

void get_canvas(canvas_t **canvas)
{
	size_t row, col, opt;

	puts("Sellect option (1 or 2):");
	puts("1: Create new canvas");
	puts("2: Load existing canvas");
	printf("%s", "-> ");

	scanf("%1lu", &opt);

	switch (opt)
	{
		case 1:
			printf("%s", "Enter size of the canvas (rows, cols): ");
			scanf("%lu, %lu", &row, &col);

                        *canvas = new_canvas(row, col);
                        break;
                case 2:
                        *canvas = load_canvas();
                        break;
	}
}

void get_turtle(turtle_t **turtle)
{
        size_t row, col;

        printf("%s", "Enter starting position of the turtle (row, col): ");
        scanf("%lu, %lu", &row, &col);

        *turtle = new_turtle(row, col);
}