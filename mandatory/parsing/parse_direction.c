/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:40:05 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/01 00:48:00 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	no_direct(t_map_info *game, char *line)
{
	char *str;

	if (ft_strnstr(line, "NO", 2) && game->has_no == -1)
	{
		str = remove_prefix(line, "NO");
		game->no = remove_caract(str, " ");
		if (!(game->no))
			write(2, "there is an error", 17);
		game->has_no = 1;
		free(str);
	}
}

void	we_direct(t_map_info *game, char *line)
{
	char *str;

	if (ft_strnstr(line, "WE", 2) && game->has_we == -1)
	{
		str = remove_prefix(line, "WE ");
		game->we = remove_caract(str, " ");
		if (!(game->we))
			write(2, "there is an error", 17);
		game->has_we = 1;
		free(str);
	}
}

void	so_direct(t_map_info *game, char *line)
{
	char *str;

	if (ft_strnstr(line, "SO", 2) && game->has_so == -1)
	{
		str = remove_prefix(line, "SO ");
		game->so = remove_caract(str, " ");
		if (!(game->so))
			write(2, "there is an error", 17);
		game->has_so = 1;
	}
}

void	ea_direct(t_map_info *game, char *line)
{
	char *str;
	
	if (ft_strnstr(line, "EA", 2) && game->has_ea == -1)
	{
		str = remove_prefix(line, "EA ");
		game->ea = remove_caract(str, " ");
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
