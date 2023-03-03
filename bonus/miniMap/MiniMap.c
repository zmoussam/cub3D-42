/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:05:41 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 23:13:22 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;
	int		ofsset;

	ofsset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + ofsset;
	*(unsigned int *)dst = color;
}

int	get_minimap_collor(char **map, t_cordinates pos)
{
	if (map[(int)(pos.y / (MINI_MAP_TILE_SIZE))][(int)(pos.x / \
		(MINI_MAP_TILE_SIZE))] == '1')
		return (0x00000000);
	else if (map[(int)(pos.y / (MINI_MAP_TILE_SIZE))][(int)(pos.x / \
		(MINI_MAP_TILE_SIZE))] == ' ')
		return (0xA0A00000);
	return (0xA0A090A0);
}

void	draw_minimap(t_collect_data *data, t_cordinates minimap_pos, \
	int i, int j)
{
	if ((minimap_pos.x > 0 && minimap_pos.x < data->map_info->maxlenmap * \
	MINI_MAP_TILE_SIZE && minimap_pos.y > 0 && minimap_pos.y < \
	data->map_info->maplines * MINI_MAP_TILE_SIZE) && \
	(minimap_pos.x / MINI_MAP_TILE_SIZE) < \
ft_strlen(data->map_info->map[(int)(minimap_pos.y / MINI_MAP_TILE_SIZE)]))
		my_mlx_pixel_put(data->mini_map, j, i, \
		get_minimap_collor(data->map_info->map, minimap_pos));
	else
		my_mlx_pixel_put(data->mini_map, j, i, 0xA0A00000);
}

void	put_minimap(t_collect_data *data)
{
	int				i;
	int				j;
	t_cordinates	p_pos;
	t_cordinates	start_minimap;

	p_pos = data->player->position;
	start_minimap.x = round((p_pos.x / TILE_SIZE * MINI_MAP_TILE_SIZE) \
	- (SCREENWIDTH * MINI_MAP_FACTOR / 2));
	start_minimap.y = round((p_pos.y / TILE_SIZE * MINI_MAP_TILE_SIZE) \
	- (SCREENHEIGHT * MINI_MAP_FACTOR / 2));
	i = -1;
	while (++i < MINI_MAP_HEIGHT)
	{
		j = -1;
		start_minimap.x = round((p_pos.x / TILE_SIZE * MINI_MAP_TILE_SIZE) \
		- (SCREENWIDTH * MINI_MAP_FACTOR / 2));
		while (++j < MINI_MAP_WIDTH)
		{
			draw_minimap(data, start_minimap, i, j);
			start_minimap.x++;
		}
		start_minimap.y++;
	}
	put_player(data);
}
