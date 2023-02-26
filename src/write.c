#include "main.h"

void write_canvas(canvas_t *canvas, char *filename)
{
        size_t i, j;

        FILE *output = fopen(filename, "w+");
        if (!output)
                die("Failed to open file to write to");

        for (i = 0; i < canvas->rows; i++)
        {
                for (j = 0; j < canvas->cols; j++)
                        fputc(canvas->floor[i][j], output);
                fputc('\n', output);
        }
        fclose(output);

        printf("%s%s\n\n", "Canvas successfully written to -> ", filename);
}
