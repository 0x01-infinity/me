#include "main.h"
#include "turtle.h"

int main(void)
{
	char floor[FLOOR_SIZE][FLOOR_SIZE];
	size_t command;
	turtle_t *turtle = Turtle_new();

	initialize(floor);

	print_pos(turtle->pos, turtle->direction);
	puts("\nEnter commands");

	scanf("%lu", &command);

	while (command != 9)
	{
		executeCommand(command, turtle, floor);

		print_pos(turtle->pos, turtle->direction);
		scanf("%lu", &command);
	}
	free(turtle);

	return (0);
}
