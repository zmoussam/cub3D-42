/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:13 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/11 22:52:51 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D__
#define __CUB3D__
    
typedef struct s_player_data
{
    double x;
    double y;
    int radius;
    int movespeed;
    double rotationangle;
    double rotationspeed;
    int turndirection;
    int walkdirection;
    t_data *img;
    void *mlx;
    void *mlx_win;
} t_player_data;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int releaskey(int keycode, t_player_data *player);
int presskey(int keycode, t_player_data *player);
int key_hook(t_player_data *player);

#endif