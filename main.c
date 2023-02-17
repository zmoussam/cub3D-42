/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:11 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/17 22:35:32 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMap[MAPWIDTH][MAPHEIGHT]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1},
  {1,0,0,1,0,0,0,0,1,0,0,0,1,1,0,0,1},
  {1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1},
  {1,0,0,1,1,0,0,0,0,0,0,0,1,0,1,0,1},
  {1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1},
  {1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1},
  {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
  {1,0,0,0,1,0,1,1,0,1,1,0,1,0,0,0,1},
  {1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1},
  {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img_data	img;
  t_player_data player;

  player.radius = 5;
  player.position.x = (SCREENWIDTH / 2); 
  player.position.y = (SCREENHEIGHT / 2);
  player.movespeed = 2;
  player.viewangle = PI / 2;
  player.movesleft_or_right = 0;
  player.rotationspeed = 5 * (PI / 180);
  player.turndirection = 0;
  player.walkdirection = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SCREENWIDTH, SCREENHEIGHT, "Awesome cub3d!");
	img.img = mlx_new_image(mlx, SCREENWIDTH, SCREENHEIGHT);
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
  mlx_loop_hook(mlx, &moveplayer, &player);
	mlx_loop(mlx);
}
