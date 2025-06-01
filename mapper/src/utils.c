#include "so_cube_mapper.h"

void draw_tile(void *mlx, void *win, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    while (i < TILE_SIZE)
    {
        j =0;
        while (j < TILE_SIZE)
        {
            mlx_pixel_put(mlx, win, x + i, y + j, color);
             j++;
        }
        i++;
    }
}

void draw_map(t_mapper *mapper)
{
    int i;
    int j;

    i = 0;
    while (i < MAP_HEIGHT)
    {
        j = 0;
        while (j < MAP_WIDTH)
        {
            if (mapper->map[i][j] == 1)
                draw_tile(mapper->mlx, mapper->win, j * TILE_SIZE, i * TILE_SIZE, 0xFFFFFF);
            else if (mapper->map[i][j] == 2)
                draw_tile(mapper->mlx, mapper->win, j * TILE_SIZE, i * TILE_SIZE, 0x00FF00);
            j++;
        }
        i++;
    }
}

void draw_player(void *mlx, void *win, int x, int y)
{
    draw_tile(mlx, win, x * TILE_SIZE, y * TILE_SIZE, 0xFF0000);
}

void draw_exit(void *mlx, void *win, int x, int y)
{
    draw_tile(mlx, win, x * TILE_SIZE, y * TILE_SIZE, 0x0000FF);
}

void draw_wall(void *mlx, void *win, int x, int y)
{
    draw_tile(mlx, win, x * TILE_SIZE, y * TILE_SIZE, 0x000000);
}

void draw_floor(void *mlx, void *win, int x, int y)
{
    draw_tile(mlx, win, x * TILE_SIZE, y * TILE_SIZE, 0x808080);
}

void draw_item(void *mlx, void *win, int x, int y)
{
    draw_tile(mlx, win, x * TILE_SIZE, y * TILE_SIZE, 0xFFFF00);
}

void clean_exit(t_mapper *mapper)
{
    mlx_destroy_window(mapper->mlx, mapper->win);
    mlx_destroy_display(mapper->mlx);
    free(mapper->mlx);
    exit(0);
}

int handle_key(int keycode, void *param)
{
    t_mapper *mapper = (t_mapper *)param;

    if (keycode == 65307) // ESC
        clean_exit(mapper);

    // handle other keys here

    return (0);
}
