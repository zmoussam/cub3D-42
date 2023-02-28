/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainparsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:18:20 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/28 03:18:06 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	ft_reading_maps(t_abtmap *game, char *file)
{
	char	*ptr;
	char	*clean_ptr;
	int		fd;
	int		retvalue;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		write(2, "there is a probleme in operning file", 48);
	ptr = get_next_line(fd);
	game->lineindex = 0;
	if (!ptr)
		return (0);
	game->maplines = countline(file);
	while (ptr)
	{
		clean_ptr = remove_caract(ptr, " \n");
		if (!clean_ptr)
			return (0);
		game->lenghtlines = ft_strlen(clean_ptr);
		i = 0;
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

int base_parsing(char *file, t_abtmap *game)
{
    int res;

	initializer(game);
	ft_check_cub(file);
	res = ft_reading_maps(game, file);
	return (res);
}
