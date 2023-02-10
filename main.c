#include "main.h"

int main(void)
{
	char floor[FLOOR_SIZE][FLOOR_SIZE];
	size_t pen = 0, pos[2] = {0, 0};
	size_t command;
	DIRECTION direction = RIGHT;

	initialize(floor);

	print_pos(pos, direction);
	puts("\nEnter commands");

	scanf("%lu", &command);

	while (command != 9)
	{
		executeCommand(command, &pen, pos, &direction, floor);

		print_pos(pos, direction);
		scanf("%lu", &command);
	}

	return (0);
}
