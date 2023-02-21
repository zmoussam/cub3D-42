/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:52:17 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/21 21:32:43 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
    distaceprojplan = (SCREENWIDTH / 2) / tan(VIEW_ANGLE / 2);
    wallstripheight = (TILE_SIZE / ray.distance) * distanceprojplan;
*/

t_texture_data *get_texture_data(void* mlx, char *filename)
{
    t_texture_data *texture;
    // int *tmp;
    texture = (t_texture_data *)malloc(sizeof(t_texture_data));
    if (!texture)
        return (NULL);
    texture->texture.img = mlx_xpm_file_to_image(mlx, filename, &texture->_width, &texture->_heigth);
    // printf("hi\n");
    texture->texture.addr= mlx_get_data_addr(texture->texture.img, &texture->texture.bits_per_pixel, \
    &texture->texture.line_length, &texture->texture.endian);
    return (texture);
}