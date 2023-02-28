/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:40:05 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/28 21:29:24 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	no_direct(t_map_info *game, char *line)
{
	if (ft_strnstr(line, "NO", 2) && game->has_no == -1)
	{
		game->no = remove_prefix(line, "NO ");
		if (!(game->no))
			write(2, "there is an error", 17);
		game->has_no = 1;
	}
}

void	we_direct(t_map_info *game, char *line)
{
	if (ft_strnstr(line, "WE", 2) && game->has_we == -1)
	{
		game->we = remove_prefix(line, "WE ");
		if (!(game->we))
			write(2, "there is an error", 17);
		game->has_we = 1;
	}
}

void	so_direct(t_map_info *game, char *line)
{
	if (ft_strnstr(line, "SO", 2) && game->has_so == -1)
	{
		game->so = remove_prefix(line, "SO ");
		if (!(game->so))
			write(2, "there is an error", 17);
		game->has_so = 1;
	}
}

void	ea_direct(t_map_info *game, char *line)
{
	if (ft_strnstr(line, "EA", 2) && game->has_ea == -1)
	{
		game->ea = remove_prefix(line, "EA ");
		if (!(game->ea))
			write(2, "there is an error", 17);
		game->has_ea = 1;
	}
}

void	parse_direction(t_map_info *game, char *line)
{
	no_direct(game, line);
	so_direct(game, line);
	ea_direct(game, line);
	we_direct(game, line);
}
