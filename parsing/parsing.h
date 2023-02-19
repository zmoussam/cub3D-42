/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:06:26 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/19 19:09:04 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

// #include "../cub3d.h"
#include "./get_next_line/get_next_line.h"
 #include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "../libft_zack/libft.h"
#include<errno.h>

typedef struct s_info{
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    int     floor;
    int     ceilling;
    char    **map;
} t_info;

typedef enum map_token
{
    EMPTY_LINE,
    INVALIDE_LINE,
    DIRECTION,
    RGB_COLOR, 
    MAP,
} t_map_token;

char	*get_texture_path(char *line);
void	get_direction(t_info *infos, char *line, int *count);
int     parse_color(char **colors);
int     check_if_empty(char *color);
int     callcul_color(char *rgb_color);
void	get_color(t_info *infos, char *line, int *count);
int     is_valid_rgb(int color);
void	check_extention(char *file_name);
int     get_token(char *line);
int     get_infos(t_info *infos, int fd);
int     parsing(t_info *infos, char *file_name);
void	_error(char *error_name);
void    free_colors(char **colors);
void	free_map_list(t_list *map, int height);
int     check_wals(char *border, int index);
int     get_map(int fd, t_info *infos, char *first_line);
int     map_list_to_array(t_list *map, t_info *infos, int height);
int     get_map_content(int fd, t_list **map);

#endif
