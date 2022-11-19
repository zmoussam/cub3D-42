/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:29:57 by zmoussam          #+#    #+#             */
/*   Updated: 2022/11/19 22:14:14 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

int check_west(char **map, int x, int y)
{
    if (x == 0)
        return (0);
    else if (map[y][x - 1] == 32)
        return (0);
    return (1);
}

int check_east(char **map, int x, int y)
{
    if (map[y][x + 1] == 32 || map[y][x + 1] == '\n' || map[y][x + 1] == '\0')
        return (0);
    return (1);
}

int check_north(char **map, int x, int y)
{
    if (y == 0)
        return (0);
    else if (ft_strlen(map[y - 1]) <= x + 1)
        return (0);
    else if (map[y - 1][x] == 32)
        return (0);
    return (1);
}

int check_south(char **map, int x, int y, int height)
{
    if (y == height - 1)
        return (0);
    else if (ft_strlen(map[y + 1]) <= x)
        return (0);
    else if (map[y + 1][x] == 32 || map[y + 1][x] == '\0')
        return (0);
    return (1);
}

int check_for_empty_space(char **map, int x, int y, int height)
{
    if (!check_west(map, x, y) || !check_north(map, x, y) \
        || !check_east(map, x, y) || !check_south(map, x, y, height))
        return (0);
    return (1);
}

int check_component(char **map, int height)
{
    int i;
    int j;
    int size;
    int count;

    i = 0;
    j = 0;
    count = 0;
    while (map[i])
    {
        j = 0;
        size = ft_strlen(map[i]);
        while (map[i][j])
        {
            if (map[i][j] == '0' || map[i][j] == 'S' || map[i][j] == 'E' \
                || map[i][j] == 'W' || map[i][j] == 'N')
            {
                if (!check_for_empty_space(map, j , i, height))
                     return (printf("Error1: invalid map!!\n"),0);
                if (map[i][j] != '0')
                    count++;
            }
            else if (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != 'N' \
                && map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W' \
                && map[i][j] != '\n')
                return (printf("Error: invalid map!!\n"), 0);
            if (count > 1)
               return (printf("Error: invalid map!! multiple player!!\n"), 0);
            j++;
        }
        i++;
    }
    if (count == 0)
         return (printf("Error: invalid map!! need player's position!!\n"), 0);
    return (1); 
}

int parse_map(char **map, int height)
{
    if (!check_component(map, height))
        return (0);
    return (1);  
}

int	get_map(int fd, t_info *infos, char *first_line)
{
	t_list	*map;
	int		map_height;
	
	(void)infos;
	if (!first_line)
		return (printf("Error: map not found"), 0);
	map = ft_lstnew(first_line);
	if (!map)
		return (free(first_line), printf("Error: memory was not allocated!!\n"), 0);
	map_height = get_map_content(fd, &map);
	if (!map_list_to_array(map, infos, map_height))
        return (0);
    if (!parse_map(infos->map, map_height))
        return(0);
	close(fd);
	return (1);
}