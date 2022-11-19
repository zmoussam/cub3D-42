#ifndef CUB3D_H
#define CUB3D_H
#include <stdio.h>
#include <math.h>
#include "libft/libft.h"
#include "mlx.h"
#define BLOCK 64
#define WIDTH 14 * 64
#define HIGHT 8 * 64
#define W 13
#define S 1
#define A 0
#define D 2
#define ESC 53
#define M_L 123
#define M_R 124
#define RETAION (5 * M_PI) / 180
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
    double angle;
} t_cub3d;

int movement(int key, t_cub3d *cub3d);
void add_image(t_cub3d *cub3d);
void ft_mov(t_cub3d *cub3d);
void init_maps(t_cub3d *cub3d);
void draw_line(t_cub3d *cub, int beginX, int beginY, int endX, int endY, int color);
void raycasting(t_cub3d *cub3d);

#endif
