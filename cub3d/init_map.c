/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:18:56 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/26 16:51:13 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		size;
	int		j;

	size = 0;
	while (s1[size])
		size++;
	copy = (char *)malloc((size + 1) * sizeof(char));
	if (copy == NULL)
		return (copy);
	j = 0;
	while (s1[j])
	{
		copy[j] = s1[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

void get_map(char **map)
{   
   map[0] =  ft_strdup("11111111111111111111111");
   map[1] =  ft_strdup("10000000000000001");
   map[2] =  ft_strdup("11111000000000001111111");
   map[3] =  ft_strdup("10000000000000000000001");
   map[4] =  ft_strdup("11111100000000011111111");
   map[5] =  ft_strdup("      10000000111111111");
   map[6] =  ft_strdup("111111000000001");
   map[7] =  ft_strdup("100000000000001");
   map[8] =  ft_strdup("100000000000001");
   map[9] =  ft_strdup("100000000000001");
   map[10] = ft_strdup("10000000000000111111111");
   map[11] = ft_strdup("11111111000000000000001");
   map[12] = ft_strdup("        10000000000001");
   map[13] = ft_strdup("1111111100S000000000001");
   map[14] = ft_strdup("10000000000000000000001");
   map[15] = ft_strdup("10000000000000000000001");
   map[16] = ft_strdup("11111111111111111111111");
   map[17] = NULL;
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void init_map(t_map_info *map_info)
{
    map_info->c_ceiling = create_trgb(0x00, 0x00, 0x2A, 0x41);
    map_info->c_floor = create_trgb(0x00, 0x90, 0x94, 0x90);
    map_info->ea = ft_strdup("./assets/ea.xpm");
    map_info->no = ft_strdup("./assets/no.xpm");
    map_info->so = ft_strdup("./assets/so.xpm");
    map_info->we = ft_strdup("./assets/we.xpm");
    map_info->map = (char **)malloc(sizeof(char *) * 24);
    if (!map_info->map)
        return ;
    get_map(map_info->map);
}