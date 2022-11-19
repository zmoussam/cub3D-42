/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:29:57 by zmoussam          #+#    #+#             */
/*   Updated: 2022/11/19 18:20:23 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int check_wals(char *border, int index)
{
	int i;

	i = 0;
	if (index == 0)
	{
		while (border[i])
		{
			if (border[i] != '1' && border[i] != 32 && border[i] != '\n')
				return (0);
			i++;
		}	
	}
	else if (border[0] != '1' || border[ft_strlen(border) - 2] != '1')
		return (0);
	return (1);
}


int	map_list_to_array(t_list *map, t_info *infos, int height)
{
	int i;
	
	i = 0;
	infos->map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!infos->map)
		return (printf("Error: memory was not allocated!!\n"), 0);
	while (map)
	{
		infos->map[i] = map->content;
		map = map->next;
		i++;	
	}
    infos->map[i] = NULL;
	return (1);
}

int	get_map_content(int fd, t_list **map)
{
	char	*line;
	t_list	*new;
	int		map_height;
	
	map_height = 1;
	line = get_next_line(fd);
	while (line)
	{
		new = ft_lstnew(line);
		if (!new)
			return (free_map_list(*map, map_height), \
			printf("Error: memory was not allocated!!\n"), 0);
		ft_lstadd_back(map, new);
		map_height++;
		line = get_next_line(fd);
	}
	return (map_height);
}

int	get_map(int fd, t_info *infos, char *first_line)
{
	t_list	*map;
	int		map_height;
	
	(void)infos;
	if (!first_line)
		return (printf("Error: map not found"), 0);
	if (!check_wals(first_line, 0))
		return (printf("Error: invalide map's walls!!\n"), free(first_line), 0);
	map = ft_lstnew(first_line);
	if (!map)
		return (free(first_line), printf("Error: memory was not allocated!!\n"), 0);
	map_height = get_map_content(fd, &map);
	map_list_to_array(map, infos, map_height);
    // if (!parse_map(info->map, map_height));
    //     return (free_info(info));
	close(fd);
	return (1);
}