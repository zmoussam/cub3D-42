/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getTextureInfo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:02:59 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 20:51:51 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

char	**get_texture_path(t_map_info *map_file)
{
	char	**texture_files;

	texture_files = (char **)malloc(sizeof(char *) * 5);
	if (!texture_files)
		return (ft_error("memory was not allocated!!"), exit(1), NULL);
	texture_files[0] = map_file->so;
	texture_files[1] = map_file->no;
	texture_files[2] = map_file->we;
	texture_files[3] = map_file->ea;
	texture_files[4] = NULL;
	return (texture_files);
}

t_texture	*get_wall_texture(void *mlx, t_map_info *map_file)
{
	t_texture	*texture;
	char		**texture_files;
	int			i;

	texture = (t_texture *)malloc(sizeof(t_texture) * 4);
	if (!texture)
		return (ft_error("memory was not allocated"), exit(1), NULL);
	texture_files = get_texture_path(map_file);
	i = 0;
	while (i < 4)
	{
		texture[i].info = (t_img_data *)malloc(sizeof(t_img_data));
		if (!texture[i].info)
			return (ft_error("memory was not allocated"), exit(1), NULL);
		texture[i].info->img = mlx_xpm_file_to_image(mlx, texture_files[i],
				&texture[i]._width, &texture[i]._heigth);
		if (!texture[i].info->img)
			return (ft_error("texture not found!!"), exit(1), NULL);
		texture[i].info->int_addr = (int *)mlx_get_data_addr(texture[i].info->\
			img, &(texture[i].info->bits_per_pixel), \
			&(texture[i].info->line_length), &(texture[i].info->line_length));
		i++;
	}
	free(texture_files);
	return (texture);
}

t_texture	*get_texture(t_mlx *mlx, char *file_name)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (!texture)
		return (ft_error("memory was not allocated"), exit(1), NULL);
	texture->info = (t_img_data *)malloc(sizeof(t_img_data));
	if (!texture->info)
		return (ft_error("memory was not allocated"), exit(1), NULL);
	texture->info->img = mlx_xpm_file_to_image(mlx->mlx, file_name, \
		&texture->_width, &texture->_heigth);
	if (!texture->info->img)
		return (ft_error("texture not found!!"), exit(1), NULL);
	return (texture);
}

t_texture	**get_weapon_texture(t_mlx *mlx)
{
	t_texture	**weapon;

	weapon = (t_texture **)malloc(sizeof(t_texture *) * 3);
	if (!weapon)
		return (NULL);
	weapon[0] = get_texture(mlx, "./assets/weapon_1.xpm");
	weapon[1] = get_texture(mlx, "./assets/weapon_2.xpm");
	weapon[2] = get_texture(mlx, "./assets/weapon_3.xpm");
	return (weapon);
}

t_texture	**get_digit_texture(t_mlx *mlx)
{
	t_texture	**digit;

	digit = (t_texture **)malloc(sizeof(t_texture *) * 10);
	if (!digit)
		return (NULL);
	digit[0] = get_texture(mlx, "./assets/0.xpm");
	digit[1] = get_texture(mlx, "./assets/1.xpm");
	digit[2] = get_texture(mlx, "./assets/2.xpm");
	digit[3] = get_texture(mlx, "./assets/3.xpm");
	digit[4] = get_texture(mlx, "./assets/4.xpm");
	digit[5] = get_texture(mlx, "./assets/5.xpm");
	digit[6] = get_texture(mlx, "./assets/6.xpm");
	digit[7] = get_texture(mlx, "./assets/7.xpm");
	digit[8] = get_texture(mlx, "./assets/8.xpm");
	digit[9] = get_texture(mlx, "./assets/9.xpm");
	return (digit);
}
