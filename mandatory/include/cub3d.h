/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:13 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/28 03:32:04 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef __CUB3D__
#define __CUB3D__

#include <math.h>
#define TILE_SIZE 30
#define ROTATION_SPEED 3 * (M_PI / 180)
#define SCREENWIDTH 1500
#define SCREENHEIGHT 940
#define MINI_MAP_FACTOR 0.2
#define VIEW_ANGLE 60 * M_PI / 180
#define WALL_HEIGHT 20
#include "../gnl/get_next_line.h"
#include "../libft_zack/libft.h"
#include<mlx.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include <fcntl.h>
#include <limits.h>

typedef struct s_index
{
	size_t i;
	size_t j;
}t_index;

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
    
} t_collect_data;

typedef struct s_abtmap
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			**map;
	int				has_no;
	int				has_so;
	int				has_we;
	int				has_ea;
	int				maplines;
	int				lenghtlines;
	int				has_f;
	int				has_c;
	int				floor;
	int				ceilling;
	int				lineindex;
	size_t				maxlenmap;

}					t_abtmap;

void        init_player(t_player *player, char **map);
void        init_map(t_map_info *map_file);
int         releaskey(int keycode, t_player *player);
int         presskey(int keycode, t_player *player);
void        my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int         moveplayer(t_collect_data *data);
void        put_minimap(t_collect_data *data);
t_texture   *get_texture_data(void* mlx, t_map_info *map_file);
void        castingrays(t_collect_data *data);
void        get_ray_direction(t_ray *ray);
void        draw(t_collect_data *data, t_ray *ray, int i);
int         check_wall(double x, double y, char **map);
double      normangle(double angle);

// parsing
char				*remove_caract(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_check_cub(char *filename);
int					countline(char *file);
int					ft_reading_maps(t_abtmap *jeu, char *file);
char				**remplir_tableau(void);
void				initializer(t_abtmap *game);
void				free_tab(char **tab, int size);
int					check_intern_map(char *clean_ptr, t_abtmap *game);
void				parse_direction(t_abtmap *game, char *line);
void				ea_direct(t_abtmap *game, char *line);
void				no_direct(t_abtmap *game, char *line);
void				we_direct(t_abtmap *game, char *line);
void				so_direct(t_abtmap *game, char *line);
char				*ft_strcpy(char *dest, char *src);
char				*remove_prefix(char *line, char *prefix);
void				memory_error(void);
void				parse_color(t_abtmap *game, char *cleanline);
int					receive_rgb_color(char *color);
int					isalldigits(const char *s);
int					rgb_converter(char **rgbclr);
int					parse_map(t_abtmap *game, char *first_line, int fd);
int					valid_n(char **map, size_t i, size_t j);
int					valid_e(char **map, size_t i, size_t j);
int					valid_s(char **map, size_t i, size_t j, t_abtmap *game);
int					valid_w(char **map, size_t i, size_t j);
int					check_valid_map(t_index index, char **map, t_abtmap *game, int *counter);
int					checkmap(t_abtmap *game);
int					check_path(t_abtmap *game, char *cleanline);
void				check_retvalue(int retvalue, char *clean_ptr, t_abtmap *game);
int 				base_parsing(char *file, t_abtmap *game);
void 				findmaxline(t_abtmap *game);
char 				*fillwithspace(char *line, t_abtmap *game);
char 				*onlyspaces(int diff);
int 				numberofgamma(char *pathcolor);
int 				checkgamma(char *pathcolor);

#endif