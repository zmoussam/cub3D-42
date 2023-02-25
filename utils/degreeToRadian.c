/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degreeToRadian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:42:02 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/24 21:48:40 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PI 3.14

// opposite
// adjacent
// hypotenuse

double deg2rad(double degrees){
    return degrees * (PI / 180.0);
}
