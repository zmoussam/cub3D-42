/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3Dprojection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:31:14 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/26 18:40:03 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void drawwallcolumn(t_img_data *img, double sx, double sy, double dy, int color)
{
  while (sy < dy && dy <= SCREENHEIGHT && sy >= 0)
  {
    my_mlx_pixel_put(img, sx, sy, color);
    sy++;
  }
}

void draw_wall(t_collect_data *data, t_cordinates ofsset, double wallstripheight, int i)
{
  double top;
  double bottom;
  double dis;
  double wall;
  if (wallstripheight > SCREENHEIGHT)
    wall = SCREENHEIGHT;
  else 
    wall = wallstripheight;
  
  top = (SCREENHEIGHT / 2) - (wall / 2);
  bottom = (SCREENHEIGHT / 2) + (wall / 2);
  while (top < bottom)
  {
    dis = top + (wallstripheight / 2) - (SCREENHEIGHT / 2);
    ofsset.y = round(dis / wallstripheight * data->texture[1]._heigth) ;
    my_mlx_pixel_put(data->mlx->img, i, top, data->texture[1].info->int_addr[(int)round((int)((ofsset.y * data->texture[1]._width) + ofsset.x))]);
    top++;  
  }
}

void draw(t_collect_data *data, t_ray *ray, int i)
{
  double distance_projection_plane;
  double wallstripheight;
  double walltop;
  double wallbottom;
  t_cordinates ofssets;
  distance_projection_plane = (SCREENWIDTH / 2) / (tan(VIEW_ANGLE / 2));
  wallstripheight = (SCREENWIDTH / ray->distancetowall) * WALL_HEIGHT;
  
  walltop = (SCREENHEIGHT / 2) - (wallstripheight / 2);
  if (walltop < 0)
    walltop = 0;
    
  wallbottom = (SCREENHEIGHT / 2) + (wallstripheight / 2); 
  if (wallbottom > SCREENHEIGHT)
    wallbottom = SCREENHEIGHT;
    
  drawwallcolumn(data->mlx->img, i, 0, walltop, 0x00009AFF);
  
  if (ray->wallhitisvert)
    ofssets.x = fmod(ray->vertwallhit.y, TILE_SIZE) / TILE_SIZE * data->texture[0]._width;
  else
    ofssets.x = fmod(ray->horzwallhit.x, TILE_SIZE) / TILE_SIZE * data->texture[0]._width;
  
  draw_wall(data, ofssets, wallstripheight, i);
  drawwallcolumn(data->mlx->img, i, wallbottom, SCREENHEIGHT, 0x00909490);
}