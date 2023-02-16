/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:52:17 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/15 17:01:10 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
    distaceprojplan = (SCREENWIDTH / 2) / tan(VIEW_ANGLE / 2);
    wallstripheight = (TILE_SIZE / ray.distance) * distanceprojplan;
*/

