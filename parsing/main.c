/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:06:29 by zmoussam          #+#    #+#             */
/*   Updated: 2022/11/18 17:13:16 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "../libft_zack/libft.h"

// void	read_map_file(char *file_name)
// {
	
// }
void	handel_error(char *error_name)
{
	perror(error_name);
	exit(1);
}

void	check_extention(char *file_name)
{
	int		start;
	char	*extention;

	start = ft_strlen(file_name) - 4;
	extention = ft_substr(file_name, start, 4);
	if (ft_strcmp(".cub", extention) != 0)
	{
		free(extention);
		handel_error("extention must be .cub\n");
	}
	free(extention);
}

int main(int ac, char **argv)
{
    if (ac != 2)
		handel_error("cub3d: error: invalid argument!!\n");
    check_extention(argv[1]);
}