/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:27:06 by zmoussam          #+#    #+#             */
/*   Updated: 2022/11/19 17:44:53 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*get_texture_path(char *line)
{
	char *texture;
	
	texture = ft_strtrim(line, " \n");
	if (!texture)
		_error("Error: memory was not allocated!!\n");
	return (texture);
}

void	get_direction(t_info *infos, char *line, int *count)
{
	*count += 1;
	
	if (line[0] == 'N' && line[1] == 'O' && !infos->no)
		infos->no = get_texture_path(&line[2]);
	else if (line[0] == 'S' && line[1] == 'O' && !infos->so)
		infos->so = get_texture_path(&line[2]);
	else if (line[0] == 'W' && line[1] == 'E' && !infos->we)	
		infos->we = get_texture_path(&line[2]);
	else if (line[0] == 'E' && line[1] == 'A' && !infos->ea)
		infos->ea = get_texture_path(&line[2]);
}