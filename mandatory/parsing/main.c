/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:40:56 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/01 05:23:38 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"


int	main(int ac, char **av)
{
	t_map_info game;
	int res;
	int i;
	if (ac != 2)
		ft_error("invalid args!!");
	else
	{
		res = base_parsing(av[1], &game);
		if (res)
		{
			i = 0;
			printf("NO = %s\n", game.no);
			printf("SO = %s\n", game.so);
			printf("EA = %s\n", game.ea);
			printf("we = %s\n", game.we);
			printf("floor = %d\n", game.c_floor);
			printf("ceilling = %d\n", game.c_ceilling);
			printf("ceilling = %d\n", game.maplines);
			printf("max line in map = %zu\n", game.maxlenmap);
			while (game.map[i])
				printf("%sfin\n", game.map[i++]);
		}
		else
			ft_error("invalid map!");;
	}
	return (1);
}
