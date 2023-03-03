/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:59:17 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 22:59:52 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	handle_mouse(int x, int y, t_collect_data *data)
{
	y = 0;
	if (data->player->release_mouse)
	{
		if (x > data->mouse_pos)
			data->player->turndirection = 1;
		else if (x < data->mouse_pos)
			data->player->turndirection = -1;
		data->mouse_pos = x;
	}
	return (0);
}

int	mouse_press(int key, int x, int y, t_collect_data *data)
{
	if (key == 1 && x >= 0 && x <= SCREENWIDTH && y >= 0 && y <= SCREENHEIGHT)
	{
		data->mouse_pos = x;
		data->player->release_mouse = 1;
	}
	return (0);
}

int	mouse_release(int key, int x, int y, t_collect_data *data)
{
	(void)x;
	(void)y;
	if (key == 1)
	{
		data->player->release_mouse = 0;
		data->player->turndirection = 0;
	}
	return (0);
}