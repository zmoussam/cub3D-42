/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:40:05 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/02 05:35:37 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	no_direct(t_map_info *game, char *line)
{
	char *str;

	str = remove_prefix(line, "NO");
	if (!str)
		return (ft_error("can't allocat memory"), exit(1), 0);
	game->no = remove_caract(str, " ");
	if (!game->no)
		return (ft_error("can't allocat memory"), exit(1), 0);
	game->has_no++;
	free(str);
	return (1);
}

int	we_direct(t_map_info *game, char *line)
{
	char	*str;

	str = remove_prefix(line, "WE");
	if (!str)
		return (ft_error("can't allocat memory"), exit(1), 0);
	game->we = remove_caract(str, " ");
	if (!game->we)
		return (ft_error("can't allocat memory"), exit(1), 0);
	game->has_we++;
	free(str);
	return (1);
}

int	so_direct(t_map_info *game, char *line)
{
	char *str;
	
	str = remove_prefix(line, "SO");
	if (!str)
		return (ft_error("can't allocat memory"), exit(1), 0);
	game->so = remove_caract(str, " ");
	if (!game->so)
		return (ft_error("can't allocat memory"), exit(1), 0);
	game->has_so++;
	free(str);
	return (1);
}

int	ea_direct(t_map_info *game, char *line)
{
	char *str;
	
	str = remove_prefix(line, "EA");
	if (!str)
		return (ft_error("can't allocat memory"), exit(1), 0);
	game->ea = remove_caract(str, " ");
	if (!game->ea)
		return (ft_error("can't allocat memory"), exit(1), 0);
	game->has_ea++;
	free(str);
	return (1);
}

void	parse_direction(t_map_info *game, char *line)
{
	if (ft_strnstr(line, "NO", 2))
		no_direct(game, line);
	else if (ft_strnstr(line, "SO", 2))
		so_direct(game, line);
	else if (ft_strnstr(line, "EA", 2))
		ea_direct(game, line);
	else if (ft_strnstr(line, "WE", 2))
		we_direct(game, line);
	free(line);
}
