#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_d
{
    int     w;
    int     h;
    char    c;
} t_d;

typedef struct s_t
{
    char type;
    float x;
    float y;
    float w;
    float h;
    char c;
}t_t;

int in_r(t_t table, int x, int y)
{
    return (table.x <= x && x <= table.w + table.x && \
            table.y <= y && y <= table.h + table.y);
}

int in_b(t_t table, int x, int y)
{
    return (table.x + 1 > x || x > table.w + table.x - 1 || \
            table.y + 1 > y || y > table.h + table.y - 1);
}

void draw_canvas(char *canvus, t_t table, t_d data)
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
				canvus[y * data.w + x] = table.c;
			if (table.type == 'R' && in_r(table, x, y))
				canvus[y * data.w + x] = table.c;
		}
	}
}

void print_canvas(char *canvus, t_d data)
{
    int x;
    int y;

    y = -1;
    while (++y < data.h)
    {
        x = -1;
        while (++x < data.w)
            write(1, &canvus[y * data.w + x], 1);
        write(1, "\n", 1);
    }
}

int draw(FILE *file)
{
    t_d data;
    t_t table;
    int ret;
    char *canvus;

    ret = 0;
    if (fscanf(file, "%d %d %c\n", &data.w, &data.h, &data.c) != 3)
        return (1);
    if (data.w <= 0 || data.w > 300 || data.h <= 0 || data.h > 300)
        return (1);
    if (!(canvus = malloc(data.w * data.h)))
        return (1);
    memset(canvus, data.c, data.w * data.h);
    while ((ret = fscanf(file, "%c %f %f %f %f %c\n", \
            &table.type, &table.x, &table.y, &table.w, &table.h, &table.c)) == 6)
    {
        if (table.w <= 0 || table.h <= 0 || !(table.type == 'R' || table.type == 'r'))
        {
            free(canvus);
            return (1);
        }
        draw_canvas(canvus, table, data);
    }
    if (ret != EOF)
    {
        free(canvus);
        return (1);
    }
    print_canvas(canvus, data);
    free(canvus);
    return (0);
}

int main (int ac, char **av)
{
    FILE *file;

    file = NULL;
    if (ac == 2)
    {
        if(!(file = fopen(av[1], "r")) || draw(file))
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