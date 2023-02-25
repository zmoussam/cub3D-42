/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectData.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:52:17 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/25 15:03:37 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture *get_texture_data(void* mlx, char *filename)
{
    t_texture *texture;
    texture = (t_texture *)malloc(sizeof(t_texture));
    if (!texture)
        return (NULL);
    texture->img = mlx_xpm_file_to_image(mlx, filename, &texture->_width, &texture->_heigth);
    texture->addr = (int *)mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
    &texture->line_length, &texture->endian);
    return (texture);
}