#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

typedef struct s_d
{
    int w;
    int h;
    char c;
}           t_d;

typedef struct s_t
{
    char type;
    float x;
    float y;
    float r;
    char c;
}              t_t;

int in_r(t_t table, int x, int y)
{
    return (sqrtf(powf(table.x - x, 2) + powf(table.y - y, 2)) <= table.r);
}
int in_b(t_t table, int x, int y)
{
    return (sqrtf(powf(table.x - x, 2) + powf(table.y - y, 2)) > table.r - 1);
}
void draw(char *canvas, t_t table, t_d data)
{
    int x;
    int y;

    y = -1;
    while (++y < data.h)
    {
        x = -1;
        while (++x < data.w)
        {
            if (table.type == 'c' && in_r(table, x, y) && in_b(table, x, y))
                canvas[y * data.w + x] = table.c;
            if (table.type == 'C' && in_r(table, x, y))
                canvas[y * data.w + x] = table.c;
        }
    }
}

void print_canvas(char *canvas, t_d data)
{
    int x;
    int y;

    y = -1;
    while (++y < data.h)
    {
        x = -1;
        while (++x < data.w)
            write(1, &canvas[y * data.w + x], 1);
        write(1, "\n", 1);
    }
}

int draw_file(FILE *file)
{
    t_d     data;
    t_t     table;
    int     ret;
    char    *canvas;

    ret = 0;
    if(fscanf(file, "%d %d %c\n", &data.w, &data.h, &data.c) != 3)
        return (1);
    if (data.w <= 0 || 300 < data.w || data.h <= 0 || 300 < data.h)
        return (1);
    if (!(canvas = malloc(data.w * data.h)))
        return (1);
    memset(canvas, data.c, data.w * data.h);
    while ((ret = fscanf(file, "%c %f %f %f %c\n", &table.type, &table.x, &table.y, &table.r, &table.c)) == 5)
    {
        if (table.r <= 0 || (table.type != 'c' && table.type != 'C'))
        {
            free(canvas);
            return (1);
        }
        draw(canvas, table, data);
    }
    if (ret != EOF)
    {
        free(canvas);
        return (1);
    }
    print_canvas(canvas, data);
    free(canvas);
    return (0);
}

int main(int ac, char **av)
{
    FILE *file;

    file = NULL;
    if (ac == 2)
    {
        if (!(file = fopen(av[1], "r")) || draw_file(file))
        {
            write(1,"Error: Operation file corrupted\n", 32);
            return (1);
        }
    }
    else
    {
        write(1, "Error: argument\n", 16);
        return (1);
    }
    return (0);
}
