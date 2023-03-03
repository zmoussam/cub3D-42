/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:03:44 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 23:27:49 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_ray_direction(t_ray *ray)
{
	if (ray->angle > 0 && ray->angle < M_PI)
	{
		ray->isfacingdown = 1;
		ray->isfacingup = 1;
	}
	else
	{
		ray->isfacingdown = 0;
		ray->isfacingup = -1;
	}
	if (ray->angle < (M_PI / 2) || ray->angle > (3 * M_PI / 2))
	{
		ray->isfacingright = 1;
		ray->isfacingleft = 1;
	}
	else
	{
		ray->isfacingright = 0;
		ray->isfacingleft = -1;
	}
}

double	normangle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = angle + (2 * M_PI);
	return (angle);
}

double	getdis(t_player *player, double x, double y, bool check)
{
	if (!check)
		return (INT_MAX);
	else
		check = 0;
	return (sqrt(((x - player->position.x) * (x - player->position.x)) + \
			((y - player->position.y) * (y - player->position.y))));
}
