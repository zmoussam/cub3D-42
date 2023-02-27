/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:05:41 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/27 01:22:53 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"
#include"string.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void drawline(t_collect_data *data,t_cordinates player_pos, t_cordinates ray_limit)
{
    int dx;
    int dy;
    int steps;
    int i;

    double xx;
    double yy;
    double xinc;
    double yinc;
    
    dx = (ray_limit.x - player_pos.x);
    dy = (ray_limit.y - player_pos.y);

    if(abs(dx) > abs(dy))
      steps = abs(dx);
    else
      steps = abs(dy);

    xinc = dx / (float)steps;
    yinc = dy / (float)steps;

    xx = player_pos.x;
    yy = player_pos.y;
    i = 0;
    while (i <= steps)
    {
        my_mlx_pixel_put(data->mini_map, xx, yy, 0x00FF0000);
        xx = xx + xinc;
        yy = yy + yinc;
        i++;
    }
}
void put_player(t_collect_data *data)
{
  t_cordinates player_pos;
  t_cordinates ray_limit;;
  t_ray ray;
  
  player_pos.x = MINI_MAP_WIDTH / 2;
  player_pos.y = MINI_MAP_HEIGHT / 2;
  
  double ray_angle;
  double angle_inc;
  int count;
  angle_inc = VIEW_ANGLE / 15;
  ray_angle = data->player->viewangle - (VIEW_ANGLE / 2);
  count= 0;
  while (count < 15)
  {
    ray.angle = ray_angle;
    get_ray_direction(&ray);
    ray_limit.x =  player_pos.x + (cos(ray.angle) * 10);
    ray_limit.y = player_pos.y + (sin(ray.angle) * 10);
    drawline(data, player_pos, ray_limit);
    ray_angle += angle_inc;
    count++;
  }
}
int get_minimap_collor(char **map, t_cordinates pos)
{
  if (map[(int)(pos.y / (TILE_SIZE))][(int)(pos.x / (TILE_SIZE))] == '1')
    return (0x00000000);
  else
    return (0x00808080);
}

void put_minimap(t_collect_data *data)
{
  int i;
  int j;
  int collor;
  t_cordinates player_pos;
  t_cordinates start_minimap;
  
  player_pos = data->player->position;
  start_minimap.x = round(player_pos.x - (SCREENWIDTH * MINI_MAP_FACTOR / 2));
  start_minimap.y = round(player_pos.y - (SCREENHEIGHT * MINI_MAP_FACTOR / 2));
  i = 0;
  j = 0;
  while(i < MINI_MAP_HEIGHT)
  {
    j = 0;
    start_minimap.x = round(player_pos.x - (SCREENWIDTH * MINI_MAP_FACTOR / 2));
    while(j < MINI_MAP_WIDTH)
    {
      if (start_minimap.x > 0 && start_minimap.x < 33 * TILE_SIZE && start_minimap.y > 0 && start_minimap.y < 34 * TILE_SIZE)
      {
        collor = get_minimap_collor(data->map_info->map, start_minimap);
        my_mlx_pixel_put(data->mini_map, j, i, collor);
      }
      else 
        my_mlx_pixel_put(data->mini_map, j, i, 0x00000000);
      j++;
      start_minimap.x++;
    }
    start_minimap.y++;
    i++;
  }
  put_player(data);
}

