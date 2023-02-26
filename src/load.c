#include "main.h"

canvas_t *load_canvas(char *filename)
{
	canvas_t *_new_canvas;
	size_t dimensions[2];

	FILE *input = fopen(filename, "r");
	if (!input)
	{
		perror("");
		return (NULL);
	}

	get_size(input, dimensions);

	_new_canvas = new_canvas(dimensions[0], dimensions[1]);

	if(!_new_canvas)
		die("Mem allocation");

	rewind(input);
	populate_canvas(input, _new_canvas);
	fclose(input);

	printf("%s%s", filename, " -> loaded successfully.\n\n");

	print_canvas(_new_canvas);
	return (_new_canvas);
}

void load_new_canvas(canvas_t **canvas, char *filename)
{
	size_t dimensions[2];

	FILE *input = fopen(filename, "r");
	if (!input)
	{
		perror("File couldn't be loaded");
		return;
	}

	get_size(input, dimensions);
	
	_realloc_floor(*canvas, dimensions);

	rewind(input);
	populate_canvas(input, *canvas);
	fclose(input);

	printf("%s%s", filename, " -> loaded successfully.\n\n");

	print_canvas(*canvas);
}

void get_size(FILE *input, size_t *dimensions)
{
	char c;
	size_t count, *size = dimensions;

	size[0] = 0;
	size[1] = 0;

	count = 0;
	while ((c = getc(input)) != EOF)
	{
		if (c == '\n')
		{
			if (count > size[1])
				size[1] = count;
			size[0]++;
			count = 0;
		}
		else
		{
			count++;
		}
	}
}

void populate_canvas(FILE *input, canvas_t *canvas)
{
	char c ;
	size_t row, col;

	row = col = 0;
	while ((c = getc(input)) != EOF && row < canvas->rows)
	{
		if (c != '\n')
		{
			canvas->floor[row][col++] = c;
		}
		else
		{
			col = 0;
			row++;
		}
	}
}

void _realloc_floor(canvas_t *canvas, size_t *dimensions)
{
	size_t i;

	if (dimensions[0] < canvas->rows)
	{
		for (i = dimensions[0]; i < canvas->rows; i++)
			free(canvas->floor[i]);
	}

	canvas->floor = realloc(canvas->floor, dimensions[0] * sizeof(char *));

	if(!canvas->floor)
		die("Mem allocation");

	if (dimensions[1] != canvas->cols)
		_realloc_rows(canvas, dimensions);

	if (dimensions[0] > canvas->rows)
		_alloc_new_rows(canvas, dimensions);

	canvas->rows = dimensions[0];
	canvas->cols = dimensions[1];

	clear_canvas(canvas);
}

void _realloc_rows(canvas_t *canvas, size_t *size)
{
	size_t row_size, i, j;

	row_size = (canvas->rows < size[0]) ? canvas->rows : size[0];
	for (i = 0; i < row_size; i++)
	{
		canvas->floor[i] = realloc(canvas->floor[i], sizeof(char) * size[1]);
		if (!canvas->floor)
		{
			for (j = 0; j < row_size; j++)
				free(canvas->floor[j]);
			free(canvas->floor);
			perror("floor realloc");
		}
	}
}

void _alloc_new_rows(canvas_t *canvas, size_t *size)
{
	size_t i, j;

	for (i = canvas->rows; i < size[0]; i++)
	{
		canvas->floor[i] = calloc(size[1], sizeof(char));
		if (!canvas->floor)
		{
			for (j = 0; j < i; j++)
				free(canvas->floor[j]);
			free(canvas->floor);
			perror("floor realloc");
		}
	}
}