/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainparsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:00:35 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/28 21:28:56 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

char	**remplir_tableau(void)
{
	char	**tableau;

	tableau = malloc(3 * sizeof(char *));
	tableau[0] = ft_strdup("F ");
	tableau[1] = ft_strdup("C ");
	tableau[2] = ft_strdup("1");
	return (tableau);
}

void	free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	check_intern_map(char *clean_ptr, t_map_info *game)
{
	int		j;
	char	**tab;
	int		i;

	i = 0;
	while (clean_ptr[i++])
	{
		if (check_path(game, clean_ptr))
			return (1);
		j = 0;
		tab = remplir_tableau();
		while (j < 3)
		{
			if (ft_strncmp(clean_ptr, tab[j], ft_strlen(tab[j])) == 0)
			{
				if (j == 2)
					return (free_tab(tab, 3), 2);
				else
					return (free_tab(tab, 3), 3);
			}
			j++;
		}
		free_tab(tab, 3);
	}
	return (printf("Error: invalid map's informations!!\n"), 0);
}

void	check_retvalue(int retvalue, char *clean_ptr, t_map_info *game)
{
	if (retvalue == 1)
		parse_direction(game, clean_ptr);
	else if (retvalue == 3)
		parse_color(game, clean_ptr);
	else
		exit(0);
}

int	check_path(t_map_info *game, char *cleanline)
{
	if (game->lenghtlines > 3)
	{
		if (ft_strnstr(cleanline, "NO ", 3) || \
ft_strnstr(cleanline, "SO ", 3) || ft_strnstr(cleanline, "WE ", 3) || \
ft_strnstr(cleanline, "EA ", 3))
			return (1);
	}
	return (0);
}
