/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findIntersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:01:39 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 23:27:44 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	haswall_at(double x, double y, t_map_info *map)
{
	if (x < 0 || x > map->maxlenmap * TILE_SIZE || y < 0 || \
		y > map->maplines * TILE_SIZE)
		return (1);
	if ((int)(x / TILE_SIZE) >= (int)ft_strlen(map->map[(int)(y / TILE_SIZE)]))
	{
		return (1);
	}
	return (map->map[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1');
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

double	find_horzintersection(t_player *player, t_ray *ray, \
		t_map_info *map, bool gethorhit)
{
	t_cordinates	step;
	short			check_isfacingup;

	check_isfacingup = 0;
	ray->horzwallhit = find_horzintercept(player, ray);
	step = find_horzstep(ray);
	if (ray->isfacingup == -1)
		check_isfacingup = 1;
	while (ray->horzwallhit.x >= 0 && ray->horzwallhit.x <= \
	(map->maxlenmap - 1) * TILE_SIZE && ray->horzwallhit.y >= 0 && \
		ray->horzwallhit.y <= (map->maplines - 1) * TILE_SIZE)
	{
		if (haswall_at(ray->horzwallhit.x, ray->horzwallhit.y - \
			check_isfacingup, map))
		{
			gethorhit = true;
			break ;
		}
		else
		{
			ray->horzwallhit.x += step.x;
			ray->horzwallhit.y += step.y;
		}
	}
	return (getdis(player, ray->horzwallhit.x, ray->horzwallhit.y, gethorhit));
}

double	find_vertintersection(t_player *player, t_ray *ray, \
t_map_info *map, bool getverthit)

{
	t_cordinates	step;
	short			check_isfacingleft;

	check_isfacingleft = 0;
	ray->vertwallhit = find_vertintercept(player, ray);
	step = find_vertstep(ray);
	if (ray->isfacingleft == -1)
		check_isfacingleft = 1;
	while (ray->vertwallhit.x >= 0 && ray->vertwallhit.x < \
		(map->maxlenmap) * TILE_SIZE && ray->vertwallhit.y >= 0 && \
		ray->vertwallhit.y <= (map->maplines) * TILE_SIZE)
	{
		if (haswall_at(ray->vertwallhit.x - check_isfacingleft, \
			ray->vertwallhit.y, map))
		{
			getverthit = true;
			break ;
		}
		else
		{
			ray->vertwallhit.x += step.x;
			ray->vertwallhit.y += step.y;
		}
	}
	return (getdis(player, ray->vertwallhit.x, ray->vertwallhit.y, getverthit));
}
