/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniPlayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:12:46 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 23:13:14 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	drawline(t_collect_data *data, t_cordinates player_pos,
		t_cordinates ray_limit)
{
	t_cordinates	dest;
	t_cordinates	pos;
	t_cordinates	inc;
	int				steps;
	int				i;

	dest.x = (ray_limit.x - player_pos.x);
	dest.y = (ray_limit.y - player_pos.y);
	if (fabs(dest.x) > fabs(dest.y))
		steps = fabs(dest.x);
	else
		steps = fabs(dest.y);
	inc.x = dest.x / (float)steps;
	inc.y = dest.y / (float)steps;
	pos.x = player_pos.x;
	pos.y = player_pos.y;
	i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_put(data->mini_map, pos.x, pos.y, 0x00FF0000);
		pos.x = pos.x + inc.x;
		pos.y = pos.y + inc.y;
		i++;
	}
}

void	put_player(t_collect_data *data)
{
	t_cordinates	player_pos;
	t_cordinates	ray_limit;
	t_ray			ray;
	double			angle_inc;
	int				count;

	player_pos.x = MINI_MAP_WIDTH / 2;
	player_pos.y = MINI_MAP_HEIGHT / 2;
	angle_inc = VIEW_ANGLE / 15;
	ray.angle = data->player->viewangle - (VIEW_ANGLE / 2);
	count = 0;
	while (count < 15)
	{
		get_ray_direction(&ray);
		ray_limit.x = player_pos.x + (cos(ray.angle) * 10);
		ray_limit.y = player_pos.y + (sin(ray.angle) * 10);
		drawline(data, player_pos, ray_limit);
		ray.angle += angle_inc;
		count++;
	}
}