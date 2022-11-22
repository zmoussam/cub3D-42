#ifndef CUB3D_H
#define CUB3D_H
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
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
#define MAX_INT 2147483647

typedef struct ray
{
    double first_x;
    double first_y;
    double x;
    double y;
    int flag_vertical;
    int flag_horizental;
} t_ray;

typedef struct cub3d
{
    char *mlx;
    char *window;
    int p_x;
    int p_y;
    int i;
    char *space;
    char *wall;
    double angle;
    char *no;
    char *so;
    char *we;
    char *ea;
    int floor;
    int ceilling;
    char **map;
    t_ray ray_vertical;
    t_ray ray_horizental;
} t_cub3d;

typedef enum map_token
{
    EMPTY_LINE,
    INVALIDE_LINE,
    DIRECTION,
    RGB_COLOR,
    MAP,
} t_map_token;

//            < - - - - parsing - - - - >

char *get_texture_path(char *line);
void get_direction(t_cub3d *infos, char *line, int *count);
int parse_color(char **colors);
int check_if_empty(char *color);
int callcul_color(char *rgb_color);
void get_color(t_cub3d *infos, char *line, int *count);
int is_valid_rgb(int color);
void check_extention(char *file_name);
int get_token(char *line);
int get_infos(t_cub3d *infos, int fd);
int parsing(t_cub3d *infos, char *file_name);
void _error(char *error_name);
void free_colors(char **colors);
void free_map_list(t_list *map, int height);
int check_wals(char *border, int index);
int get_map(int fd, t_cub3d *infos, char *first_line);
int map_list_to_array(t_list *map, t_cub3d *infos, int height);
int get_map_content(int fd, t_list **map);

// < - - - - - - - - - - - - - - - - - - >
int movement(int key, t_cub3d *cub3d);
void add_image(t_cub3d *cub3d);
void ft_mov(t_cub3d *cub3d);
void init_maps(t_cub3d *cub3d);
void draw_line(t_cub3d *cub, int beginX, int beginY, int endX, int endY, int color);
void raycasting(t_cub3d *cub3d);

#endif
