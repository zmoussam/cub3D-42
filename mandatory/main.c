/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:11 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 16:30:11 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	esc_hook(t_mlx *mlx)
{
	write(1, "game over!!!\n", 13);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

void cub3d_loop(t_collect_data *data)
{
	mlx_hook(data->mlx->mlx_win, 2, 1L << 0, presskey, data->player);
	mlx_hook(data->mlx->mlx_win, 3, 1L << 0, releaskey, data->player);
	mlx_hook(data->mlx->mlx_win, 17, 1L, esc_hook, data->mlx);
	mlx_loop_hook(data->mlx->mlx, moveplayer, data);
	mlx_loop(data->mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_collect_data all_data;
	t_map_info map_info;
	t_player player;
	t_mlx mlx;
	t_img_data img;
	
	if (argc == 2)
	{
		_parsing(argv[1], &map_info);
		init_player(&player, map_info.map);
		mlx.mlx = mlx_init();
		mlx.mlx_win = mlx_new_window(mlx.mlx, SCREENWIDTH, SCREENHEIGHT, "CUB3D!");
		img.img = mlx_new_image(mlx.mlx, SCREENWIDTH, SCREENHEIGHT);
		if (!img.img)
			return (ft_error("img not found!!"), exit(1), 0);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		all_data.wall = get_texture_data(mlx.mlx, &map_info);
		mlx.img = &img;
		all_data.map_info = &map_info;
		all_data.mlx = &mlx;
		all_data.player = &player;
		cub3d_loop(&all_data);
	}
	ft_error("invalid argument!!");
}