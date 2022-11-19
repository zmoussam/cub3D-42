/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:25:59 by zmoussam          #+#    #+#             */
/*   Updated: 2022/11/19 17:44:58 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_color(char **colors)
{
	int i;
	int j;
	
	i = 0;
	while (colors[i])
	{
		j = 0;
		if (check_if_empty(colors[i]))
			return (0);
		while (colors[i][j])
		{
			if ((!ft_isdigit(colors[i][j]) && colors[i][j] != 32))
				return (0);
			j++;	
		}
		if(!is_valid_rgb(ft_atoi(colors[i])))
			return (0);
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}

int check_if_empty(char *color)
{
	int i;

	i = 0;
	if (color[0] == '\0')
		return (1);
	while (color[i])
	{
		if (color[i] != ' ' && ft_isdigit(color[i]))
			return (0);
		i++;
	}
	return (1);
}

int	callcul_color(char *rgb_color)
{
	char	**colors;
	
	if (!rgb_color)
		return (_error("Error: memory was not allocated\n"), -1);
	colors = ft_split(rgb_color, ',');
	if (!colors)
		return (free(rgb_color), _error("Error: memory was not alocated\n"), -1);
	if (!parse_color(colors))
		return (free(rgb_color), free_colors(colors), _error("Error: invalide rgb color\n"), -1);
	return (ft_atoi(colors[0]) << 16 | ft_atoi(colors[1]) << 8 | ft_atoi(colors[2]));
}

void	get_color(t_info *infos, char *line, int *count)
{	
	*count += 1;
	if (line[0] == 'F' && infos->floor == -1)
		infos->floor = callcul_color(ft_strtrim(&line[1], " \n"));
	else if (line[0] == 'C' && infos->ceilling == -1)
		infos->ceilling = callcul_color(ft_strtrim(&line[1], " \n"));	
}

int is_valid_rgb(int color)
{
	return (color >= 0 && color <= 255);
}