#include "turtle.h"
#include "main.h"

turtle_t *new_turtle(size_t row, size_t col)
{
	turtle_t *turtle = malloc(sizeof(turtle_t));

	if (!turtle)
		die("Failed to allocate memory for Turtle");
	
	turtle->pen = 0;
	turtle->pos[0] = row;
	turtle->pos[1] = col;
	turtle->direction = RIGHT;

	return (turtle);
}

void move(size_t num, turtle_t *turtle, canvas_t *canvas)
{
	switch (turtle->direction)
	{
		case RIGHT:
			move_outwards(num, Y, turtle, canvas);
			break;
		case LEFT:
			move_inwards(num, Y, turtle, canvas);
			break;
		case UP:
			move_inwards(num, X, turtle, canvas);
			break;
		case DOWN:
			move_outwards(num, X, turtle, canvas);
			break;
	}
}

void turn_right(turtle_t *turtle)
{
	if (turtle->direction != UP)
                (turtle->direction)++;
        else
                turtle->direction = RIGHT;
}

void turn_left(turtle_t *turtle)
{
        if (turtle->direction != RIGHT)
                (turtle->direction)--;
        else
                turtle->direction = UP;
}

void turn_opposite(turtle_t *turtle)
{
	switch (turtle->direction)
	{
		case RIGHT:
			turtle->direction = LEFT;
			break;
		case LEFT:
			turtle->direction = RIGHT;
			break;
		case UP:
			turtle->direction = DOWN;
			break;
		case DOWN:
			turtle->direction = UP;
			break;
	}
}

void pen_up(turtle_t *turtle)
{
        turtle->pen = 0;
}

void pen_down(turtle_t *turtle)
{
        turtle->pen = 1;
}

void print_pos(size_t *pos, DIRECTION direction)
{
	printf("\nCurrently at pos: [%lu, %lu]\n", pos[0], pos[1]);

	if (direction == RIGHT)
		puts("Pointing right ➡️");
	if (direction == LEFT)
		puts("Pointing left ⬅️");
	if (direction == UP)
		puts("Pointing up ⬆️");
	if (direction == DOWN)
		puts("Pointing down ⬇️");
}
