/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:14:58 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/01 03:40:07 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	init_map_data(t_map_info *game)
{
	game->maplines = 0;
	game->lenghtlines = 0;
	game->has_ea = -1;
	game->has_no = -1;
	game->has_we = -1;
	game->has_so = -1;
	game->has_c = -1;
	game->has_f = -1;
	game->c_floor = 0;
	game->c_ceilling = 0;
}

void	extention(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 4] != '.' || filename[len - 3] != 'c' || \
filename[len - 2] != 'u' || filename[len - 1] != 'b')
	{
		ft_error("this file's name needs to be ended by .cub");
		exit(1);
	}
}
