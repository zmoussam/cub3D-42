/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extention.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:30:56 by zmoussam          #+#    #+#             */
/*   Updated: 2022/11/20 19:14:25 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <string.h>
void	check_extention(char *file_name)
{
	int		start;
	char	*extention;

	start = ft_strlen(file_name) - 4;
	extention = ft_substr(file_name, start, 4);
	if (ft_strcmp(".cub", extention) != 0)
	{
		free(extention);
		_error("extention must be .cub\n");
	}
	free(extention);
}