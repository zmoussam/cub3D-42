/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RaysCasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:13:48 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 04:27:44 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

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

t_cordinates	find_vertintercept(t_player *player, t_ray *ray)
{
	t_cordinates	intercept;

	intercept.x = floor(player->position.x / TILE_SIZE) * TILE_SIZE
		+ (ray->isfacingright * TILE_SIZE);
	intercept.y = player->position.y + (intercept.x - player->position.x)
		* tan(ray->angle);
	return (intercept);
}

t_cordinates	find_horzintercept(t_player *player, t_ray *ray)
{
	t_cordinates	intercept;

	intercept.y = floor(player->position.y / TILE_SIZE) * TILE_SIZE
		+ (ray->isfacingdown * TILE_SIZE);
	intercept.x = player->position.x + (intercept.y - player->position.y)
		/ tan(ray->angle);
	return (intercept);
}

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

int	haswall_at(double x, double y, t_map_info *map)
{
	if (x < 0 || x > map->maxlenmap * TILE_SIZE || y < 0 || y > map->maplines
		* TILE_SIZE)
		return (1);
	if ((int)(x / TILE_SIZE) >= (int)ft_strlen(map->map[(int)(y / TILE_SIZE)]))
	{
		return (1);
	}
	return (map->map[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1');
}

double	get_distance(t_player *player, double x, double y, bool check)
{
	if (!check)
		return (INT_MAX);
	else
		check = 0;
	return (sqrt(((x - player->position.x) * (x - player->position.x)) +
					((y - player->position.y) * (y - player->position.y))));
}
double	find_horzintersection(t_player *player, t_ray *ray, t_map_info *map, bool gethorzwall)
{
	t_cordinates	step;
	short			check_isfacingup;

	check_isfacingup = 0;
	ray->horzwallhit = find_horzintercept(player, ray);
	step = find_horzstep(ray);
	if (ray->isfacingup == -1)
		check_isfacingup = 1;
	while (ray->horzwallhit.x >= 0 && ray->horzwallhit.x <= (map->maxlenmap - 1) * \
	TILE_SIZE && ray->horzwallhit.y >= 0 && ray->horzwallhit.y <= (map->maplines - 1) * TILE_SIZE)
	{
		if (haswall_at(ray->horzwallhit.x, ray->horzwallhit.y - check_isfacingup, map))
		{
			gethorzwall = true;
			break ;
		}
		else
		{
			ray->horzwallhit.x += step.x;
			ray->horzwallhit.y += step.y;
		}
	}
	return (get_distance(player, ray->horzwallhit.x, ray->horzwallhit.y, gethorzwall));
}

double	find_vertintersection(t_player *player, t_ray *ray, t_map_info *map, \
	bool getvertwall)
{
	t_cordinates	step;
	short			check_isfacingleft;
	
	check_isfacingleft = 0;
	ray->vertwallhit = find_vertintercept(player, ray);
	step = find_vertstep(ray);
	if (ray->isfacingleft == -1)
		check_isfacingleft = 1;
	while (ray->vertwallhit.x >= 0 && ray->vertwallhit.x < (map->maxlenmap - 1) * \
	TILE_SIZE && ray->vertwallhit.y >= 0 && ray->vertwallhit.y <= (map->maplines - 1) * TILE_SIZE)
	{
		if (haswall_at(ray->vertwallhit.x - check_isfacingleft, ray->vertwallhit.y, map))
		{
			getvertwall = true;
			break ;
		}
		else
		{
			ray->vertwallhit.x += step.x;
			ray->vertwallhit.y += step.y;
		}
	}
	return (get_distance(player, ray->vertwallhit.x, ray->vertwallhit.y, getvertwall));
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

