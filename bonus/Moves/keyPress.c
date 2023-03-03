/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyPress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:45:07 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 23:02:18 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	esc_hook(t_collect_data *data)
{
	printf("game over!!!\n");
	ft_free_data(data);
	mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
	exit(0);
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
	if (keycode == SHOOT)
	{
		data->player->check_shoot = 1;
		if (data->player->count_shoot > 0)
			data->player->count_shoot--;
	}
	if (keycode == ESC)
		esc_hook(data);
	return (0);
}