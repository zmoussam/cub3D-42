/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putTexture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:48:13 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 23:17:53 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	collect_all_texture(t_collect_data *data)
{
	data->wall = get_wall_texture(data->mlx->mlx, data->map_info);
	data->shoot_target = get_texture(data->mlx, "./assets/shooting_target.xpm");
	data->weapon = get_weapon_texture(data->mlx);
	data->digit = get_digit_texture(data->mlx);
	data->amo = get_texture(data->mlx, "./assets/amo.xpm");
}

void	put_weapon(t_mlx *mlx, t_texture **weapon, int *check_shoot,
		int count_shoot)
{
	static int	r;

	r++;
	if (*check_shoot == 1 && count_shoot > 0)
	{
		if (r == 1)
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
		weapon[0]->info->img, SCREENWIDTH - 250 - weapon[0]->_width, \
		SCREENHEIGHT - weapon[0]->_heigth);
		else if (r == 2)
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
			weapon[1]->info->img, SCREENWIDTH - 250 - weapon[1]->_width, \
			SCREENHEIGHT - weapon[1]->_heigth);
		else if (r == 3)
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, weapon[2]->info->\
img, SCREENWIDTH - 250 - weapon[2]->_width, SCREENHEIGHT - weapon[2]->_heigth);
	}
	else
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, weapon[0]->info->img, \
SCREENWIDTH - 250 - weapon[0]->_width, SCREENHEIGHT - weapon[0]->_heigth);
	if (r == 3)
	{
		*check_shoot = 0;
		r = 0;
	}
}

void	put_count_amo(t_mlx *mlx, t_texture **digit, int count_shoot)
{
	if (count_shoot == 100)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, digit[1]->info->img, \
				SCREENWIDTH - 204, SCREENHEIGHT - 148);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, digit[0]->info->img, \
			SCREENWIDTH - 136, SCREENHEIGHT - 148);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, digit[0]->info->img, \
				SCREENWIDTH - 68, SCREENHEIGHT - 148);
	}
	else if (count_shoot >= 10)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
digit[count_shoot / 10]->info->img, SCREENWIDTH - 136, SCREENHEIGHT - 148);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
digit[count_shoot % 10]->info->img, SCREENWIDTH - 68, SCREENHEIGHT - 148);
	}
	else
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, \
digit[count_shoot]->info->img, SCREENWIDTH - 68, SCREENHEIGHT - 148);
}

void	put_all_texture(t_collect_data *data)
{
	put_minimap(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, \
	data->mlx->img->img, 0, 0);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, \
	data->shoot_target->info->img, (SCREENWIDTH / 2) - 15, \
	(SCREENHEIGHT / 2) - 15);
	put_count_amo(data->mlx, data->digit, data->player->count_shoot);
	put_weapon(data->mlx, data->weapon, &data->player->check_shoot, \
	data->player->count_shoot);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, \
	data->amo->info->img, SCREENWIDTH - 74, SCREENHEIGHT - 84);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, \
	data->mini_map->img, 10, SCREENHEIGHT - \
	(SCREENHEIGHT * MINI_MAP_FACTOR) - 10);
}