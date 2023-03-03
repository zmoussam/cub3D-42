/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:13 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 23:11:05 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "parsing.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# define TILE_SIZE 30
# define ROTATION_SPEED 0.05235988
# define SCREENWIDTH 1500
# define SCREENHEIGHT 940
# define MINI_MAP_FACTOR 0.2
# define VIEW_ANGLE 1.04719767
# define WALL_HEIGHT 20

typedef struct s_img_data
{
	void			*img;
	char			*addr;
	int				*int_addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img_data;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	t_img_data		*img;
}					t_mlx;

typedef struct s_cordinates
{
	double			x;
	double			y;
}					t_cordinates;

typedef struct s_player_data
{
	t_cordinates	position;
	double			movespeed;
	double			viewangle;
	double			rotationspeed;
	int				movesleft_or_right;
	int				turndirection;
	int				walkdirection;
}					t_player;

typedef enum keys
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	TURN_LEFT = 123,
	TURN_RIGHT = 124,
	ESC = 53,
}					t_keys;

typedef struct s_texture
{
	t_img_data		*info;
	int				_width;
	int				_heigth;
}					t_texture;

typedef struct s_ray
{
	double			angle;
	double			distancetowall;
	int				isfacingdown;
	int				isfacingup;
	int				isfacingleft;
	int				isfacingright;
	t_cordinates	horzwallhit;
	t_cordinates	vertwallhit;
	bool			wallhitisvert;
	double			wallstripheight;
}					t_ray;

typedef struct s_collect_data
{
	t_player		*player;
	t_mlx			*mlx;
	t_map_info		*map_info;
	t_texture		*wall;

}					t_collect_data;

void				init_player(t_player *player, char **map);
void				init_map(t_map_info *map_file);
int					releaskey(int keycode, t_player *player);
int					presskey(int keycode, t_collect_data *data);
void				my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int					moveplayer(t_collect_data *data);
void				put_minimap(t_collect_data *data);
t_texture			*get_texture_data(void *mlx, t_map_info *map_file);
void				castingrays(t_collect_data *data);
void				get_ray_direction(t_ray *ray);
void				draw(t_collect_data *data, t_ray *ray, int i);
int					check_wall(double x, double y, char **map);
double				normangle(double angle);
void				ft_free_data(t_collect_data *data);
int					esc_hook(t_collect_data *data);
void				get_ray_direction(t_ray *ray);
double				normangle(double angle);
double				getdis(t_player *player, double x, double y, bool check);
t_cordinates		find_horzstep(t_ray *ray);
t_cordinates		find_vertstep(t_ray *ray);
void				get_smallwallhit(t_ray *ray, t_player *player,
						double horzdistance, double vertdistance);
void				castingrays(t_collect_data *data);
int					haswall_at(double x, double y, t_map_info *map);
t_cordinates		find_vertintercept(t_player *player, t_ray *ray);
t_cordinates		find_horzintercept(t_player *player, t_ray *ray);
double				find_horzintersection(t_player *player, t_ray *ray,
						t_map_info *map, bool gethorhit);
double				find_vertintersection(t_player *player, t_ray *ray,
						t_map_info *map, bool getverthit);
void				draw(t_collect_data *data, t_ray *ray, int i);
void				draw_wall(t_collect_data *data, t_cordinates offsset, int i,
						t_ray *ray);
void				drawwallcolumn(t_img_data *img, t_cordinates _pos,
						double dy, int clr);
void				my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void				put_west_east_texture(t_collect_data *data,
						t_cordinates offsset, t_ray *ray,
						t_cordinates cordinates);
void				put_north_south_texture(t_collect_data *data,
						t_cordinates offsset, t_ray *ray,
						t_cordinates cordinates);
void	_put_pixel_from_texture_to_wall(t_collect_data *data,
										t_cordinates offsset,
										t_ray *ray,
										t_cordinates cordinates);
double				get_ofssets_x(t_texture *texture, t_ray *ray);
int					releaskey(int keycode, t_player *player);
int					presskey(int keycode, t_collect_data *data);
int					check_wall(double x, double y, char **map);

#endif
