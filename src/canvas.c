#include "canvas.h"
#include "main.h"

canvas_t *new_canvas(size_t r, size_t c)
{
	canvas_t *canvas = malloc(sizeof(canvas));

	if (!canvas)
		die("Failed to allocate canvas");

	canvas->rows = r;
	canvas->cols = c;
	canvas->floor = new_floor(r, c);

	return (canvas);
}

char **new_floor(size_t r, size_t c)
{
	size_t i, j;
	char **floor = malloc(sizeof(char *) * r);

	if (!floor)
		die("Failed to allocate floor");

	for (i = 0; i < r; i++)
	{
		floor[i] = malloc(sizeof(char) * c);
		if (!floor[i])
		{
			for (j = 0; j < i; j++)
				free(floor[i]);
			free(floor);
			die("Failed to allocate floor row");
		}
	}

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
			floor[i][j] = '\0';
	}

	return (floor);
}

void print_canvas(canvas_t *canvas)
{
	size_t i, j;

	for (i = 0; i < canvas->rows; i++)
	{
		for (j = 0; j < canvas->cols; j++)
			putchar(canvas->floor[i][j]);
		printf("%lu", i);
		putchar('\n');
	}
}

void fill_canvas(canvas_t *canvas, char c)
{
	size_t i, j;

	for (i = 0; i < canvas->rows; i++)
	{
		for (j = 0; j < canvas->cols; j++)
			canvas->floor[i][j] = c;
	}
}

void clear_canvas(canvas_t *canvas)
{
	fill_canvas(canvas, '\0');
}

void destroy_canvas(canvas_t *canvas)
{
	size_t i;

	for (i = 0; i < canvas->rows; i++)
		free(canvas->floor[i]);
	
	free(canvas->floor);
	free(canvas);
}