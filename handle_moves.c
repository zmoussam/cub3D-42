/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:35:38 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/13 23:35:06 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_wals(double x, double y, int radius) 
{
    int i = x;
    int j = y;

    while(i < radius + x)
    {
        j = y;
        while(j < radius + y)
        { 
           if (worldMap[(int)(j / TILE_SIZE)][(int)(i / TILE_SIZE)] == 1)
                return 1;
           j++;
        }
        i++;
    }
    return 0;
}

int releaskey(int keycode, t_player_data *player)
{
  if (keycode == KEY_LEFT)
    player->movesleft_or_right = 0;
  if (keycode == KEY_RIGHT)
      player->movesleft_or_right = 0; 
  if (keycode == KEY_DOWN)
    player->walkdirection = 0;  
  if (keycode == KEY_UP)
      player->walkdirection = 0;
  if (keycode == TURN_LEFT)
      player->turndirection = 0;
  if (keycode == TURN_RIGHT)
      player->turndirection = 0;
  return 0;
}

int presskey(int keycode, t_player_data *player)
{
  if (keycode == KEY_LEFT)
    player->movesleft_or_right = -1;
  if (keycode == KEY_RIGHT)
    player->movesleft_or_right = +1;   
  if (keycode == KEY_DOWN)
    player->walkdirection = -1;  
  if (keycode == KEY_UP)
      player->walkdirection = +1;
  if (keycode == TURN_LEFT)
      player->turndirection = -1;
  if (keycode == TURN_RIGHT)
      player->turndirection = +1;
    return 0;
}

int moveplayer(t_player_data *player)
{
  int movestep;
  double left_or_right_angle;
  double tmpangle;
  
  left_or_right_angle = 0;
  player->viewangle += player->turndirection * player->rotationspeed;
  
  if (player->walkdirection != 0 && player->movesleft_or_right != 0)
  {
    movestep = player->movespeed;
    tmpangle = player->walkdirection * (player->viewangle + (player->movesleft_or_right * PI / 4));
    if (!check_wals(player->x + (cos(tmpangle) * movestep), player->y +\
    (sin(tmpangle) * movestep), player->radius))
    {
      player->x += cos(tmpangle) * movestep; 
      player->y += sin(tmpangle) * movestep;
    }
  }
  else if (player->walkdirection != 0)
  {
    movestep = player->walkdirection * player->movespeed;
    if (!check_wals(player->x + (cos(player->viewangle) * movestep), player->y +\
    (sin(player->viewangle) * movestep), player->radius))
    {
      player->x += round(cos(player->viewangle) * movestep); 
      player->y += round(sin(player->viewangle) * movestep);
    }
  }
  else if (player->movesleft_or_right != 0)
  {
    movestep = player->movespeed;
    left_or_right_angle = player->movesleft_or_right * PI / 2;
     if (!check_wals(player->x + (cos(player->viewangle + left_or_right_angle) * movestep), player->y +\
     (sin(player->viewangle + left_or_right_angle) * movestep), player->radius))
     {
        player->x += round(cos(player->viewangle + left_or_right_angle) * movestep); 
        player->y += round(sin(player->viewangle + left_or_right_angle) * movestep);
     }
  }
  put_map(player);
  put_player(player);
  draw_view_angle(player);
  mlx_put_image_to_window(player->mlx, player->mlx_win, player->img->img, 0, 0);
  return 1;
}