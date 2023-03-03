/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:11 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 23:08:15 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	cub3d_loop(t_collect_data *data)
{
	mlx_hook(data->mlx->mlx_win, 2, 1L << 0, presskey, data);
	mlx_hook(data->mlx->mlx_win, 3, 1L << 1, releaskey, data->player);
	mlx_hook(data->mlx->mlx_win, 17, 1L, esc_hook, data);
	mlx_hook(data->mlx->mlx_win, 4, 1L << 8, mouse_press, data);
	mlx_hook(data->mlx->mlx_win, 5, 1L << 8, mouse_release, data);
	mlx_hook(data->mlx->mlx_win, 6, 1L << 6, handle_mouse, data);
	mlx_loop_hook(data->mlx->mlx, moveplayer, data);
	mlx_loop(data->mlx->mlx);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->img = (t_img_data *)malloc(sizeof(t_img_data));
	if (!mlx->img)
		return (ft_error("memory was not allocated!!"), exit(1));
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, \
	SCREENWIDTH, SCREENHEIGHT, "Awesome cub3d!");
	mlx->img->img = mlx_new_image(mlx->mlx, SCREENWIDTH, SCREENHEIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, \
&mlx->img->bits_per_pixel, &mlx->img->line_length, &mlx->img->endian);
}

int	main(int arc, char **arv)
{
	t_map_info		map_info;
	t_collect_data	all_data;
	t_player		player;
	t_mlx			mlx;
	t_img_data		mini_map;

	if (arc == 2)
	{
		_parsing(arv[1], &map_info);
		init_player(&player, map_info.map);
		init_mlx(&mlx);
		mini_map.img = mlx_new_image(mlx.mlx, MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
		mini_map.addr = mlx_get_data_addr(mini_map.img, \
	&mini_map.bits_per_pixel, &mini_map.line_length, &mini_map.endian);
		all_data.map_info = &map_info;
		all_data.mlx = &mlx;
		all_data.player = &player;
		all_data.mini_map = &mini_map;
		collect_all_texture(&all_data);
		cub3d_loop(&all_data);
	}
	ft_error("invalid argument!!");
}
