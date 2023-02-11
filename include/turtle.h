#ifndef _turtle_h
#define _turtle_h

#include <stddef.h>
#include <stdlib.h>

#define FLOOR_SIZE 50

typedef enum direction
{
	RIGHT,
	DOWN,
	LEFT,
	UP
} DIRECTION;

typedef struct turtle_s
{
	size_t pen;
	size_t pos[2];
	DIRECTION direction;
} turtle_t;

turtle_t *Turtle_new(void);

void turn_right(turtle_t *turtle);
void turn_left(turtle_t *turtle);
void turn_opposite(turtle_t *turtle);

void move(size_t num, turtle_t *turtle, char floor[][FLOOR_SIZE]);
void move_right(size_t num, turtle_t *turtle, char floor[][FLOOR_SIZE]);
void move_down(size_t num, turtle_t *turtle, char floor[][FLOOR_SIZE]);
void move_left(size_t num, turtle_t *turtle, char floor[][FLOOR_SIZE]);
void move_up(size_t num, turtle_t *turtle, char floor[][FLOOR_SIZE]);

void pen_up(turtle_t *turtle);
void pen_down(turtle_t *turtle);

void print_pos(size_t *pos, DIRECTION direction);
size_t unsigned_sub(size_t a, size_t b);
size_t unsigned_add(size_t a, size_t b);
void positive_bound(size_t point, size_t *pos);
size_t negative_bound(size_t point, size_t b, size_t *pos);
void die(const char *message);


#endif