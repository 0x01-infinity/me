#ifndef _main_h
#define _main_h

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>

#include "turtle.h"
#include "canvas.h"

void startup(canvas_t **canvas, turtle_t **turtle);
void startup_from_file(FILE *input, canvas_t **canvas, turtle_t **turtle);
void executeCommand(size_t command, turtle_t *turtle, canvas_t *canvas);
void execute_command_file(size_t command, FILE *input, turtle_t *turtle, canvas_t *canvas);
void execute_command_no_stream(size_t command, turtle_t *turtle, canvas_t *canvas);

void open_and_exec_file(char *filename);
void execute_commands_stdin(void);

size_t unsigned_sub(size_t a, size_t b);
size_t unsigned_add(size_t a, size_t b);
void positive_bound(size_t point, size_t *pos, size_t size, canvas_t *canvas);
size_t negative_bound(size_t point, size_t b, size_t *pos);

void flush();
void die(const char *message);

#endif