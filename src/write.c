#include "canvas.h"
#include "main.h"

void write_canvas(canvas_t *canvas)
{
        char filename[11];
        size_t i, j;

        printf("%s", "Enter filename to save canvas: ");
        scanf("%10s", filename);

        FILE *output = fopen(filename, "w");
        if (!output)
                die("Failed to open file to write to");

        for (i = 0; i < canvas->rows; i++)
        {
                for (j = 0; j < canvas->cols; j++)
                        fputc(canvas->floor[i][j], output);
                fputc('\n', output);
        }
        fclose(output);

        printf("%s%s\n", "Canvas successfully written to ", filename);
}
