#include "main.h"

void get_turtle_file(FILE *input, turtle_t **turtle, canvas_t *canvas);
void get_canvas_file(FILE *input, canvas_t **canvas);

void startup_from_file(FILE *input, canvas_t **canvas, turtle_t **turtle)
{
	get_canvas_file(input, canvas);
	if (!*canvas)
        {
                fclose(input);
		die("Failed allocation of canvas");
        }
	
	get_turtle_file(input, turtle, *canvas);
	if (!*turtle)
	{
                fclose(input);
		destroy_canvas(*canvas);
		die("Failed allocation of turtle");
	}
}

void get_canvas_file(FILE *input, canvas_t **canvas)
{
	size_t row, col, opt;
        char filename[11];

	fscanf(input, "%lu", &opt);

	if (!(opt >= 1 && opt <= 2))
	{
		*canvas = NULL;
                return;
	}

	col = row = 0;
	switch (opt)
	{
	case 1:
		fscanf(input, "%lu, %lu", &row, &col);

		if (row == 0 || col == 0)
                {
                        *canvas = NULL;
                        return;
                }
		*canvas = new_canvas(row, col);
		printf("%s[%lu, %lu]%s", "Created ", row, col, " blank canvas\n\n");
		break;
	case 2:
                fscanf(input, "%10s", filename);
		*canvas = load_canvas(filename);
		break;
	}
}

void get_turtle_file(FILE *input, turtle_t **turtle, canvas_t *canvas)
{
	size_t row, col;

	fscanf(input, "%lu, %lu", &row, &col);

	if (row >= canvas->rows || col >= canvas->cols)
        {
		*turtle = NULL;
                return;
        }

	*turtle = new_turtle(row, col);
}
