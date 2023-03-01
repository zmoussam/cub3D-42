/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:33:48 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/01 04:24:52 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void ft_error(char *error_name)
{
	printf("\n\033[31m---------------------------[ ERORR ]--------------------------\n\n\033[0m");
    printf("\033[0;33m=> : %s\033[0m\n\n", error_name);
    printf("\033[31m--------------------------------------------------------------\n\033[0m");
}

int	check_valid_map(t_index index, char **map, t_map_info *game, int *counter)
{
	if (game->map[index.i][index.j] == 'N' || game->map[index.i][index.j] == 'S' || \
game->map[index.i][index.j] == 'E' || game->map[index.i][index.j] == 'W')
		(*counter)++;
	if (*counter == 1 || game->map[index.i][index.j] == '0')
	{
		if (!valid_n(map, index.i, index.j) || !valid_e(map, index.i, index.j) || !valid_s(map, index.i, index.j, \
game) || !valid_w(map, index.i, index.j))
			return (printf("map is invalide\n"), exit(1), 0);
	}
	else if (*counter > 1)
		return (printf("there is more than 1player \n"), exit(1), 0);
	return (1);
}

int	checkmap(t_map_info *game)
{
	t_index index;
	int		counter;

	index.i = -1;
	counter = 0;
	while (game->map[++index.i])
	{
		index.j = -1;
		while (game->map[index.i][++index.j])
		{
			if (game->map[index.i][index.j] == 'N' || game->map[index.i][index.j] == 'S' || \
game->map[index.i][index.j] == 'E' || game->map[index.i][index.j] == 'W' || game->map[index.i][index.j] == '0')
			{
				if (!check_valid_map(index, game->map, game, &counter))
					return (0);
			}
			else if (game->map[index.i][index.j] != '1' && game->map[index.i][index.j] != ' ' && \
			game->map[index.i][index.j] != '\n')
				return (printf("Error: invalid map!!\n"), 0);
		}
	}
	if (counter == 0)
		return (printf("map should contain 1 player"), exit(1), 0);
	return (1);
}

int	parse_map(t_map_info *game, char *first_line, int fd)
{
	int		i;
	char	*line;

	i = 1;
	game->map = (char **)malloc((game->maplines - game->lineindex + 1) * \
	sizeof(char *));
	if (!(game->map))
		return (0);
	game->map[0] = first_line;
	line = get_next_line(fd);
	while (i < game->maplines - game->lineindex)
	{
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	int j;
	j = 0;
	game->map[i] = NULL;
	if (!checkmap(game))
		return (0);
	findmaxline(game);
	
	while(j < game->maplines - game->lineindex)
	{
		char *cleanptr = remove_caract(game->map[j], "\n");
		if(!cleanptr)
			return(0);
		game->map[j] = cleanptr;
		j++;
	}
	close(fd);
	return (1);
}