#ifndef CUB3D_H
#define CUB3D_H
#include <stdio.h>
#include <math.h>
#include "libft/libft.h"
#include "mlx.h"
#define BLOCK 64
#define WIDTH 42 * 64
#define HIGHT 12 * 64
#define W 13
#define S 1
#define A 0
#define D 2
#define ESC 53

typedef struct cub3d
{
    char **map;
    char *mlx;
    char *window;
    int p_x;
    int p_y;
    int i;
    char *space;
    char *wall;
} t_cub3d;

#endif