/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:35:41 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/02 18:22:51 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/parsing.h"

void	parse_color(t_map_info *game, char *cleanline)
{
	char	*floor;
	char	*ceilling;
	char	*str;

	if (cleanline[0] == 'F')
	{
		str = remove_prefix(cleanline, "F ");
		floor = ft_strtrim(str, " ");
		if (!floor)
			return (ft_error("memory was not allocated!!"), exit(1));
		if (!checkgamma(floor))
			return (ft_error("color should contain 2 gamma"), exit(1));
		game->c_floor = receive_rgb_color(floor);
		if (game->c_floor == -1)
			exit(1);
		game->has_f++;
		free(floor);
		free(str);
	}
	else if (cleanline[0] == 'C')
	{
		str = remove_prefix(cleanline, "C ");
		ceilling = ft_strtrim(str, " ");
		if (!ceilling)
			return (ft_error("memory was not allocated!!"), exit(1));
		if (!checkgamma(ceilling))
			return(ft_error("color should contain 2 gamma\n"), exit(1));
		game->c_ceilling = receive_rgb_color(ceilling);
		if (game->c_ceilling == -1)
			exit(1);
		game->has_c++;
		free(str);
		free(ceilling);
	}
	free(cleanline);
}

void	free_color(char **color)
{
	int	i;
	i = 0;

	while (color[i])
		free(color[i++]);
	free(color);
}

int	receive_rgb_color(char *color)
{
	char	**rgbclr;
	int		decrgb;
	int		i;

	i = 0;
	rgbclr = ft_split(color, ',');
	if (!rgbclr)
		return (ft_error("memory was not allocated!!"), exit(1), -1);
	while (rgbclr[i])
		i++;
	if (i != 3)
	{
		free_color(rgbclr);
		ft_error("there are more or less than 3 numbers!!");
		exit(0);
	}
	decrgb = rgb_converter(rgbclr);
	free_color(rgbclr);
	if (decrgb == -1)
		return (ft_error("RGB colors are not available"), -1);
	return (decrgb);
}

int	isalldigits(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && !ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	rgb_converter(char **rgbclr)
{
	int	i;
	int	color;

	i = 0;
	while (rgbclr[i])
	{
		if (!isalldigits(rgbclr[i]))
			return (-1);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(rgbclr[i]) < 0 || ft_atoi(rgbclr[i]) > 255)
			return (-1);
		i++;
	}
	color = ft_atoi(rgbclr[0]) << 16 | ft_atoi(rgbclr[1]) << 8 | ft_atoi(rgbclr[2]);
	return (color);
}
