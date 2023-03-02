/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleMoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:35:38 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/01 20:43:52 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int check_wall(double x, double y, char **map) 
{
    int i = x;
    int j = y;
    int radius;
    
    radius = 2;
    while(i < radius + x)
    {
        j = y;
        while(j < radius + y)
        { 
           if (map[(int)(j / TILE_SIZE)][(int)(i / TILE_SIZE)] == '1')
                return 1;
           j++;
        }
        i++;
    }
    return 0;
}

int releaskey(int keycode, t_player *player)
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

int presskey(int keycode, t_player *player)

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
  if (keycode == SHOOT)
  {
    player->check_shoot = 1;
    if (player->count_shoot > 0)
      player->count_shoot--;
      
  }
  if (keycode == ESC)
	{
		printf("game over!!!\n");
		// mlx_destroy_window(so_long->mlx, so_long->win);
		exit(-1);
	}
  return 0;
}
void put_weapon(t_mlx *mlx, t_texture **weapon, int *check_shoot, int count_shoot)
{
    static int r;
    
    r++;
    if (*check_shoot == 1 && count_shoot > 0)
    {
        if (r == 1)
          mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, weapon[0]->info->img, SCREENWIDTH - 250 - weapon[0]->_width, SCREENHEIGHT - weapon[0]->_heigth);
        else if (r == 2)
          mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, weapon[1]->info->img, SCREENWIDTH - 250 - weapon[1]->_width, SCREENHEIGHT - weapon[1]->_heigth);
        else if (r == 3)
          mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, weapon[2]->info->img, SCREENWIDTH - 250 - weapon[2]->_width, SCREENHEIGHT - weapon[2]->_heigth);
    }
    else 
      mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, weapon[0]->info->img, SCREENWIDTH - 250 - weapon[0]->_width, SCREENHEIGHT - weapon[0]->_heigth);
    if (r == 3)
    {
      *check_shoot = 0;
      r = 0;
    }
}

void put_count_amo(t_mlx *mlx, t_texture **digit, int count_shoot)
{
    if (count_shoot == 100)
    {
      mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, digit[1]->info->img, SCREENWIDTH - 204, SCREENHEIGHT - 148);
      mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, digit[0]->info->img, SCREENWIDTH - 136, SCREENHEIGHT - 148);
      mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, digit[0]->info->img, SCREENWIDTH - 68, SCREENHEIGHT - 148);
    }
    else if (count_shoot >= 10)
    {
      mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, digit[count_shoot / 10]->info->img, SCREENWIDTH - 136, SCREENHEIGHT - 148);
      mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, digit[count_shoot % 10]->info->img, SCREENWIDTH - 68, SCREENHEIGHT - 148);
    }
    else 
      mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, digit[count_shoot]->info->img, SCREENWIDTH - 68, SCREENHEIGHT - 148);
}

int moveplayer(t_collect_data *data)
{
  int movestep;
  double left_or_right_angle;
  double next_x;
  double next_y;
  double tmpangle;

  left_or_right_angle = 0;
  data->player->viewangle += data->player->turndirection * data->player->rotationspeed;
  
  if (data->player->walkdirection != 0 && data->player->movesleft_or_right != 0)
  {
    movestep = data->player->movespeed;
    if (data->player->walkdirection == -1)
      tmpangle = data->player->walkdirection * (data->player->viewangle + (data->player->movesleft_or_right * 3 * M_PI / 4));
    else if (data->player->walkdirection == 1)
      tmpangle = data->player->walkdirection * (data->player->viewangle + (data->player->movesleft_or_right * M_PI / 4));
    else
      tmpangle = data->player->walkdirection * (data->player->viewangle + (data->player->movesleft_or_right * M_PI / 4));
    next_x = data->player->position.x + (cos(tmpangle) * movestep);
    next_y = data->player->position.y + (sin(tmpangle) * movestep);
    if (!check_wall(next_x, next_y, data->map_info->map))
    {
      data->player->position.x = next_x; 
      data->player->position.y = next_y;
    }
  }
  if (data->player->walkdirection != 0)
  {
    movestep = data->player->walkdirection * data->player->movespeed;
    next_x = data->player->position.x + (cos(data->player->viewangle) * movestep);
    next_y = data->player->position.y + (sin(data->player->viewangle) * movestep);
    if (!check_wall(next_x, next_y, data->map_info->map))
    {
      data->player->position.x = next_x; 
      data->player->position.y = next_y;
    }
  }
  else if (data->player->movesleft_or_right != 0)
  {
    movestep = data->player->movespeed;
    left_or_right_angle = data->player->movesleft_or_right * M_PI / 2;
    next_x = data->player->position.x + (cos(data->player->viewangle + left_or_right_angle) * movestep);
    next_y = data->player->position.y + (sin(data->player->viewangle + left_or_right_angle) * movestep);
    if (!check_wall(next_x, next_y, data->map_info->map))
    {
        data->player->position.x = next_x;
        data->player->position.y = next_y;
    }
  }
  mlx_clear_window(data->mlx->mlx, data->mlx->mlx_win);
  castingrays(data); 
  put_minimap(data);
  mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->img->img, 0, 0);
  mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->shooting_target->info->img, (SCREENWIDTH / 2) - 15, (SCREENHEIGHT / 2) - 15);
  put_count_amo(data->mlx, data->digit, data->player->count_shoot);
  put_weapon(data->mlx, data->weapon, &data->player->check_shoot, data->player->count_shoot);
  mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->amo->info->img, SCREENWIDTH - 74, SCREENHEIGHT - 84);
  mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mini_map->img, \
   10, SCREENHEIGHT - (SCREENHEIGHT * MINI_MAP_FACTOR) - 10);
  
  return 1;
}
