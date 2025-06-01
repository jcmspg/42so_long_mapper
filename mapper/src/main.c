#include "so_cube_mapper.h"

int main(void)
{
    t_mapper mapper;
    // t_tile map[MAP_HEIGHT][MAP_WIDTH];


    mapper.mlx = mlx_init();
    if (!mapper.mlx)
        return (EXIT_FAILURE);

    mapper.win=mlx_new_window(mapper.mlx, WIN_WIDTH, WIN_HEIGHT, "map editor");
    if (!mapper.win)
        return (EXIT_FAILURE);


    draw_map(&mapper);

    //keyloop to close
    mlx_key_hook(mapper.win, handle_key, &mapper);

    mlx_loop(mapper.mlx);


    return (EXIT_SUCCESS);
}
