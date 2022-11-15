#ifndef CUB3D_H
#define CUB3D_H
#include <stdio.h>
#include <math.h>
#include "libft/libft.h"
#include "mlx.h"
#define WIDTH 11 * 64
#define HIGHT 7 * 64
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
    char *p;
    int i;
} t_cub3d;

#endif