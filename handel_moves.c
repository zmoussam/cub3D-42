/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:35:38 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/11 22:53:06 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int releaskey(int keycode, t_player_data *player)
{
  if (keycode == 0)
      player->turndirection = 0;
  if (keycode == 2)
      player->turndirection = 0;   
  if (keycode == 1)
    player->walkdirection = 0;  
  if (keycode == 13)
      player->walkdirection = 0;
  return 0;
}

int presskey(int keycode, t_player_data *player)
{
  if (keycode == 0)
      player->turndirection = -1;
  if (keycode == 2)
      player->turndirection = +1;   
  if (keycode == 1)
    player->walkdirection = -1;  
  if (keycode == 13)
      player->walkdirection = +1;
    return 0;
}

int key_hook(t_player_data *player)
{
  int movestep;
  
  player->rotationangle += player->turndirection * player->rotationspeed;
  movestep = player->walkdirection * player->movespeed;
  if (!check_wals(player->x + (cos(player->rotationangle) * movestep), player->y +\
  (sin(player->rotationangle) * movestep), player->radius))
  {
      player->x += cos(player->rotationangle) * movestep; 
      player->y += sin(player->rotationangle) * movestep;
  }
  put_map(player);
  put_player(player);
  draw_view_angle(player);
  mlx_put_image_to_window(player->mlx, player->mlx_win, player->img->img, 0, 0);
  
  return 1;
}