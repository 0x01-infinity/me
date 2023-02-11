#ifndef _canvas_h
#define _canvas_h

#include <stdio.h>

typedef struct canvas_s
{
        size_t row;
        size_t col;
        size_t canvas[row][col];
        struct canvasProto proto;
} canvas_t;

struct canvasProto
{
        void (*print)(canvas_t *);
        void (*clear)(canvas_t *);
        void (*write)(FILE *, canvas_t *);
        canvas_t *(*load)(FILE *);
        canvas_t *(*resize)(canvas_t *, size_t);
};

#endif