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

void write_canvas(canvas_t *canvas, char *filename);
canvas_t *load_canvas(char *filename);
void load_new_canvas(canvas_t **canvas, char *filename);
void _realloc_floor(canvas_t *canvas, size_t *dimensions);
void _realloc_rows(canvas_t *canvas, size_t *size);
void _alloc_new_rows(canvas_t *canvas, size_t *size);
void get_size(FILE *input, size_t *dimensions);
void populate_canvas(FILE *input, canvas_t *canvas);
canvas_t *resize_canvas(canvas_t *canvas, size_t new_size);

#endif