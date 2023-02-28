/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getTextureInfo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:02:59 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/28 21:46:09 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

t_texture *get_texture_data(void* mlx, t_map_info *map_file)
{
    t_texture *texture;
    char **texture_files;
    int i;

    i = 0;
    texture_files = (char **)malloc(sizeof(char *) * 5);
    if (!texture_files)
        return (NULL);
    texture = (t_texture *)malloc(sizeof(t_texture) * 4);
    if (!texture)
        return (NULL);
    texture_files[0] = map_file->so;
    texture_files[1] = map_file->no;
    texture_files[2] = map_file->we;
    texture_files[3] = map_file->ea;
    // while (i < 4)
    //     printf("%s\n", texture_files[i++]);
    texture_files[4] = NULL;
    i = 0;
    while(i < 4)
    {
        texture[i].info = (t_img_data *)malloc(sizeof(t_img_data));
        texture[i].info->img = mlx_xpm_file_to_image(mlx, texture_files[i], &texture[i]._width, &texture[i]._heigth);
        texture[i].info->int_addr = (int *)mlx_get_data_addr(texture[i].info->img, \
        &(texture[i].info->bits_per_pixel), &(texture[i].info->line_length), &(texture[i].info->line_length));
        // printf("hna\n");
        i++;
    }
    free(texture_files);
    return (texture);
}