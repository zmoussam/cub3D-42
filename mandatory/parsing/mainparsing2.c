/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainparsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:00:35 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 01:17:53 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	check_line(char *clean_line, t_map_info *game)
{
	char	*tab[3];
	int		i;

	tab[0] = "F ";
	tab[1] = "C ";
	tab[2] = "1";
	if (check_texture(game, clean_line))
		return (parse_direction(game, clean_line), 1);
	i = 0;
	while (i < 3)
	{
		if (ft_strncmp(clean_line, tab[i], ft_strlen(tab[i])) == 0)
		{
			if (i == 2)
				return (free(clean_line), 2);
			else
				return (parse_color(game, clean_line), 3);
		}
		i++;
	}
	free(clean_line);
	return (ft_error("invalid map!!"), exit(0), 0);
}

int	check_texture(t_map_info *game, char *cleanline)
{
	if (game->lenghtlines > 3)
	{
		if (ft_strnstr(cleanline, "NO ", 3) ||
			ft_strnstr(cleanline, "SO ", 3) || ft_strnstr(cleanline, "WE ", 3)
				||
			ft_strnstr(cleanline, "EA ", 3))
			return (1);
	}
	return (0);
}
