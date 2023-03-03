/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dprojection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:31:14 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 02:46:16 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;
	int		ofsset;

	ofsset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + ofsset;
	*(unsigned int *)dst = color;
}

void	drawwallcolumn(t_img_data *img, t_cordinates _pos, double dy, int clr)
{
	while (_pos.y < dy && dy <= SCREENHEIGHT && _pos.y >= 0)
	{
		my_mlx_pixel_put(img, _pos.x, _pos.y, clr);
		_pos.y++;
	}
}

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

void _put_pixel_from_texture_to_wall(t_collect_data *data, \
	t_cordinates offsset, t_ray *ray, t_cordinates cordinates)
{
	if (ray->wallhitisvert)
		put_west_east_texture(data, offsset, ray,  cordinates);
	else
		put_north_south_texture(data,  offsset, ray,  cordinates);
}

void	draw_wall(t_collect_data *data, t_cordinates offsset, int i, t_ray *ray)
{
	double	top;
	double	bottom;
	double	wall;
	t_cordinates cordinates;

	if (ray->wallstripheight > SCREENHEIGHT)
		wall = SCREENHEIGHT;
	else
		wall = ray->wallstripheight;
	top = (SCREENHEIGHT / 2) - (wall / 2);
	bottom = (SCREENHEIGHT / 2) + (wall / 2);
	while (top < bottom)
	{
		cordinates.x = i;
		cordinates.y = top;
		_put_pixel_from_texture_to_wall(data, offsset, ray, cordinates);
		top++;
	}
}

double get_ofssets_x(t_texture *texture, t_ray *ray)
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

void	draw(t_collect_data *data, t_ray *ray, int i)
{
	double distance_projection_plane;
	double walltop;
	double wallbottom;
	t_cordinates ofssets;
	t_cordinates _draw_pos;
	
	distance_projection_plane = (SCREENWIDTH / 2) / (tan(VIEW_ANGLE / 2));
	ray->wallstripheight = (SCREENWIDTH / ray->distancetowall) * WALL_HEIGHT;

	walltop = (SCREENHEIGHT / 2) - (ray->wallstripheight / 2);
	if (walltop < 0)
		walltop = 0;

	wallbottom = (SCREENHEIGHT / 2) + (ray->wallstripheight / 2);
	if (wallbottom > SCREENHEIGHT)
		wallbottom = SCREENHEIGHT;
	_draw_pos.x = i;
	_draw_pos.y = 0;
	drawwallcolumn(data->mlx->img, _draw_pos, walltop, data->map_info->c_ceilling);
	ofssets.x = get_ofssets_x(data->wall, ray);
	draw_wall(data, ofssets, i, ray);
	_draw_pos.y = wallbottom;
	drawwallcolumn(data->mlx->img, _draw_pos, SCREENHEIGHT, data->map_info->c_floor);
}
