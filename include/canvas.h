#ifndef _canvas_h
#define _canvas_h

#include <stdio.h>
#include <stdlib.h>

typedef struct canvas_s
{
	size_t rows;
	size_t cols;
	char **floor;
} canvas_t;

canvas_t *new_canvas(size_t row, size_t col);
char **new_floor(size_t row, size_t col);
void destroy_canvas(canvas_t *canvas);

void print_canvas(canvas_t *canvas);
void fill_canvas(canvas_t *canvas, char c);
void clear_canvas(canvas_t *canvas);

void write_canvas(FILE *input, canvas_t *canvas);
canvas_t *load_canvas(FILE *input);
canvas_t *resize_canvas(canvas_t *canvas, size_t new_size);

#endif