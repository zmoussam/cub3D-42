/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dprojection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:31:14 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 23:20:26 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_west_east_texture(t_collect_data *data, t_cordinates offsset, \
		t_ray *ray, t_cordinates cordinates)
{
	double	dis;

	dis = cordinates.y + (ray->wallstripheight / 2) - (SCREENHEIGHT / 2);
	if (ray->isfacingright)
	{
		offsset.y = floor(dis / ray->wallstripheight * \
			data->wall[0]._heigth);
		my_mlx_pixel_put(data->mlx->img, cordinates.x, cordinates.y, \
			data->wall[0].info->int_addr[(int)((offsset.y \
			* data->wall[0]._width) + offsset.x)]);
	}
	else
	{
		offsset.y = floor(dis / ray->wallstripheight * \
			data->wall[1]._heigth);
		my_mlx_pixel_put(data->mlx->img, cordinates.x, cordinates.y, \
			data->wall[1].info->int_addr[(int)((offsset.y \
			* data->wall[1]._width) + offsset.x)]);
	}
}

void	put_north_south_texture(t_collect_data *data, t_cordinates \
		offsset, t_ray *ray, t_cordinates cordinates)
{
	double	dis;

	dis = cordinates.y + (ray->wallstripheight / 2) - (SCREENHEIGHT / 2);
	if (ray->isfacingdown)
	{
		offsset.y = floor(dis / ray->wallstripheight \
			* data->wall[2]._heigth);
		my_mlx_pixel_put(data->mlx->img, cordinates.x, cordinates.y, \
			data->wall[2].info->int_addr[(int)((offsset.y \
			* data->wall[2]._width) + offsset.x)]);
	}
	else
	{
		offsset.y = floor(dis / ray->wallstripheight \
			* data->wall[3]._heigth);
		my_mlx_pixel_put(data->mlx->img, cordinates.x, cordinates.y, \
			data->wall[3].info->int_addr[(int)((offsset.y \
			* data->wall[3]._width) + offsset.x)]);
	}
}

void	_put_pixel_from_texture_to_wall(t_collect_data *data, \
	t_cordinates offsset, t_ray *ray, t_cordinates cordinates)
{
	if (ray->wallhitisvert)
		put_west_east_texture(data, offsset, ray, cordinates);
	else
		put_north_south_texture(data, offsset, ray, cordinates);
}

double	get_ofssets_x(t_texture *texture, t_ray *ray)
{
	if (ray->wallhitisvert)
	{
		if (ray->isfacingright)
			return (fmod(ray->vertwallhit.y, TILE_SIZE) / TILE_SIZE \
				* texture[0]._width);
		else
			return (fmod(ray->vertwallhit.y, TILE_SIZE) / TILE_SIZE \
				* texture[1]._width);
	}
	else
	{
		if (ray->isfacingdown)
			return (fmod(ray->horzwallhit.x, TILE_SIZE) / TILE_SIZE \
				* texture[2]._width);
		else
			return (fmod(ray->horzwallhit.x, TILE_SIZE) / TILE_SIZE \
				* texture[3]._width);
	}
}
