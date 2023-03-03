/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:17:19 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 23:24:48 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	drawwallcolumn(t_img_data *img, t_cordinates _pos, double dy, int clr)
{
	while (_pos.y < dy && dy <= SCREENHEIGHT && _pos.y >= 0)
	{
		my_mlx_pixel_put(img, _pos.x, _pos.y, clr);
		_pos.y++;
	}
}

void	draw_wall(t_collect_data *data, t_cordinates offsset, int i, t_ray *ray)
{
	double			top;
	double			bottom;
	double			wall;
	t_cordinates	cordinates;

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

void	draw(t_collect_data *data, t_ray *ray, int i)
{
	double			distance_projection_plane;
	double			walltop;
	double			wallbottom;
	t_cordinates	ofssets;
	t_cordinates	_draw_pos;

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
	drawwallcolumn(data->mlx->img, _draw_pos, walltop, \
			data->map_info->c_ceilling);
	ofssets.x = get_ofssets_x(data->wall, ray);
	draw_wall(data, ofssets, i, ray);
	_draw_pos.y = wallbottom;
	drawwallcolumn(data->mlx->img, _draw_pos, SCREENHEIGHT, \
			data->map_info->c_floor);
}
