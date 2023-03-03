/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RaysCasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:13:48 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 23:33:36 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_cordinates	find_horzstep(t_ray *ray)
{
	t_cordinates	step;

	step.y = TILE_SIZE;
	step.y *= ray->isfacingup;
	step.x = TILE_SIZE / tan(ray->angle);
	if (ray->isfacingleft == -1 && step.x > 0)
		step.x *= -1;
	if (ray->isfacingright && step.x < 0)
		step.x *= -1;
	return (step);
}

t_cordinates	find_vertstep(t_ray *ray)
{
	t_cordinates	step;

	step.x = TILE_SIZE;
	step.x *= ray->isfacingleft;
	step.y = TILE_SIZE * tan(ray->angle);
	if (ray->isfacingup == -1 && step.y > 0)
		step.y *= -1;
	if (ray->isfacingdown && step.x < 0)
		step.y *= -1;
	return (step);
}

void	get_smallwallhit(t_ray *ray, t_player *player, double horzdistance,
		double vertdistance)
{
	ray->wallhitisvert = false;
	if (horzdistance <= vertdistance)
		ray->distancetowall = horzdistance * cos(ray->angle
				- player->viewangle);
	else if (horzdistance > vertdistance)
	{
		ray->wallhitisvert = true;
		ray->distancetowall = vertdistance * cos(ray->angle
				- player->viewangle);
	}
}

void	castingrays(t_collect_data *data)
{
	double	ray_angle;
	double	angle_inc;
	int		view_angle_degree;
	int		count;
	t_ray	ray;

	view_angle_degree = VIEW_ANGLE * 180 / M_PI;
	angle_inc = view_angle_degree * (M_PI / (180 * SCREENWIDTH));
	ray_angle = data->player->viewangle - (VIEW_ANGLE / 2);
	count = 0;
	while (count < SCREENWIDTH)
	{
		ray.angle = normangle(ray_angle);
		get_ray_direction(&ray);
		get_smallwallhit(&ray, data->player, \
		find_horzintersection(data->player, &ray, data->map_info, false), \
		find_vertintersection(data->player, &ray, data->map_info, false));
		draw(data, &ray, count);
		ray_angle += angle_inc;
		count++;
	}
}
