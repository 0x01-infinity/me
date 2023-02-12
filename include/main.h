#ifndef _main_h
#define _main_h

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "turtle.h"
#include "canvas.h"


void executeCommand(size_t command, turtle_t *turtle, canvas_t *canvas);

size_t unsigned_sub(size_t a, size_t b);
size_t unsigned_add(size_t a, size_t b);
void positive_bound(size_t point, size_t *pos, size_t size, canvas_t *canvas);
size_t negative_bound(size_t point, size_t b, size_t *pos);

void flush();
void die(const char *message);

#endif