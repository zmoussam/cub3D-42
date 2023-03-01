/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainparsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:18:20 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/01 04:02:19 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	ft_reading_maps(t_map_info *game, char *file)
{
	char	*ptr;
	char	*clean_ptr;
	int		fd;
	int		retvalue;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return(ft_error("can't open file"), exit(1), 0);
	ptr = get_next_line(fd);
	if (!ptr)
		return (ft_error("empty map file"), exit(1), 0);
	game->lineindex = 0;
	game->maplines = countline(file);
	if (!game->maplines)
		return (free(ptr), 0);
	while (ptr)
	{
		clean_ptr = remove_caract(ptr, " \n");
		if (clean_ptr == NULL)
			return (0);
		game->lenghtlines = ft_strlen(clean_ptr);
		if (game->lenghtlines == 0)
		{
			free(clean_ptr);
			ptr = get_next_line(fd);
			continue ;
		}
		retvalue = check_intern_map(clean_ptr, game);
		if (retvalue == 2)
			break ;
		else
			check_retvalue(retvalue, clean_ptr, game);
		free(ptr);
		ptr = get_next_line(fd);
		game->lineindex++;
	}
	if (game->has_c != 1 || game->has_we != 1 || game->has_f != 1 || \
game->has_no != 1 || game->has_so != 1 || game->has_we != 1)
		return (printf("Error : invalid map"), 0);
	if (!parse_map(game, ptr, fd))
		return (exit(1), 0);
	return (1);
}

int base_parsing(char *file, t_map_info *game)
{
	init_map_data(game);
	extention(file);
	return (ft_reading_maps(game, file));
}
