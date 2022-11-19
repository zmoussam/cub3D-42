/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:34:55 by zmoussam          #+#    #+#             */
/*   Updated: 2022/11/19 17:53:38 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int get_token(char *line)
{
	int size;
	
	size = ft_strlen(line);
	if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
		return (RGB_COLOR);
	else if (line[0] == '1')
		return (MAP);
	else if (line[0] == '\0')
		return (EMPTY_LINE);
	else if (size > 3 && \
		((line[0] == 'N' && line[1] == 'O' && line[2] == ' ') \
		|| (line[0] == 'S' && line[1] == 'O' && line[2] == ' ') \
		|| (line[0] == 'E' && line[1] == 'A' && line[2] == ' ') \
		|| (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')))
		return (DIRECTION);
	else 
		return (INVALIDE_LINE);
}

int parsing(t_info *infos, char *file_name)
{
	int		fd;
	
	check_extention(file_name);
	fd = open(file_name, O_RDWR);
	if (fd == -1)
		return (printf("Error: %s\n", strerror(errno)), 0);
	if (!get_infos(infos, fd))
		return (0);
	return (1);
}