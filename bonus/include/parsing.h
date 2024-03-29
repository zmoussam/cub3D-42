/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:01:19 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 21:48:43 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_index
{
	size_t	i;
	size_t	j;
}			t_index;

typedef struct s_map_info
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**map;
	int		has_no;
	int		has_so;
	int		has_we;
	int		has_ea;
	int		has_f;
	int		has_c;
	int		maplines;
	int		lenghtlines;
	int		c_floor;
	int		c_ceilling;
	int		lineindex;
	size_t	maxlenmap;
}			t_map_info;

char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_check_cub(char *filename);
int		countline(char *file);
void	ft_reading_maps(t_map_info *jeu, char *file);
void	initializer(t_map_info *game);
int		check_line(char *clean_ptr, t_map_info *game);
void	parse_direction(t_map_info *game, char *line);
int		ea_direct(t_map_info *game, char *line);
int		no_direct(t_map_info *game, char *line);
int		we_direct(t_map_info *game, char *line);
int		so_direct(t_map_info *game, char *line);
char	*ft_strcpy(char *dest, char *src);
char	*remove_prefix(char *line, char *prefix);
void	parse_color(t_map_info *game, char *cleanline);
int		receive_rgb_color(char *color);
int		isalldigits(const char *s);
int		rgb_converter(char **rgbclr);
int		_parse_map(t_map_info *game, char *first_line, int fd);
int		valid_n(char **map, size_t i, size_t j);
int		valid_e(char **map, size_t i, size_t j);
int		valid_s(char **map, size_t i, size_t j, t_map_info *game);
int		valid_w(char **map, size_t i, size_t j);
int		check_valid_map(t_index index, char **map, \
t_map_info *game, int *counter);
int		checkmap(t_map_info *game);
int		check_texture(t_map_info *game, char *cleanline);
void	_parsing(char *file, t_map_info *game);
void	findmaxline(t_map_info *game);
int		checkgamma(char *pathcolor);
size_t	delet_espaces_at_the_end(char *chaine);
void	ft_error(char *error_name);
void	_parse_map2(t_map_info *game);
void	parse_color_for_floor(t_map_info *game, char *cleanline, char *str);
void	parse_color_for_ceilling(t_map_info *game, \
char *cleanline, char *str);
void	free_color(char **color);
#endif
