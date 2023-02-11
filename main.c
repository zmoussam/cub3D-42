/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:11 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/11 22:53:22 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define mapWidth 17
#define mapHeight 17
#define screenWidth 640
#define screenHeight 480
#define PI 3.14159265
#define VIEW_ANGLE 30 * PI / 180;
#include<mlx.h>
#include <math.h>
#include<stdlib.h>
#include<stdio.h>
#include "cub3d.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
  t_player_data player;

  player.x = 248;
  player.y = 248;
  player.radius = 14 ;
  player.movespeed = 2;
  player.rotationangle = PI / 2;
  player.rotationspeed = 5 * (PI / 180);
  player.turndirection = 0;
  player.walkdirection = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 17 * 30, 17 * 30, "Awesome cub3d!");
	img.img = mlx_new_image(mlx, 17 * 30, 17 * 30);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
  player.img = &img;
  player.mlx = mlx;
  player.mlx_win = mlx_win;
  put_map(&player);
  put_player(&player);
	draw_view_angle(&player);
  mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
  mlx_hook(mlx_win, 2, 1L << 0, presskey , &player);
  mlx_hook(mlx_win, 3, 1L << 0, releaskey , &player);
  mlx_loop_hook(mlx, &key_hook, &player);
	mlx_loop(mlx);
}
