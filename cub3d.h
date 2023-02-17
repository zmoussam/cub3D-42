/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:13 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/17 18:56:53 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D__
#define __CUB3D__

#define MAPWIDTH 17
#define MAPHEIGHT 17
#define TILE_SIZE 50
#define SCREENWIDTH MAPWIDTH * TILE_SIZE
#define SCREENHEIGHT MAPHEIGHT * TILE_SIZE
#define PI 3.14159265
#define VIEW_ANGLE 60 * PI / 180
#define MINI_MAP_FACTOR 0.2
#include<mlx.h>
#include <math.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_cordinates{
    double x;
    double y;
} t_cordinates;

typedef struct s_player_data
{
    t_cordinates position;
    int radius;
    int movespeed;
    double viewangle;
    double rotationspeed;
    int movesleft_or_right;
    int turndirection;
    int walkdirection;
    t_img_data *img;
    void *mlx;
    void *mlx_win;
} t_player_data;

typedef enum keys{
    KEY_UP = 13,
    KEY_DOWN = 1,
    KEY_LEFT = 0,
    KEY_RIGHT = 2,
    TURN_LEFT = 123,
    TURN_RIGHT = 124,
} t_keys;


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

extern int worldMap[MAPWIDTH][MAPHEIGHT];

int     releaskey(int keycode, t_player_data *player);
int     presskey(int keycode, t_player_data *player);
int     moveplayer(t_player_data *player);
void    my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void    put_player(t_player_data *player);
void    put_map(t_player_data *player);
void    drawline(t_player_data *player, double x, double y);
void    draw_view_angle(t_player_data *player);
int     check_wals(double x, double y, int radius);

#endif