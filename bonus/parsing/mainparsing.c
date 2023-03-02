/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainparsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:18:20 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/02 05:15:17 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	ft_reading_maps(t_map_info *game, char *file)
{
	char	*line;
	char	*clean_line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error("can't open file"), exit(1));
	line = get_next_line(fd);
	if (!line)
		return (ft_error("memory was not allocated!"), exit(1));
	game->lineindex = 0;
	game->maplines = countline(file);
	while (line)
	{
		clean_line = remove_caract(line, " \n");
		if (!clean_line)
			return (ft_error("memory was not allocated!"), exit(1));
		game->lenghtlines = ft_strlen(clean_line);
		if (game->lenghtlines == 0)
		{
			free(clean_line);
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (check_line(clean_line, game) == 2)
			break ;
		free(line);
		line = get_next_line(fd);
		game->lineindex++;
	}
	if (game->has_c != 1 || game->has_we != 1 || game->has_f != 1 || \
		game->has_no != 1 || game->has_so != 1 || game->has_we != 1)
		return (ft_error("invalide map's cart!!"), exit(1));
	if (!parse_map(game, line, fd))
		return (ft_error("invalid map!!"), exit(1));
}

void	base_parsing(char *file, t_map_info *game)
{
	initializer(game);
	ft_check_cub(file);
	ft_reading_maps(game, file);
}
