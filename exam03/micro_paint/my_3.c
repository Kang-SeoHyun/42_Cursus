#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_d
{
    int w;
    int h;
    char c;
}               t_d;

typedef struct s_t
{
    char type;
    float x;
    float y;
    float w;
    float h;
    char  c;
}                   t_t;

int in_r(t_t table, int x, int y)
{
    return (table.x <= x && x <= table.x + table.w \
        && table.y <= y && y <= table.y + table.h);
}

int in_b(t_t table, int x, int y)
{
    return (table.x + 1 > x || x > table.x + table.w - 1 \
        || table.y + 1> y || y > table.y + table.h - 1);
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
            if (table.type == 'r' && in_r(table, x, y) && in_b(table, x, y))
                canvas[data.w * y + x] = table.c;
            if (table.type == 'R' && in_r(table, x, y))
                canvas[data.w * y + x] = table.c;
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
            write(1, &canvas[data.w * y+ x], 1);
        write(1, "\n", 1);
    }
}

int draw_file(FILE *file)
{
    t_d data;
    t_t table;
    int ret;
    char *canvas;

    ret = 0;
    //이부분
    if (fscanf(file, "%d %d %c\n", &data.w, &data.h, &data.c) != 3)
        return (1);
    if (!(0 < data.w && data.w <= 300 && 0 < data.h && data.h <= 300))
        return (1);
    if (!(canvas = malloc(data.w * data.h)))
        return (1);
    memset(canvas, data.c, data.w * data.h);
    while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &table.type, \
            &table.x, &table.y, &table.w, &table.h, &table.c)) == 6)
            {
                if (table.w <= 0 || table.h <= 0 || (table.type != 'r' && table.type != 'R'))
                {
                    free (canvas);
                    return (1);
                }
                draw(canvas, table, data);
            }
    if (ret != EOF)
    {
        free (canvas);
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
            write(1, "Error: Operation file corrupted\n", 32);
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