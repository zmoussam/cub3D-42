/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:13:48 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/14 22:07:42 by zmoussam         ###   ########.fr       */
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
  
  int i;
  int j;
  double dist;

  i = 0;
  j = 0;
  
  while(i < SCREENWIDTH)
  {
    j = 0;
    while(j < SCREENHEIGHT)
    {
      dist = sqrt((i - player->position.x)*(i - player->position.x) +\
      (j - player->position.y)*(j - player->position.y));
      if(dist <= player->radius)
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
    
    dx = x - player->position.x;
    dy = y - player->position.y;

    if(abs(dx) > abs(dy))
      steps = abs(dx);
    else
      steps = abs(dy);

    xinc = dx / (float)steps;
    yinc = dy / (float)steps;

    xx = player->position.x;
    yy = player->position.y;
    i = 0;
    while (i <= steps)
    {
        my_mlx_pixel_put(player->img, round(xx), round(yy), 0x00FF4F37);
        xx = xx + xinc;
        yy = yy + yinc;
        i++;
    }
}

t_cordinates find_vertintercept(t_player_data *player, t_ray *ray)
{
  t_cordinates intercept;

  intercept.x = floor(player->position.x / TILE_SIZE) * TILE_SIZE + (ray->isfacingright * TILE_SIZE);
  intercept.y = player->position.y + (intercept.x - player->position.x) * tan(ray->angle);

  return (intercept);
}
t_cordinates find_horzintercept(t_player_data *player, t_ray *ray)
{
  t_cordinates intercept;

  intercept.y = floor(player->position.y / TILE_SIZE) * TILE_SIZE + (ray->isfacingdown * TILE_SIZE);
  intercept.x = player->position.x + (intercept.y - player->position.y) / tan(ray->angle);

  return (intercept);
}

t_cordinates find_horzstep(t_ray *ray)
{
    t_cordinates step;

    step.y = TILE_SIZE;
    step.y *= ray->isfacingup;

    step.x = TILE_SIZE / tan(ray->angle);
    if (ray->isfacingleft == -1 && step.x > 0)
      step.x *= -1;
    if (ray->isfacingright && step.x < 0)
      step.x *= -1;
    return (step);
}
t_cordinates find_vertstep(t_ray *ray)
{
    t_cordinates step;

    step.x = TILE_SIZE;
    step.x *= ray->isfacingleft;

    step.y = TILE_SIZE * tan(ray->angle);
    if (ray->isfacingup == -1 && step.y > 0)
      step.y *= -1;
    if (ray->isfacingdown && step.x < 0)
      step.y *= -1;
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
      ray->isfacingleft = 1;
    }
    else
    {
      ray->isfacingright = 0;
      ray->isfacingleft = -1;
    }
    
}
int haswallat(double x, double y)
{
    if(worldMap[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == 1)
      return 1;
    else 
      return 0;
}
double get_distance(t_player_data *player, double x, double y, bool check)
{
  if (!check)
    return (INT_MAX);
  else 
    return (sqrt(((x - player->position.x) * (x - player->position.x)) + \
    ((y - player->position.y) * (y - player->position.y))));
}
double find_horzintersection(t_player_data *player, t_ray *ray)
{
    t_cordinates intercept;
    t_cordinates step;
    t_cordinates nexthorzinter;
    ray->horzwallhit.x = 0;
    ray->horzwallhit.y = 0;
    short check_isfacingup;
    bool gethorzwall;
     
    gethorzwall = false;
    check_isfacingup = 0;
    intercept = find_horzintercept(player, ray);
    step = find_horzstep(ray);
    nexthorzinter.x = intercept.x;
    nexthorzinter.y = intercept.y;
    if (ray->isfacingup == -1)
       check_isfacingup = 1;
    while(nexthorzinter.x >= 0 && nexthorzinter.x <= SCREENWIDTH && \
    nexthorzinter.y >= 0 && nexthorzinter.y <= SCREENHEIGHT)
    {
      if(haswallat(nexthorzinter.x, nexthorzinter.y - check_isfacingup))
      {
          gethorzwall = true;
          ray->horzwallhit.x = nexthorzinter.x;
          ray->horzwallhit.y = nexthorzinter.y;
          break;
      }
      else
      {
          nexthorzinter.x += step.x;
          nexthorzinter.y += step.y;
      } 
    }
    return (get_distance(player, ray->horzwallhit.x, ray->horzwallhit.y, gethorzwall));
}

double find_vertintersection(t_player_data *player, t_ray *ray)
{
    t_cordinates intercept;
    t_cordinates step;
    t_cordinates nextvertinter;
    short check_isfacingleft;
    int getvertwall;
     
    getvertwall = false;
    check_isfacingleft = 0;
    ray->vertwallhit.x = 0;
    ray->vertwallhit.y = 0;
    intercept = find_vertintercept(player, ray);
    step = find_vertstep(ray);
    nextvertinter.x = intercept.x;
    nextvertinter.y = intercept.y;
    if (ray->isfacingleft == -1)
        check_isfacingleft = 1;
    while (nextvertinter.x >= 0 &&  nextvertinter.x <= SCREENWIDTH && \
    nextvertinter.y >= 0 && nextvertinter.y <= SCREENHEIGHT)
    {
      if (haswallat(nextvertinter.x - check_isfacingleft, nextvertinter.y))
      {
          getvertwall = true;
          ray->vertwallhit.x =  nextvertinter.x;
          ray->vertwallhit.y =  nextvertinter.y;
          break;
      }
      else
      {
          nextvertinter.x += step.x;
          nextvertinter.y += step.y;
      } 
    }
    return (get_distance(player, ray->vertwallhit.x, ray->vertwallhit.y, getvertwall));
}

t_cordinates get_smallwallhit(t_ray *ray, double horzdistance, double vertdistance)
{
    ray->wallhitisvert = false;
    if (horzdistance <= vertdistance)
    {
      ray->distancetowall = horzdistance;
      return (ray->horzwallhit);
    }
    else
    {
      ray->wallhitisvert = true;
      ray->distancetowall = vertdistance;
      return (ray->vertwallhit);
    } 
}

double normangle(double angle)
{
  angle = fmod(angle, 2 * PI);
  if (angle < 0)
      angle = angle + (2 * PI);
  return (angle);
}
void draw_view_angle(t_player_data *player) 
{
    double ray_angle;
    double angle_inc;
    double horz_hitdistance;
    double vert_hitdistance;
    int view_angle_degree;

    t_cordinates wallhit;
    t_ray ray;
    
    view_angle_degree = VIEW_ANGLE * 180 / PI;
    angle_inc = view_angle_degree * (PI / (180 * SCREENWIDTH));
    ray_angle = player->viewangle - (VIEW_ANGLE / 2);
    
    // ray.angle = normangle(ray_angle);
    // get_ray_direction(&ray);
    // horz_hitdistance = find_horzintersection(player, &ray);
    // vert_hitdistance = find_vertintersection(player, &ray);
    // wallhit = get_smallwallhit(&ray, horz_hitdistance, vert_hitdistance);

    // drawline(player, wallhit.x, wallhit.y);
  
    // printf("up %d\n", ray.isfacingdown);
    printf("anglr inc = %lf\n", angle_inc);
    while (ray_angle <= player->viewangle + (VIEW_ANGLE / 2))
    {
      ray.angle = normangle(ray_angle);
      get_ray_direction(&ray);
      horz_hitdistance = find_horzintersection(player, &ray);
      vert_hitdistance = find_vertintersection(player, &ray);
      wallhit = get_smallwallhit(&ray, horz_hitdistance, vert_hitdistance);
      drawline(player, wallhit.x, wallhit.y);
      ray_angle += angle_inc;
    }
}
