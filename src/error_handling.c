#include "main.h"

size_t unsigned_sub(size_t a, size_t b)
{
	if (a < b)
		die("Unsigned integer subtraction causing negative value");
	else
		return (a - b);
	
	return (0);
}

size_t unsigned_add(size_t a, size_t b)
{
	if (UINT_MAX - a < b)
		die("Unsigned integer addition causing wrapping / overflow");
	else
		return (a + b);
	
	return (0);
}

void positive_bound(size_t point, size_t *pos, size_t size, canvas_t *canvas)
{
	if (point >= size)
	{
		printf("Out of the bounds of floor [%lu, %lu]\n", canvas->rows, canvas->cols);
		
		if (pos[0] >= canvas->rows)
			pos[0] = canvas->rows - 1;
		
		if (pos[1] >= canvas->cols)
			pos[1] = canvas->cols - 1;
		
		printf("Position adjusted to [%lu, %lu]\n", pos[0], pos[1]);
	}
}

size_t negative_bound(size_t point, size_t b, size_t *pos)
{
	if (point < b)
	{
		puts("\nNegative index detected. Out of bounds of floor. Least index allowed is 0.");

		if ((int) (pos[0] - b) < 0)
			pos[0] = 0;
		else if ((int) (pos[1] - b) < 0)
			pos[1] = 0;
		
		printf("Position adjusted to [%lu, %lu]\n", pos[0], pos[1]);
		return (1);
	}

	return (0);
}

void die(const char *message)
{
	if (errno)
		perror(message);
	else
		printf("\n%s%s\n", "Error: ", message);
	exit (1);
}

void flush()
{
	char c;

	while (1)
	{
		c = fgetc(stdin);
		if (c == EOF || c == '\n')
			break;
	}
}