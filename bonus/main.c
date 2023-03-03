/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:11 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 16:43:38 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	esc_hook(t_mlx *mlx)
{
	printf("game over!!!\n");
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

int	handle_mouse(int x, int y, t_collect_data *data)
{
	y = 0;
	if (data->player->release_mouse)
	{
		if (x > data->mouse_pos)
			data->player->turndirection = 1;
		else if (x < data->mouse_pos)
			data->player->turndirection = -1;
		data->mouse_pos = x;
	}
	return (0);
}

int	mouse_press(int key, int x, int y, t_collect_data *data)
{
	if (key == 1 && x >= 0 && x <= SCREENWIDTH && y >= 0 && y <= SCREENHEIGHT)
	{
		data->mouse_pos = x;
		data->player->release_mouse = 1;
	}
	return (0);
}

int	mouse_release(int key, int x, int y, t_collect_data *data)
{
	(void)x;
	(void)y;
	if (key == 1)
	{
		data->player->release_mouse = 0;
		data->player->turndirection = 0;
	}
	return (0);
}
void cub3d_loop(t_collect_data *data)
{
	mlx_hook(data->mlx->mlx_win, 2, 1L << 0, presskey, data->player);
	mlx_hook(data->mlx->mlx_win, 3, 1L << 1, releaskey, data->player);
	mlx_hook(data->mlx->mlx_win, 17, 1L, esc_hook, data->mlx);
	mlx_hook(data->mlx->mlx_win, 4, 1L << 8, mouse_press, data);
	mlx_hook(data->mlx->mlx_win, 5, 1L << 8, mouse_release, data);
	mlx_hook(data->mlx->mlx_win, 6, 1L << 6, handle_mouse, data);
	mlx_loop_hook(data->mlx->mlx, moveplayer, data);
	mlx_loop(data->mlx->mlx);
}

void collect_all_texture(t_collect_data *data)
{
	data->texture = get_wall_texture(data->mlx->mlx, data->map_info);
	data->shoot_target = get_texture(data->mlx, "./assets/shooting_target.xpm");
	data->weapon = get_weapon_texture(data->mlx);
	data->digit = get_digit_texture(data->mlx);
	data->amo = get_texture(data->mlx, "./assets/amo.xpm");
}
void init_mlx(t_mlx *mlx)
{
	mlx->img = (t_img_data *)malloc(sizeof(t_img_data));
	if(!mlx->img)
		return (ft_error("memory was not allocated!!"), exit(1));
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, SCREENWIDTH, SCREENHEIGHT, "Awesome cub3d!");
	mlx->img->img = mlx_new_image(mlx->mlx, SCREENWIDTH, SCREENHEIGHT);
	mlx->img->addr = mlx_get_data_addr(mlx->img->img, &mlx->img->bits_per_pixel, &mlx->img->line_length, &mlx->img->endian);
}

int	main(int arc, char **arv)
{
	t_map_info map_info;
	t_collect_data all_data;
	t_player player;
	t_mlx mlx;
	t_img_data mini_map;
	
	if (arc == 2)
	{
		_parsing(arv[1], &map_info);
		init_player(&player, map_info.map);
		init_mlx(&mlx);
		mini_map.img = mlx_new_image(mlx.mlx, MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
		mini_map.addr = mlx_get_data_addr(mini_map.img, &mini_map.bits_per_pixel, &mini_map.line_length, &mini_map.endian);
		all_data.map_info = &map_info;
		all_data.mlx = &mlx;
		all_data.player = &player;
		all_data.mini_map = &mini_map;
		
		collect_all_texture(&all_data);
		cub3d_loop(&all_data);
	}
	else
		ft_error("invalid argument!!");
}