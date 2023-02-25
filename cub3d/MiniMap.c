/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:05:41 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/26 00:12:51 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"
#include"string.h"

void  get_ray_direction(t_ray *ray)
{
    if (ray->angle > 0 && ray->angle < M_PI)
    {
      ray->isfacingdown = 1;
      ray->isfacingup = 1;
    }
    else
    {
      ray->isfacingdown = 0;
      ray->isfacingup = -1;
    }
    if (ray->angle < (M_PI / 2) || ray->angle > (3 * M_PI / 2))
    {
      ray->isfacingright = 1;
      ray->isfacingleft = 1;
    }
    else
    {
      ray->isfacingright = 0;
      ray->isfacingleft = -1;
    }
    
}
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void drawline(t_collect_data *data, double x, double y)
{
    int dx;
    int dy;
    int steps;
    int i;

    double xx;
    double yy;
    double xinc;
    double yinc;
    
    dx = (x - data->player->position.x) * MINI_MAP_FACTOR;
    dy = (y - data->player->position.y) * MINI_MAP_FACTOR;

    if(abs(dx) > abs(dy))
      steps = abs(dx);
    else
      steps = abs(dy);

    xinc = dx / (float)steps;
    yinc = dy / (float)steps;

    xx = data->player->position.x * MINI_MAP_FACTOR;
    yy = data->player->position.y * MINI_MAP_FACTOR;
    i = 0;
    while (i <= steps)
    {
       if (data->map_info->map[(int)(yy / (TILE_SIZE * MINI_MAP_FACTOR))][(int)(xx / (TILE_SIZE * MINI_MAP_FACTOR))] == '1')
          break;
        my_mlx_pixel_put(data->mlx->img, xx, yy, 0x00FF0000);
        xx = xx + xinc;
        yy = yy + yinc;
        i++;
    }
}
void put_player(t_collect_data *data)
{
  t_ray ray;
  double ray_angle;
  double angle_inc;
  int count;
  angle_inc = VIEW_ANGLE / 8;
  ray_angle = data->player->viewangle - (VIEW_ANGLE / 2);
  count= 0;
  while (count < 8)
  {
    ray.angle = ray_angle;
    get_ray_direction(&ray);
    drawline(data, data->player->position.x + (cos(ray.angle) * 80), data->player->position.y + (sin(ray.angle) * 80));
    ray_angle += angle_inc;
    count++;
  }
}

void put_minimap(t_collect_data *data)
{
  int i = 0; 
  int j = 0;
  int len;
  int index_x;
  int index_y;
  while(i < SCREENHEIGHT * MINI_MAP_FACTOR)
  {
    j = 0;
    index_y = (int)(i / (TILE_SIZE * MINI_MAP_FACTOR));
    len = strlen(data->map_info->map[index_y]);
    index_x = 0;
    while(j < SCREENWIDTH * MINI_MAP_FACTOR && index_x < len)
    {
      if (data->map_info->map[index_y][index_x] == '1')
        my_mlx_pixel_put(data->mlx->img, j, i, 0x00458712);
      else if (data->map_info->map[index_y][index_x] == '0')
        my_mlx_pixel_put(data->mlx->img, j, i, 0x00FFFFFF);
      else if (data->map_info->map[index_y][index_x] != 32)
       my_mlx_pixel_put(data->mlx->img, j, i, 0x00FFFFFF);
      j++;
      index_x = (int)(j / (TILE_SIZE * MINI_MAP_FACTOR));
    }
    i++;
  }
  put_player(data);
}

