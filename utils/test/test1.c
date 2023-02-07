/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:55:37 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/08 00:50:18 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define PI 3.14

// struct player{
//     x;
//     y;
//     radius;
//     turnDirection = 0;
//     walkDirection = 0;
//     rotationAngle = PI / 2;
//     moveSpeed = 3.0;
//     rotationSpeed = 3 * (PI / 2);    
// }

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
#define PI 3.14159265
#include<mlx.h>
#include <math.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct s_player_data
{
    double x;
    double y;
    int radius;
    int movespeed;
    double rotationangle;
    double rotationspeed;
    int turndirection;
    int walkdirection;
    t_data *img;
    void *mlx;
    void *mlx_win;
} t_player_data;

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
  {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1},
  {1,0,1,0,1,0,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1},
  {1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

#include <mlx.h>


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
          //  if (worldMap[(int)(player->radius + player->y / 30)][(int)(i / 30)] == 1)
          //             break;
           my_mlx_pixel_put(player->img, i, j, 0x00FF0000);
           j++;
        }
        i++;
    }
    
}
void put_map(t_player_data *player)
{
  int i = 0; 
  int j = 0; 
  while(i < 720)
  {
    j = 0;
    while(j < 720)
    {
        if (worldMap[(int)(i / 30)][(int)(j / 30)] == 1)
	        my_mlx_pixel_put(player->img, j, i, 0x00000000);
        else 
          my_mlx_pixel_put(player->img, j, i, 0x00FFFFFF);
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
      if (worldMap[(int)(yy / 30)][(int)(xx / 30)] == 1)
          break;
        my_mlx_pixel_put(player->img, xx, yy, 0x00FF0000);
        xx = xx + xinc;
        yy = yy + yinc;
    }
}

int key_hook(int keycode, t_player_data *player)
{
  int movestep;
  
  if (keycode == 0)
  {
      player->turndirection = -1;
  }
  if (keycode == 2)
  {
      player->turndirection = +1;   
  }
  if (keycode == 1)
  {
    player->walkdirection = -1;  
  }
  if (keycode == 13)
  {
      player->walkdirection = +1;
  }
  player->rotationangle += player->turndirection * player->rotationspeed;
  movestep = player->walkdirection * player->movespeed;

  player->x += cos(player->rotationangle) * movestep; 
  player->y += sin(player->rotationangle) * movestep;
  
  put_map(player);
  put_player(player);
  drawline(player, player->x + (cos(player->rotationangle) * 50) + (player->radius / 2), player->y + (sin(player->rotationangle) * 50) + (player->radius / 2));
	mlx_put_image_to_window(player->mlx, player->mlx_win, player->img->img, 0, 0);
  if (keycode == 0)
  {
      player->turndirection = 0;
  }
  if (keycode == 2)
  {
      player->turndirection = 0;   
  }
  if (keycode == 1)
  {
    player->walkdirection = 0;  
  }
  if (keycode == 13)
  {
      player->walkdirection = 0;
  }
  
  return 1;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
  t_player_data player;

  player.x = 360;
  player.y = 360;
  player.radius = 15;
  player.movespeed = 15;
  player.rotationangle = PI / 2;
  player.rotationspeed = 10 * (PI / 180);
  player.turndirection = 0;
  player.walkdirection = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 24 * 30, 24 * 30, "Awesome cub3d!");
	img.img = mlx_new_image(mlx, 24 * 30, 24 * 30);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
  player.img = &img;
  player.mlx = mlx;
  player.mlx_win = mlx_win;
  put_map(&player);
  put_player(&player);
  drawline(&player, player.x + (cos(player.rotationangle) * 50) + (player.radius / 2), player.y + (sin(player.rotationangle) * 50)+ (player.radius / 2));
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
  mlx_hook(mlx_win, 2, 1L << 0, key_hook , &player);
	mlx_loop(mlx);
}