/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:37:57 by zmoussam          #+#    #+#             */
/*   Updated: 2022/11/20 18:36:44 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	_error(char *error_name)
{
	perror(error_name);
	exit(1);
}

void free_colors(char **colors)
{
	int i;
	i = 0;

	while(colors[i])
		free(colors[i++]);
	free(colors);
}

void	free_map_list(t_list *map, int height)
{
	t_list	*head;

	head = map;
	while (head && height > 0)
	{
		free(head->content);
		head = head->next;
	}
}