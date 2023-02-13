/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:13:48 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/13 23:58:17 by zmoussam         ###   ########.fr       */
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
      // if (worldMap[(int)(yy / TILE_SIZE)][(int)(xx / TILE_SIZE)] == 1)
      //     break;
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

t_cordinates find_intercept(t_player_data *player, t_ray *ray)
{
  t_cordinates intercept;

  intercept.y = floor(player->y / TILE_SIZE) * TILE_SIZE + (ray->isfacingdown * TILE_SIZE);
  intercept.x = player->x + (intercept.y - player->y) / tan(ray->angle);

  return (intercept);
}

t_cordinates find_step(t_ray *ray)
{
    t_cordinates step;

    step.y = TILE_SIZE;
    step.y *= ray->isfacingup;

    step.x = TILE_SIZE / tan(ray->angle);
    if (ray->isfacingleft && step.x > 0)
      step.x *= -1;
    if (ray->isfacingright && step.x < 0)
      step.x *= -1;
    return (step);
}

void  get_ray_direction(t_ray *ray)
{
    if (ray->angle > 0 && ray->angle < PI)
    {
      ray->isfacingdown = 1;
      ray->isfacingup = 1;
    }
    else
    {
      ray->isfacingdown = 0;
      ray->isfacingup = -1;
    }
    if (ray->angle < (PI / 2) || ray->angle > (3 * PI / 2))
    {
      ray->isfacingright = 1;
      ray->isfacingleft = 0;
    }
    else
    {
      ray->isfacingright = 0;
      ray->isfacingleft = 1;
    }
    
}
// t_cordinates find_horizontal_intersection(t_cordinates intercept, )
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
int haswallat(double x, double y)
{
    if(worldMap[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == 1)
      return 1;
    else 
      return 0;
}
void draw_view_angle(t_player_data *player) 
{
    double ray_angle;
    double angleinc;
    double nexthorzx;
    double nexthorzy;
    t_cordinates intercept;
    t_cordinates step;
    int gethorzwall;
    t_ray ray;
    
    angleinc = (60 * (PI / (180 * SCREENWIDTH)));
    ray_angle = player->viewangle - (VIEW_ANGLE / 2);
    gethorzwall = 0;
    
    ray.angle = normangle(ray_angle);
    get_ray_direction(&ray);
    intercept = find_intercept(player, &ray);
    step = find_step(&ray);
    // printf("xstep = %d, ystep = %d\n", (int)step.x, (int)step.y);
    nexthorzx = intercept.x;
    nexthorzy = intercept.y;
    // printf("x = %d, y = %d\n", (int)nexthorzx, (int)nexthorzy);
    if (ray.isfacingup == -1)
      nexthorzy--;

    while(nexthorzx >= 0 && nexthorzx <= SCREENWIDTH && nexthorzy >= 0 && nexthorzy <= SCREENHEIGHT)
    {
      if(haswallat(nexthorzx, nexthorzy))
      {
          gethorzwall = 1;
          ray.wallhit.x = round(nexthorzx);
          ray.wallhit.y = round(nexthorzy);
          drawline(player, ray.wallhit.x, ray.wallhit.y);
          break;
          // printf("ray.wallhit.x = %lf, ray.wallhit.y = %lf\n",ray.wallhit.x, ray.wallhit.y);
      }
      else
      {
          nexthorzx += step.x;
          nexthorzy += step.y;
      } 
    }
    
    // printf("up %d\n", ray.isfacingdown);
    // drawline(player, player->x + (cos(ray.angle) * SCREENWIDTH) + (player->radius / 2), \
    // player->y + (sin(ray.angle) * SCREENHEIGHT) + (player->radius / 2));
    // while(ray_angle <= player->viewangle + (VIEW_ANGLE / 2))
    // {
    //     drawline(player, player->x + (cos(ray_angle) * SCREENWIDTH) + (player->radius / 2), \
    //     player->y + (sin(ray_angle) * SCREENHEIGHT) + (player->radius / 2));
    //     ray_angle += angleinc;
    // }
}
