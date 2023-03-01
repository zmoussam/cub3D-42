/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainparsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:00:35 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/02 00:32:33 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	check_line(char *clean_ptr, t_map_info *game)
{
	char	*tab[3];
	int		j;

	tab[0] = "F ";
	tab[1] = "C ";
	tab[2] = "1";
	if (check_texture(game, clean_ptr))
		return (parse_direction(game, clean_ptr), 1);
	j = 0;
	while (j < 3)
	{
		if (ft_strncmp(clean_ptr, tab[j], ft_strlen(tab[j])) == 0)
		{
			if (j == 2)
				return (2);
			else
				return (parse_color(game, clean_ptr), 3);
		}
		j++;
	}
	free(clean_ptr);
	return (ft_error("invalid map!!"), 0);
}

int	check_texture(t_map_info *game, char *cleanline)
{
	if (game->lenghtlines > 3)
	{
		if (ft_strnstr(cleanline, "NO ", 3) || \
ft_strnstr(cleanline, "SO ", 3) || ft_strnstr(cleanline, "WE ", 3) || \
ft_strnstr(cleanline, "EA ", 3))
			return (1);
	}
	return (0);
}
