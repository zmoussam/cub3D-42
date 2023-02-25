/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleMoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:35:38 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/25 16:16:21 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_wals(double x, double y, t_player_data *player) 
{
    int i = x;
    int j = y;
    
    while(i < player->radius + x)
    {
        j = y;
        while(j < player->radius + y)
        { 
           if (player->map.map[(int)(j / TILE_SIZE)][(int)(i / TILE_SIZE)] == '1')
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
  // double tmpangle;

  left_or_right_angle = 0;
  player->viewangle += player->turndirection * player->rotationspeed;
  
  // if (player->walkdirection != 0 && player->movesleft_or_right != 0)
  // {
  //   movestep = player->movespeed;
  //   if (player->walkdirection == -1)
  //     tmpangle = player->walkdirection * (player->viewangle + (player->movesleft_or_right * 3 * PI / 4));
  //   else if (player->walkdirection == 1)
  //     tmpangle = player->walkdirection * (player->viewangle + (player->movesleft_or_right  * PI / 4));
  //   else
  //     tmpangle =(player->viewangle + (player->movesleft_or_right * PI / 4));
  //   if (!check_wals(player->position.x + (cos(tmpangle) * movestep), player->position.y +\
  //   (sin(tmpangle) * movestep), player->radius))
  //   {
  //     player->position.x += cos(tmpangle) * movestep; 
  //     player->position.y += sin(tmpangle) * movestep;
  //   }
  // }
  if (player->walkdirection != 0)
  {
    movestep = player->walkdirection * player->movespeed;
    if (!check_wals(player->position.x + (cos(player->viewangle) * movestep), player->position.y +\
    (sin(player->viewangle) * movestep), player))
    {
      player->position.x += (cos(player->viewangle) * movestep); 
      player->position.y += (sin(player->viewangle) * movestep);
    }
  }
  else if (player->movesleft_or_right != 0)
  {
    movestep = player->movespeed;
    left_or_right_angle = player->movesleft_or_right * PI / 2;
     if (!check_wals(player->position.x + (cos(player->viewangle + left_or_right_angle) * movestep), player->position.y +\
     (sin(player->viewangle + left_or_right_angle) * movestep), player))
     {
        player->position.x += (cos(player->viewangle + left_or_right_angle) * movestep); 
        player->position.y += (sin(player->viewangle + left_or_right_angle) * movestep);
     }
  }
  mlx_clear_window(player->mlx, player->mlx_win);
  castingrays(player);
  put_minimap(player);
  mlx_put_image_to_window(player->mlx, player->mlx_win, player->img->img, 0, 0);
  return 1;
}