/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:14:58 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 01:16:12 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	initializer(t_map_info *game)
{
	game->maplines = 0;
	game->lenghtlines = 0;
	game->has_ea = 0;
	game->has_no = 0;
	game->has_we = 0;
	game->has_so = 0;
	game->has_c = 0;
	game->has_f = 0;
	game->c_floor = 0;
	game->c_ceilling = 0;
	game->lineindex = 0;
	game->maxlenmap = 0;
	game->ea = NULL;
	game->so = NULL;
	game->no = NULL;
	game->we = NULL;
}

void	ft_check_cub(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 4] != '.' || filename[len - 3] != 'c' ||
		filename[len - 2] != 'u' || filename[len - 1] != 'b')
	{
		write(2, "this file's name needs to be ended by .cub\n", 42);
		exit(1);
	}
}
