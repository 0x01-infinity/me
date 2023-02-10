CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu11

turtle: exec_command.c move.c print_floor.c turn.c error_handling.c main.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm turtle