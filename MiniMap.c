/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:05:17 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/25 19:05:20 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void put_minimap(t_player_data *player)
{
  int i = 0; 
  int j = 0; 
  while(i < MAPHEIGHT * TILE_SIZE * MINI_MAP_FACTOR)
  {
    j = 0;
    while(j <  MAPWIDTH * TILE_SIZE * MINI_MAP_FACTOR)
    {
        if (fmod(i, (TILE_SIZE * MINI_MAP_FACTOR)) == 0 || fmod(j, (TILE_SIZE * MINI_MAP_FACTOR)) == 0) 
           my_mlx_pixel_put(player->img, j, i, 0x00000000);
        if (player->map.map[(int)(i / (TILE_SIZE * MINI_MAP_FACTOR))][(int)(j / (TILE_SIZE * MINI_MAP_FACTOR))] == '1')
	        my_mlx_pixel_put(player->img, j, i, 0x00000000);
        else 
          my_mlx_pixel_put(player->img, j, i, 0x00FFFFFF);
        j++;
    }
    i++;
  }
  put_player(player);
}

void put_player(t_player_data *player)
{
  t_ray ray;
  double ray_angle;
  double angle_inc;
  int count;
  angle_inc = VIEW_ANGLE / 8;
  ray_angle = player->viewangle - (VIEW_ANGLE / 2);
  count= 0;
  while (count < 8)
  {
    ray.angle = ray_angle;
    get_ray_direction(&ray);
    drawline(player,  player->position.x + (cos(ray.angle) * 80), player->position.y + (sin(ray.angle) * 80));
    ray_angle += angle_inc;
    count++;
  }
}

void drawline(t_player_data *player, double x, double y)
{
    int dx;
    int dy;
    int steps;
    int i;

    double xx;
    double yy;
    double xinc;
    double yinc;
    
    dx = (x - player->position.x) * MINI_MAP_FACTOR;
    dy = (y - player->position.y) * MINI_MAP_FACTOR;

    if(abs(dx) > abs(dy))
      steps = abs(dx);
    else
      steps = abs(dy);

    xinc = dx / (float)steps;
    yinc = dy / (float)steps;

    xx = player->position.x * MINI_MAP_FACTOR;
    yy = player->position.y * MINI_MAP_FACTOR;
    i = 0;
    while (i <= steps)
    {
       if (player->map.map[(int)(yy / (TILE_SIZE * MINI_MAP_FACTOR))][(int)(xx / (TILE_SIZE * MINI_MAP_FACTOR))] == '1')
          break;
        my_mlx_pixel_put(player->img, xx, yy, 0x00FF4F37);
        xx = xx + xinc;
        yy = yy + yinc;
        i++;
    }
}