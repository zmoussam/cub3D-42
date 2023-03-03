/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:07:23 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 23:20:17 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void	__free_data(t_collect_data *data)
{
	free(data->wall);
	free(data->map_info->ea);
	free(data->map_info->so);
	free(data->map_info->we);
	free(data->map_info->no);
	free(data->shoot_target->info);
	free(data->shoot_target);
	free(data->weapon);
	free(data->amo->info);
	free(data->amo);
	free(data->digit);
}

void	ft_free_data(t_collect_data *data)
{
	int	i;

	i = -1;
	while (++i < 10)
	{
		if (i < 4)
			free(data->wall[i].info);
		if (i < 3)
		{
			free(data->weapon[i]->info);
			free(data->weapon[i]);
		}
		free(data->digit[i]->info);
		free(data->digit[i]);
	}
	__free_data(data);
	i = -1;
	while (data->map_info->map[++i])
		free(data->map_info->map[i]);
	free(data->map_info->map);
}
