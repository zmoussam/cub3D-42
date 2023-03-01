/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:14:58 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/01 00:43:10 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	initializer(t_map_info *game)
{
	game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	game->map = NULL;
	game->ea = NULL;
	game->map = NULL;
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

void	ft_check_cub(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 4] != '.' || filename[len - 3] != 'c' || \
filename[len - 2] != 'u' || filename[len - 1] != 'b')
	{
		write(2, "this file's name needs to be ended by .cub\n", 42);
		exit(1);
	}
}
