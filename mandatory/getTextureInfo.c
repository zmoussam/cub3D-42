/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getTextureInfo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:02:59 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 00:44:59 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

t_texture *get_texture_data(void* mlx, t_map_info *map_file)
{
    t_texture *texture;
    char **texture_files;
    int i;

    texture_files = (char **)malloc(sizeof(char *) * 5);
    if (!texture_files)
        return (ft_error("memory was not allocated!!"), exit(1), NULL);
    texture = (t_texture *)malloc(sizeof(t_texture) * 4);
    if (!texture)
        return (ft_error("memory was not allocated"), exit(1), NULL);
    texture_files[0] = map_file->so;
    texture_files[1] = map_file->no;
    texture_files[2] = map_file->we;
    texture_files[3] = map_file->ea;
    texture_files[4] = NULL;
    i = 0;
    while(i < 4)
    {
        texture[i].info = (t_img_data *)malloc(sizeof(t_img_data));
        if (!texture[i].info)
             return (ft_error("memory was not allocated"), exit(1), NULL);
        texture[i].info->img = mlx_xpm_file_to_image(mlx, texture_files[i], &texture[i]._width, &texture[i]._heigth);
        if (!texture[i].info->img)
            return (ft_error("texture not found!!"), exit(1), NULL);
        texture[i].info->int_addr = (int *)mlx_get_data_addr(texture[i].info->img, \
        &(texture[i].info->bits_per_pixel), &(texture[i].info->line_length), &(texture[i].info->line_length));
        i++;
    }
    free(texture_files);
    return (texture);
}