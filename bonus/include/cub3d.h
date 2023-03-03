/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:13 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 23:15:23 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "parsing.h"
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# define TILE_SIZE 30
# define MINI_MAP_TILE_SIZE 10
# define ROTATION_SPEED 0.05235988
# define SCREENWIDTH 1500
# define SCREENHEIGHT 940
# define MINI_MAP_FACTOR 0.2
# define VIEW_ANGLE 1.04719767
# define WALL_HEIGHT 20
# define MINI_MAP_WIDTH 300
# define MINI_MAP_HEIGHT 188

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
	int				release_mouse;
	int				mouse_pos;
	int				check_shoot;
	int				count_shoot;
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
	SHOOT = 49,
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
	t_img_data		*mini_map;
	t_texture		*shoot_target;
	t_texture		**weapon;
	t_texture		**digit;
	t_texture		*amo;
	int				mouse_pos;

}					t_collect_data;

void				init_player(t_player *player, char **map);
void				init_map(t_map_info *map_file);
int					releaskey(int keycode, t_player *player);
int					presskey(int keycode, t_collect_data *data);
void				my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int					moveplayer(t_collect_data *data);
void				put_minimap(t_collect_data *data);
t_texture			*get_wall_texture(void *mlx, t_map_info *map_file);
void				castingrays(t_collect_data *data);
void				get_ray_direction(t_ray *ray);
void				draw(t_collect_data *data, t_ray *ray, int i);
int					check_wall(double x, double y, char **map);
double				normangle(double angle);
t_texture			*get_texture(t_mlx *mlx, char *file_name);
t_texture			**get_weapon_texture(t_mlx *mlx);
t_texture			**get_digit_texture(t_mlx *mlx);
void				ft_free_data(t_collect_data *data);
int					esc_hook(t_collect_data *data);
void				get_ray_direction(t_ray *ray);
double				normangle(double angle);
int					haswall_at(double x, double y, t_map_info *map);
double				getdis(t_player *player, double x, double y, bool check);
t_cordinates		find_horzstep(t_ray *ray);
t_cordinates		find_vertstep(t_ray *ray);
void				get_smallwallhit(t_ray *ray, t_player *player,
						double horzdistance, double vertdistance);
void				castingrays(t_collect_data *data);
t_cordinates		find_vertintercept(t_player *player, t_ray *ray);
t_cordinates		find_horzintercept(t_player *player, t_ray *ray);
double				find_horzintersection(t_player *player, t_ray *ray,
						t_map_info *map, bool gethorzwall);
double				find_vertintersection(t_player *player, t_ray *ray,
						t_map_info *map, bool getvertwall);
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
void				drawwallcolumn(t_img_data *img, t_cordinates _pos,
						double dy, int clr);
void				draw_wall(t_collect_data *data, t_cordinates offsset, int i,
						t_ray *ray);
void				draw(t_collect_data *data, t_ray *ray, int i);
int					releaskey(int keycode, t_player *player);
int					presskey(int keycode, t_collect_data *data);
void				put_weapon(t_mlx *mlx, t_texture **weapon, int *check_shoot,
						int count_shoot);
void				put_count_amo(t_mlx *mlx, t_texture **digit,
						int count_shoot);
void				put_all_texture(t_collect_data *data);
int					handle_mouse(int x, int y, t_collect_data *data);
int					mouse_press(int key, int x, int y, t_collect_data *data);
int					mouse_release(int key, int x, int y, t_collect_data *data);
void				collect_all_texture(t_collect_data *data);
void				__free_data(t_collect_data *data);
void				ft_free_data(t_collect_data *data);
void	drawline(t_collect_data *data, t_cordinates player_pos,
		t_cordinates ray_limit);
		void	put_player(t_collect_data *data);
		int	get_minimap_collor(char **map, t_cordinates pos);
		void	draw_minimap(t_collect_data *data, t_cordinates minimap_pos, \
	int i, int j);
	void	put_minimap(t_collect_data *data);

#endif