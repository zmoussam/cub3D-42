/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:13 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/28 06:27:32 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef __CUB3D__
#define __CUB3D__

#include <math.h>
#define TILE_SIZE 30
#define MINI_MAP_TILE_SIZE 10
#define ROTATION_SPEED 4 * (M_PI / 180)
#define SCREENWIDTH 1500
#define SCREENHEIGHT 940
#define MINI_MAP_FACTOR 0.2
#define VIEW_ANGLE 60 * M_PI / 180
#define WALL_HEIGHT 20
#define MINI_MAP_WIDTH SCREENWIDTH * MINI_MAP_FACTOR
#define MINI_MAP_HEIGHT SCREENHEIGHT * MINI_MAP_FACTOR
#include<mlx.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int 	*int_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_mlx
{
    void *mlx;
    void *mlx_win;
    t_img_data *img;
} t_mlx;

typedef struct s_cordinates{
    double x;
    double y;
} t_cordinates;

typedef struct s_map_info
{
    char *no;
    char *so;
    char *we;
    char *ea;
    int c_floor;
    int c_ceiling;
    char **map;
} t_map_info;


typedef struct s_player_data
{
    t_cordinates position;
    int release_mouse;
    int mouse_pos;
    int check_shoot;
    int count_shoot;
    double movespeed;
    double viewangle;
    double rotationspeed;
    int movesleft_or_right;
    int turndirection;
    int walkdirection;
    
} t_player;

typedef enum keys{
    KEY_UP = 13,
    KEY_DOWN = 1,
    KEY_LEFT = 0,
    KEY_RIGHT = 2,
    TURN_LEFT = 123,
    TURN_RIGHT = 124,
    ESC = 53,
    SHOOT = 49,
} t_keys;

typedef struct s_texture
{
    t_img_data *info;
    int _width;
    int _heigth;
}t_texture;

typedef struct s_ray{
    double angle;
    double distancetowall;
    int isfacingdown;
    int isfacingup;
    int isfacingleft;
    int isfacingright;
    t_cordinates horzwallhit;
    t_cordinates vertwallhit;
    bool wallhitisvert;
}t_ray;
typedef struct s_collect_data
{
    t_player *player;
    t_mlx *mlx;
    t_map_info *map_info;
    t_texture *texture;
    t_img_data *mini_map;
    t_texture *shooting_target;
    t_texture **weapon;
    t_texture **digit;
    t_texture *amo;
    
} t_collect_data;

void        init_player(t_player *player, char **map);
void        init_map(t_map_info *map_file);
int         releaskey(int keycode, t_player *player);
int         presskey(int keycode, t_player *player);
void        my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int         moveplayer(t_collect_data *data);
void        put_minimap(t_collect_data *data);
t_texture   *get_wall_texture(void* mlx, t_map_info *map_file);
void        castingrays(t_collect_data *data);
void        get_ray_direction(t_ray *ray);
void        draw(t_collect_data *data, t_ray *ray, int i);
int         check_wall(double x, double y, char **map);
double      normangle(double angle);

#endif