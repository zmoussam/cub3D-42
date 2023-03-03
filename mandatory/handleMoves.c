/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleMoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:35:38 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 17:32:47 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	check_wall(double x, double y, char **map)
{
	int	i;
	int	j;
	int	radius;

	i = x;
	j = y;
	radius = 5;
	while (i < radius + x)
	{
		j = y;
		while (j < radius + y)
		{
			if (map[(int)(j / TILE_SIZE)][(int)(i / TILE_SIZE)] == '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	releaskey(int keycode, t_player *player)
{
	if (keycode == KEY_LEFT)
		player->movesleft_or_right = 0;
	if (keycode == KEY_RIGHT)
		player->movesleft_or_right = 0;
	if (keycode == KEY_DOWN)
		player->walkdirection = 0;
	if (keycode == KEY_UP)
		player->walkdirection = 0;
	if (keycode == TURN_LEFT)
		player->turndirection = 0;
	if (keycode == TURN_RIGHT)
		player->turndirection = 0;
	return (0);
}

int	presskey(int keycode, t_collect_data *data)

{
	if (keycode == KEY_LEFT)
		data->player->movesleft_or_right = -1;
	if (keycode == KEY_RIGHT)
		data->player->movesleft_or_right = +1;
	if (keycode == KEY_DOWN)
		data->player->walkdirection = -1;
	if (keycode == KEY_UP)
		data->player->walkdirection = +1;
	if (keycode == TURN_LEFT)
		data->player->turndirection = -1;
	if (keycode == TURN_RIGHT)
		data->player->turndirection = +1;
	if (keycode == ESC)
	{
		write(1, "game over!!!\n", 13);
		ft_free_data(data);
		exit(-1);
	}
	return (0);
}

void diagonale_move(t_collect_data *data)
{
	int movestep;
	double tmpangle;
	double next_x;
	double next_y;
	
	movestep = data->player->movespeed;
	if (data->player->walkdirection == -1)
		tmpangle = data->player->viewangle + \
		(data->player->movesleft_or_right * M_PI / 2);
	else 
		tmpangle = data->player->walkdirection * (data->player->viewangle + \
		(data->player->movesleft_or_right * M_PI / 4));
	next_x = data->player->position.x + (cos(tmpangle) * movestep);
	next_y = data->player->position.y + (sin(tmpangle) * movestep);
	if (!check_wall(next_x, next_y, data->map_info->map))
	{
		data->player->position.x = next_x;
		data->player->position.y = next_y;
	}
}

void direct_move(t_collect_data *data)
{
	int movestep;
	double next_x;
	double next_y;
	
	movestep = data->player->walkdirection * data->player->movespeed;
	next_x = data->player->position.x + \
	(cos(data->player->viewangle) * movestep);
	next_y = data->player->position.y + \
	(sin(data->player->viewangle) * movestep);
	if (!check_wall(next_x, next_y, data->map_info->map))
	{
		data->player->position.x = next_x;
		data->player->position.y = next_y;
	}
}

void neutre_move(t_collect_data *data)
{
	int movestep;
	double next_x;
	double next_y;
	double left_or_right_angle;
	
	left_or_right_angle = 0;
	movestep = data->player->movespeed;
	left_or_right_angle = data->player->movesleft_or_right * M_PI / 2;
	next_x = data->player->position.x + (cos(data->player->viewangle + \
	left_or_right_angle) * movestep);
	next_y = data->player->position.y + (sin(data->player->viewangle + \
	left_or_right_angle) * movestep);
	if (!check_wall(next_x, next_y, data->map_info->map))
	{
		data->player->position.x = next_x;
		data->player->position.y = next_y;
	}
}

int	moveplayer(t_collect_data *data)
{
	data->player->viewangle += data->player->turndirection \
	* data->player->rotationspeed;
	if (data->player->walkdirection != 0 && \
	data->player->movesleft_or_right != 0)
		diagonale_move(data);
	else if (data->player->walkdirection != 0)
		direct_move(data);
	else if (data->player->movesleft_or_right != 0)
		neutre_move(data);
	mlx_clear_window(data->mlx->mlx, data->mlx->mlx_win);
	castingrays(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win,
			data->mlx->img->img, 0, 0);
	return (1);
}