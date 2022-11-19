/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:52:07 by zmoussam          #+#    #+#             */
/*   Updated: 2022/11/19 18:25:32 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_infos(t_info *infos, int fd)
{
	char		*tmp_line;
	char		*line;
	int			count;
	int			token;

	count = 0;
	tmp_line = get_next_line(fd);
	if (!tmp_line)
		return (printf("Error: empty map's file!!\n"), 0);
	while (tmp_line)
	{
		line = ft_strtrim(tmp_line, " \n");
		if (!line)
			return (printf("Error: memory was not allocated!!\n"), 0);
		token = get_token(line);
		if (token == MAP)
			break ;
		else if (token == EMPTY_LINE)
		{
			free(line);
			tmp_line = get_next_line(fd);
			continue;
		}
		else if (token == RGB_COLOR)
			get_color(infos, line, &count);
		else if (token == DIRECTION)
			get_direction(infos, line, &count);
		else if (token == INVALIDE_LINE)
			return (printf("Error: invalid map's informations!!\n"), free(tmp_line), free(line), 0);
		free(tmp_line);
		tmp_line = get_next_line(fd);
	}
	if (count != 6 || infos->ceilling == -1 || infos->floor == -1 \
		|| !infos->ea || !infos->no || !infos->we || !infos->so)
		return (printf("Error: invalid map's informations!!\n"), 0);
	if (!get_map(fd, infos, tmp_line))
		return (0);
	return (1);
}