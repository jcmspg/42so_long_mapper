#ifndef SO_CUBE_MAPPER_H
#define SO_CUBE_MAPPER_H

#include "../includes/lib_ft/libft.h"
#include "../includes/minilibx-linux/mlx.h"

// STD LIBRARIES TO INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>



#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define TILE_SIZE 32

// STATUS MESSAGES
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define MAP_WIDTH 20
#define MAP_HEIGHT 15

typedef enum e_tile {
	TILE_EMPTY,
	TILE_WALL,
	TILE_PLAYER,
	TILE_EXIT,
	TILE_ENEMY
}	t_tile;



// Tile defs
#define TILE_WALL '1'
#define TILE_FLOOR '0'
#define TILE_PLAYER 'P'
#define TILE_ENEMY 'E'
#define TILE_EXIT 'X'
#define TILE_COLLECTIBLE 'C'

// struct to save map data and mlx
typedef struct s_mapper
{
    void *mlx;
    void *win;


    int map_rows;
    int map_cols;

    int map[MAP_HEIGHT][MAP_WIDTH];

    int cursor_x;
    int cursor_y;
} t_mapper;


int main(void);

// prototypes
void clean_exit(t_mapper *mapper);
int handle_key(int key, void *param);
void load_map(t_mapper *mapper, const char *filename);
void draw_map(t_mapper *mapper);
void handle_input(t_mapper *mapper);

#endif
