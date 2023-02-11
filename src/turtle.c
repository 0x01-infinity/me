#include "turtle.h"

void move(size_t num, turtle_t *turtle, char floor[][FLOOR_SIZE])
{
	switch (turtle->direction)
	{
		case RIGHT:
			move_right(num, turtle, floor);
			break;
		case LEFT:
			move_left(num, turtle, floor);
			break;
		case UP:
			move_up(num, turtle, floor);
			break;
		case DOWN:
			move_down(num, turtle, floor);
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

turtle_t *Turtle_new(void)
{
	turtle_t *turtle = malloc(sizeof(turtle_t));

	if (!turtle)
		die("Failed to allocate memory for Turtle");
	
	turtle->pen = 0;
	turtle->pos[0] = 0;
	turtle->pos[1] = 0;
	turtle->direction = RIGHT;

	return (turtle);
}
