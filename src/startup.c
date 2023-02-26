#include "main.h"

void get_turtle(turtle_t **turtle, canvas_t *canvas);
void get_canvas(canvas_t **canvas);

void startup(canvas_t **canvas, turtle_t **turtle)
{
	get_canvas(canvas);
	if (!*canvas)
		die("Failed allocation of canvas");

	get_turtle(turtle, *canvas);
	if (!*turtle)
	{
		destroy_canvas(*canvas);
		die("Failed allocation of turtle");
	}
}

void get_canvas(canvas_t **canvas)
{
	size_t row, col, opt;
	char filename[11];

	puts("Sellect option (1 or 2):");
	puts("1: Create new canvas");
	puts("2: Load existing canvas");
	printf("%s", "-> ");

	scanf("%lu", &opt);

	while (!(opt >= 1 && opt <= 2))
	{
		puts("Enter valid option");
		printf("%s", "-> ");
		scanf("%lu", &opt);
	}

	col = row = 0;
	switch (opt)
	{
	case 1:
		printf("%s", "Enter size of the canvas (rows, cols): ");
		scanf("%lu, %lu", &row, &col);

		while (row == 0 || col == 0)
		{
			printf("%s", "Enter valid size (rows, cols): ");
			scanf("%lu, %lu", &row, &col);
		}
		*canvas = new_canvas(row, col);
		printf("%s[%lu, %lu]%s", "Created ", row, col, " blank canvas\n\n");
		break;
	case 2:
		printf("Enter file to load: ");
		scanf("%10s", filename);
		*canvas = load_canvas(filename);
		break;
	}
}

void get_turtle(turtle_t **turtle, canvas_t *canvas)
{
	size_t row, col;

	printf("%s[%lu, %lu]: ", "Enter starting position [0, 0] -> ", canvas->rows - 1, canvas->cols - 1);
	scanf("%lu, %lu", &row, &col);

	while(row >= canvas->rows || col >= canvas->cols)
	{
		puts("Invalid position");
		printf("%s", "-> ");
		scanf("%lu, %lu", &row, &col);
	}

	*turtle = new_turtle(row, col);
}
