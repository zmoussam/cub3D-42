/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:35:41 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/01 01:54:51 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	memory_error(void)
{
	write(2, "error : memory wasn't allocated\n", 20);
	exit(1);
}

void	parse_color(t_map_info *game, char *cleanline)
{
	char	*floor;
	char	*ceilling;

	if (!ft_strncmp(cleanline, "F", 1) && game->has_f == -1)
	{
		char *str;

		str = remove_prefix(cleanline, "F ");
		floor = remove_caract(str, " ");
		if (!floor)
			memory_error();
		if(!checkgamma(floor))
			return(printf("path should contain 2 gamma\n"), exit(1), (void)0);
		game->c_floor = receive_rgb_color(floor);
		if (!game->c_floor)
			exit(1);
		game->has_f = 1;
		free(str);
	}
	else if (!ft_strncmp(cleanline, "C", 1) && game->has_c == -1)
	{
		char *str;

		str = remove_prefix(cleanline, "C ");
		ceilling = remove_caract(str, " ");
		if (!ceilling)
			memory_error();
		if(!checkgamma(ceilling))
			return(printf("path should contain 2 gamma\n"), exit(1), (void)0);
		game->c_ceilling = receive_rgb_color(ceilling);
		if (!game->c_ceilling)
			exit(1);
		game->has_c = 1;
	}
}

int	receive_rgb_color(char *color)
{
	char	**rgbclr;
	int		decrgb;
	int		i;

	i = 0;
	rgbclr = ft_split(color, ',');
	if (!rgbclr)
		memory_error();
	while (rgbclr[i])
		i++;
	if (i != 3)
	{
		free(rgbclr);
		printf("error: there are more or less than 3 numbers!! \n");
		exit(0);
	}
	decrgb = rgb_converter(rgbclr);
	if (!decrgb)
		return (write(2, "Error : RGB colors are not available \n", 39), 0);
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
			return (0);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(rgbclr[i]) < 0 || ft_atoi(rgbclr[i]) > 255)
			return (0);
		i++;
	}
	color = ft_atoi(rgbclr[0]) << 16 | ft_atoi(rgbclr[1]) << \
8 | ft_atoi(rgbclr[2]);
	return (color);
}
