/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:55:37 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/11 22:54:07 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define mapWidth 17
#define mapHeight 17
#define screenWidth 640
#define screenHeight 480
#define PI 3.14159265
#define VIEW_ANGLE 30 * PI / 180;
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
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
  {1,0,0,0,1,0,1,1,0,1,1,0,1,0,0,0,1},
  {1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

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
           if (worldMap[(int)(j / 30)][(int)(i / 30)] == 1)
                break;
           my_mlx_pixel_put(player->img, i, j, 0x00FFFF00);
           j++;
        }
        i++;
    }
}

void put_map(t_player_data *player)
{
  int i = 0; 
  int j = 0; 
  while(i < 510)
  {
    j = 0;
    while(j < 510)
    {
        if (i % 30 == 0 || j % 30 == 0) 
          my_mlx_pixel_put(player->img, j, i, 0x00000000);
        else if (worldMap[(int)(i / 30)][(int)(j / 30)] == 1)
	        my_mlx_pixel_put(player->img, j, i, 0x00000000);
        else 
          my_mlx_pixel_put(player->img, j, i, 0x00909090);
        j++;
    }
    i++;
  }
}

int check_wals(double x, double y, int radius) 
{
    int i = x;
    int j = y;

    while(i < radius + x)
    {
        j = y;
        while(j < radius + y)
        { 
           if (worldMap[(int)(j / 30)][(int)(i / 30)] == 1)
                return 1;
           j++;
        }
        i++;
    }
    return 0;
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
        my_mlx_pixel_put(player->img, round(xx), round(yy), 0x00FF0000);
        xx = xx + xinc;
        yy = yy + yinc;
    }
}
void draw_view_angle(t_player_data *player)
{
    double negatif_angle;
    double positif_angle;

    negatif_angle = player->rotationangle - VIEW_ANGLE;
    positif_angle = player->rotationangle + VIEW_ANGLE;
    while(negatif_angle < player->rotationangle)
    {
        drawline(player, player->x + (cos(negatif_angle) * 510) + (player->radius / 2), \
        player->y + (sin(negatif_angle) * 510) + (player->radius / 2));
        negatif_angle += 1 * PI / 180;
    }
    while(positif_angle >= player->rotationangle)
    {
        drawline(player, player->x + (cos(positif_angle) * 510) + (player->radius / 2), \
        player->y + (sin(positif_angle) * 510) + (player->radius / 2));
        positif_angle -= 1 * PI / 180;
    } 
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

int key_hook(t_player_data *player)
{
  int movestep;
  
  player->rotationangle += player->turndirection * player->rotationspeed;
  movestep = player->walkdirection * player->movespeed;
  if (!check_wals(player->x + (cos(player->rotationangle) * movestep), player->y + \
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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
  t_player_data player;

  player.x = 248;
  player.y = 248;
  player.radius = 14 ;
  player.movespeed = 2;
  player.rotationangle = PI / 2;
  player.rotationspeed = 5 * (PI / 180);
  player.turndirection = 0;
  player.walkdirection = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 17 * 30, 17 * 30, "Awesome cub3d!");
	img.img = mlx_new_image(mlx, 17 * 30, 17 * 30);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
  player.img = &img;
  player.mlx = mlx;
  player.mlx_win = mlx_win;
  put_map(&player);
  put_player(&player);
	draw_view_angle(&player);
  mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
  mlx_hook(mlx_win, 2, 1L << 0, presskey , &player);
  mlx_hook(mlx_win, 3, 1L << 0, releaskey , &player);
  mlx_loop_hook(mlx, &key_hook, &player);
	mlx_loop(mlx);
}
