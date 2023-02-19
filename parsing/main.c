/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:06:29 by zmoussam          #+#    #+#             */
/*   Updated: 2022/11/19 17:51:32 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int main(int ac, char **argv)
{
	t_info info;
	int i = 0;
	
	info.ea = NULL;
	info.no = NULL;
	info.so = NULL;
	info.we = NULL;
	info.floor = -1;
	info.ceilling = -1;
    if (ac != 2)
		_error("cub3d: error: invalid argument!!\n");
	if (!parsing(&info, argv[1]))
		exit(1);
	// map_height = get_map
	printf("NO = %s\n", info.no);
	printf("SO = %s\n", info.so);
	printf("EA = %s\n", info.ea);
	printf("we = %s\n", info.we);
	printf("floor = %d\n", info.floor);
	printf("ceilling = %d\n", info.ceilling);
	
	printf("\n");
	
	while(info.map[i])
		printf("%s", info.map[i++]);
	// printf("trim = %s\n", ft_strtrim("\n", " \n"));
	
}