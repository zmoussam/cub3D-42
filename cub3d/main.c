/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:11 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/26 00:32:04 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int main()
{
    t_map_info map_info;
    t_collect_data all_data;
    t_player player;
    t_mlx mlx;
    t_img_data img;
    
    map_info.map = (char **)malloc(sizeof(char *) * 18);
    if (!map_info.map)
        return 0;
    init_map(&map_info);
    init_player(&player, map_info.map);
    mlx.mlx = mlx_init();
    mlx.mlx_win = mlx_new_window(mlx.mlx, SCREENWIDTH, SCREENHEIGHT, "Awesome cub3d!");
    img.img = mlx_new_image(mlx.mlx, SCREENWIDTH, SCREENHEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    mlx.img = &img;
    all_data.map_info = &map_info;
    all_data.mlx = &mlx;
    all_data.player = &player;
    
    mlx_hook(mlx.mlx_win, 2, 1L << 0, presskey, all_data.player);
    mlx_hook(mlx.mlx_win, 3, 1L << 0, releaskey, all_data.player);
    mlx_loop_hook(mlx.mlx, moveplayer, &all_data);
    mlx_loop(mlx.mlx);
}