#ifndef _main_h
#define _main_h

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define FLOOR_SIZE 50

typedef enum direction
{
	RIGHT,
	DOWN,
	LEFT,
	UP
} DIRECTION;

void executeCommand(size_t command, size_t *pen, size_t *pos, DIRECTION *direction, char floor[][FLOOR_SIZE]);

void pen_up(size_t *pen);
void pen_down(size_t *pen);

void turn_right(DIRECTION *direction);
void turn_left(DIRECTION *direction);

void (*move_forward(DIRECTION direction))(size_t, size_t, size_t *, char [][FLOOR_SIZE]);
void move_right(size_t pen, size_t num, size_t *pos, char floor[][FLOOR_SIZE]);
void move_down(size_t pen, size_t num, size_t *pos, char floor[][FLOOR_SIZE]);
void move_left(size_t pen, size_t num, size_t *pos, char floor[][FLOOR_SIZE]);
void move_up(size_t pen, size_t num, size_t *pos, char floor[][FLOOR_SIZE]);

void print_pos(size_t *pos, DIRECTION direction);
void print_floor(char floor[][FLOOR_SIZE]);
void initialize(char floor[][FLOOR_SIZE]);

size_t unsigned_sub(size_t a, size_t b);
size_t unsigned_add(size_t a, size_t b);
void positive_bound(size_t point, size_t *pos);
size_t negative_bound(size_t point, size_t b, size_t *pos);
void die(const char *message);

#endif