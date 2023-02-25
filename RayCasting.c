/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:13:48 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/25 23:00:19 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
double normangle(double angle)
{
  angle = fmod(angle, 2 * PI);
  if (angle < 0)
      angle = angle + (2 * PI);
  return (angle);
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

int haswallat(double x, double y , t_player_data *player)
{
    if (x < 0 || x > MAPWIDTH * TILE_SIZE || y < 0 || y > MAPWIDTH * TILE_SIZE)
        return 1; 
    return (player->map.map[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1');
}
double get_distance(t_player_data *player, double x, double y, bool check)
{
  if (!check)
    return (INT_MAX);
  else 
  check = 0;
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
    while(nexthorzinter.x >= 0 && nexthorzinter.x <= MAPWIDTH * TILE_SIZE && \
    nexthorzinter.y >= 0 && nexthorzinter.y <= MAPHEIGHT * TILE_SIZE)
    {
      if(haswallat(nexthorzinter.x, nexthorzinter.y - check_isfacingup, player))
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
    while (nextvertinter.x >= 0 &&  nextvertinter.x <= MAPWIDTH * TILE_SIZE && \
    nextvertinter.y >= 0 && nextvertinter.y <= MAPHEIGHT * TILE_SIZE)
    {
      if (haswallat(nextvertinter.x - check_isfacingleft, nextvertinter.y, player))
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

void get_smallwallhit(t_ray *ray, t_player_data *player, double horzdistance, double vertdistance)
{
    ray->wallhitisvert = false;
    if (horzdistance <= vertdistance)
      ray->distancetowall = horzdistance * cos(ray->angle - player->viewangle);
    else if (horzdistance > vertdistance)
    {
      ray->wallhitisvert = true;
      ray->distancetowall = vertdistance * cos(ray->angle - player->viewangle);
    }
}

void castingrays(t_player_data *player) 
{
    double ray_angle;
    double angle_inc;
    int view_angle_degree;
    double horz_hitdistance;
    double vert_hitdistance;
    int count;
    t_ray ray;
    
    view_angle_degree = VIEW_ANGLE * 180 / PI;
    angle_inc = view_angle_degree * (PI / (180 * SCREENWIDTH));
    ray_angle = player->viewangle - (VIEW_ANGLE / 2);
    count = 0;
    while (count < SCREENWIDTH)
    {
      ray.angle = normangle(ray_angle);
      get_ray_direction(&ray);
      horz_hitdistance = find_horzintersection(player, &ray);
      vert_hitdistance = find_vertintersection(player, &ray);
      get_smallwallhit(&ray, player, horz_hitdistance, vert_hitdistance);
      draw(player, player->img, &ray, count);
      ray_angle += angle_inc;
      count++;
    }
}
