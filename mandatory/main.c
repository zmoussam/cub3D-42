/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:11 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/03 00:40:45 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	esc_hook(t_mlx *mlx)
{
	write(1,"game over!!!\n", 13);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

int main(int argc, char **argv)
{
    t_map_info map_info;
    t_collect_data all_data;
    t_player player;
    t_mlx mlx;
    t_img_data img;
    t_texture *texture;
    int i ;
    i = 0;
    if (argc == 2)
    {
            base_parsing(argv[1], &map_info);
            init_player(&player, map_info.map);
            mlx.mlx = mlx_init();
            mlx.mlx_win = mlx_new_window(mlx.mlx, SCREENWIDTH, SCREENHEIGHT, "CUB3D!");
            img.img = mlx_new_image(mlx.mlx, SCREENWIDTH, SCREENHEIGHT);
            if (!img.img)
                return (ft_error("img not found!!"), exit(1), 0);
            img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
            texture = get_texture_data(mlx.mlx, &map_info);
            mlx.img = &img;
            all_data.map_info = &map_info;
            all_data.mlx = &mlx;
            all_data.player = &player;
            all_data.texture = texture;
            
            mlx_hook(mlx.mlx_win, 2, 1L << 0, presskey, all_data.player);
            mlx_hook(mlx.mlx_win, 3, 1L << 0, releaskey, all_data.player);
            mlx_hook(mlx.mlx_win, 17, 1L, esc_hook, &mlx);
            mlx_loop_hook(mlx.mlx, moveplayer, &all_data);
            mlx_loop(mlx.mlx);
    }
    else
       ft_error("invalid argument!!");
}