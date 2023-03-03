/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainparsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:18:20 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 21:51:37 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	__parse_map(t_map_info *game, char *line, int fd)
{
	if (game->has_c != 1 || game->has_we != 1 || game->has_f != 1 || \
	game->has_no != 1 || game->has_so != 1 || game->has_we != 1)
		return (ft_error("invalide map's cart!!"), exit(1));
	if (!_parse_map(game, line, fd))
		return (ft_error("invalid map!!"), exit(1));
}

char	*__start_read(t_map_info *game, char *file, int *fd)
{
	char	*first_line;

	game->maplines = countline(file);
	*fd = open(file, O_RDWR);
	if (*fd < 0)
		return (ft_error("can't open file"), exit(1), NULL);
	first_line = get_next_line(*fd);
	if (!first_line)
		return (ft_error("get map from empty file!!"), exit(1), NULL);
	return (first_line);
}

void	ft_reading_maps(t_map_info *game, char *file)
{
	char	*line;
	char	*clean_line;
	int		fd;

	line = __start_read(game, file, &fd);
	while (line)
	{
		clean_line = ft_strtrim(line, " \n");
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
	__parse_map(game, line, fd);
}

void	_parsing(char *file, t_map_info *game)
{
	initializer(game);
	ft_check_cub(file);
	ft_reading_maps(game, file);
}
