/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:06:26 by zmoussam          #+#    #+#             */
/*   Updated: 2022/11/18 22:59:07 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

// #include "../cub3d.h"
#include "../get_next_line/get_next_line.h"
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
#endif
