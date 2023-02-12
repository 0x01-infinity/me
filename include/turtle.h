#ifndef _turtle_h
#define _turtle_h

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "canvas.h"

typedef enum plane {X, Y} PLANE;

typedef enum direction {RIGHT, DOWN, LEFT, UP} DIRECTION;
typedef struct turtle_s
{
	size_t pen;
	size_t pos[2];
	DIRECTION direction;
} turtle_t;

turtle_t *new_turtle(size_t row, size_t col);

void turn_right(turtle_t *turtle);
void turn_left(turtle_t *turtle);
void turn_opposite(turtle_t *turtle);

void move(size_t num, turtle_t *turtle, canvas_t *canvas);
void move_outwards(size_t num, PLANE plane, turtle_t *turtle, canvas_t *canvas);
void move_inwards(size_t num, PLANE plane, turtle_t *turtle, canvas_t *canvas);
void move_to_pos(size_t row, size_t col, turtle_t *turtle, const canvas_t *canvas);

void pen_up(turtle_t *turtle);
void pen_down(turtle_t *turtle);

void print_pos(size_t *pos, DIRECTION direction);

#endif