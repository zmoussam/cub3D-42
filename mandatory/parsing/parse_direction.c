/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:40:05 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/02 00:24:31 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	no_direct(t_map_info *game, char *line)
{
	char *str;
	
	str = remove_prefix(line, "NO");
	if (!str)
		return (ft_error("can't allocat memory"), 0);
	game->no = remove_caract(str, " ");
	if (!game->no)
		return (ft_error("can't allocat memory"), 0);
	game->has_no = 1;
	free(str);
	return (1);
}

int	we_direct(t_map_info *game, char *line)
{
	char *str;
	
	str = remove_prefix(line, "WE");
	if (!str)
		return (ft_error("can't allocat memory"), 0);
	game->we = remove_caract(str, " ");
	if (!game->we)
		return (ft_error("can't allocat memory"), 0);
	game->has_we = 1;
	free(str);
	return (1);
}

int	so_direct(t_map_info *game, char *line)
{
	char *str;
	
	str = remove_prefix(line, "SO");
	if (!str)
		return (ft_error("can't allocat memory"), 0);
	game->so = remove_caract(str, " ");
	if (!game->so)
		return (ft_error("can't allocat memory"), 0);
	game->has_so = 1;
	free(str);
	return (1);
}

int	ea_direct(t_map_info *game, char *line)
{
	char *str;
	
	str = remove_prefix(line, "EA");
	if (!str)
		return (ft_error("can't allocat memory"), 0);
	game->ea = remove_caract(str, " ");
	if (!game->ea)
		return (ft_error("can't allocat memory"), 0);
	game->has_ea = 1;
	free(str);
	return (1);
}

void	parse_direction(t_map_info *game, char *line)
{
	if (ft_strnstr(line, "NO", 2) && game->has_no == -1)
		no_direct(game, line);
	else if (ft_strnstr(line, "SO", 2) && game->has_so == -1)
		so_direct(game, line);
	else if (ft_strnstr(line, "EA", 2) && game->has_ea == -1)
		ea_direct(game, line);
	else if (ft_strnstr(line, "WE", 2) && game->has_we == -1)
		we_direct(game, line);
}
