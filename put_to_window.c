/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:13:48 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/13 20:28:03 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void put_player(t_player_data *player)
{
  
    int i = player->x; 
    int j = player->y;
    while(i < player->radius + player->x)
    {
        j = player->y;
        while(j < player->radius + player->y)
        { 
           if (worldMap[(int)(j / TILE_SIZE)][(int)(i / TILE_SIZE)] == 1)
                break;
           my_mlx_pixel_put(player->img, i, j, 0x00203107);
           j++;
        }
        i++;
    }
}

void put_map(t_player_data *player)
{
  int i = 0; 
  int j = 0; 
  while(i < SCREENWIDTH)
  {
    j = 0;
    while(j < SCREENHEIGHT)
    {
        if (i % TILE_SIZE == 0 || j % TILE_SIZE == 0) 
          my_mlx_pixel_put(player->img, j, i, 0x00421337);
        else if (worldMap[(int)(i / TILE_SIZE)][(int)(j / TILE_SIZE)] == 1)
	        my_mlx_pixel_put(player->img, j, i, 0x00133742);
        else 
          my_mlx_pixel_put(player->img, j, i, 0x00909090);
        j++;
    }
    i++;
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
    
    dx = x - (player->x + (player->radius / 2));
    dy = y - (player->y + (player->radius / 2));

    if(abs(dx) > abs(dy))
      steps = abs(dx);
    else
      steps = abs(dy);

    xinc = dx / (float)steps;
    yinc = dy / (float)steps;

    xx = player->x + (player->radius / 2);
    yy = player->y + (player->radius / 2);
    i = 0;
    while (i <= steps)
    {
      if (worldMap[(int)(yy / TILE_SIZE)][(int)(xx / TILE_SIZE)] == 1)
          break;
        my_mlx_pixel_put(player->img, round(xx), round(yy), 0x00FF0000);
        xx = xx + xinc;
        yy = yy + yinc;
        i++;
    }
}
/*
    ///////////////////////////////////
    /////HORIZONTAL INTERSECTION
    ///////////////////////////////////
    
    yintercept = Ay = [Py / TITL_SIZE] * TITL_SIZE

    xintercept = Ax = Px + ((py - Ay) / tan(a))

    ystep = TITL_SIZE

    xstep = ystep / tan(a)

    ///////////////////////////////////
    //////VERTICAL INTERSECTION
    ///////////////////////////////////

    xstep = TITL_SIZE
    ystep = tan(a) * xstep
    
*/

t_cordinates find_intercept(double px, double py, double angleview)
{
  t_cordinates intercept;

  intercept.y = floor(py / TILE_SIZE) * TILE_SIZE;
  intercept.x = px + (intercept.y - py) / tan(angleview);

  return (intercept);
}
// t_cordinates find_horizontal_intersection(double px, double py)
// {
    
// }

// t_cordinates find_vertical_intersection(double px, double py)
// {
    
// }

// double keep_small_distance()
// {
  
// }

// double get_distance()
// {
  
// }

double normangle(double angle)
{
  angle = fmod(angle, 2 * PI);
  if (angle < 0)
      angle = angle + (2 * PI);
  return (angle);
}
void draw_view_angle(t_player_data *player) 
{
    // double negatif_angle;
    // double angle_of_ray;
    
    // angle_of_ray = (60 * (PI / (180 * SCREENWIDTH)));
    // negatif_angle = player->viewangle - (VIEW_ANGLE / 2);

    drawline(player, player->x + (cos(player->viewangle) * SCREENWIDTH) + (player->radius / 2), \
    player->y + (sin(player->viewangle) * SCREENHEIGHT) + (player->radius / 2));
    // while(negatif_angle <= player->viewangle + (VIEW_ANGLE / 2))
    // {
    //     drawline(player, player->x + (cos(negatif_angle) * SCREENWIDTH) + (player->radius / 2), \
    //     player->y + (sin(negatif_angle) * SCREENHEIGHT) + (player->radius / 2));
    //     negatif_angle += angle_of_ray;
    // }
}
