/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:13:48 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/12 14:48:31 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
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
           if (worldMap[(int)(j / TITE_SIZE)][(int)(i / TITE_SIZE)] == 1)
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
        if (i % TITE_SIZE == 0 || j % TITE_SIZE == 0) 
          my_mlx_pixel_put(player->img, j, i, 0x00421337);
        else if (worldMap[(int)(i / TITE_SIZE)][(int)(j / TITE_SIZE)] == 1)
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
    
    for (i = 0; i <= steps; i++)
    {
      if (worldMap[(int)(yy / TITE_SIZE)][(int)(xx / TITE_SIZE)] == 1)
          break;
        my_mlx_pixel_put(player->img, round(xx), round(yy), 0x00FF0000);
        xx = xx + xinc;
        yy = yy + yinc;
    }
}
void draw_view_angle(t_player_data *player)
{
    double negatif_angle;
    double positif_angle;

    negatif_angle = player->viewangle - VIEW_ANGLE;
    positif_angle = player->viewangle + VIEW_ANGLE;
    while(negatif_angle < player->viewangle)
    {
        drawline(player, player->x + (cos(negatif_angle) * SCREENWIDTH) + (player->radius / 2), \
        player->y + (sin(negatif_angle) * SCREENHEIGHT) + (player->radius / 2));
        negatif_angle += 1 * PI / 180;
    }
    while(positif_angle >= player->viewangle)
    {    drawline(player, player->x + (cos(positif_angle) * SCREENWIDTH) + (player->radius / 2), \
        player->y + (sin(positif_angle) * SCREENHEIGHT) + (player->radius / 2));
        positif_angle -= 1 * PI / 180;
    } 
}
