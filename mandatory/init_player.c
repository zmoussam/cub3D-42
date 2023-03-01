/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:00:42 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/01 21:47:21 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

static void get_player_position(t_player *player, char **map)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 32)
            {
                player->position.x = j * TILE_SIZE + (TILE_SIZE / 2);
                player->position.y = i * TILE_SIZE + (TILE_SIZE / 2);
            }
            j++;
        }
        i++;
    }
}
static void get_first_direction_angle(t_player *player, char **map)
{
    int direction;
    direction = (int)map[(int)player->position.y / TILE_SIZE]\
    [(int)player->position.x / TILE_SIZE];
    if (direction == 83)
        player->viewangle = M_PI / 2;
    if (direction == 69)
        player->viewangle = 0;
    if (direction == 87)
        player->viewangle = M_PI;
    if (direction == 78)
        player->viewangle = -1 * M_PI / 2;
}

void init_player(t_player *player, char **map)
{
    player->turndirection = 0;
    player->walkdirection = 0;
    player->movespeed = 2;
    player->movesleft_or_right = 0;
    player->rotationspeed = ROTATION_SPEED;
    get_player_position(player, map);
    get_first_direction_angle(player, map);
}
