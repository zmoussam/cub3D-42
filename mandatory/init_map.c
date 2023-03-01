/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:18:56 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/28 21:31:18 by zmoussam         ###   ########.fr       */
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
   map[0] =  ft_strdup("11111111111111111111111111111111");
   map[1] =  ft_strdup("10000000000001000000011111111111");
   map[2] =  ft_strdup("100000000000010000001");
   map[3] =  ft_strdup("10011111111000100100111");
   map[4] =  ft_strdup("10010000001000000001000111111111");
   map[5] =  ft_strdup("10010000001000001001001");
   map[6] =  ft_strdup("10010011111111001111111111111111");
   map[7] =  ft_strdup("10010010000001001000000000001001");
   map[8] =  ft_strdup("10010010000001001000000000001001");
   map[9] =  ft_strdup("10010010001001111001111111111111");
   map[10] = ft_strdup("10000000001000001000001001");
   map[11] = ft_strdup("11110010001000001000001000001111");
   map[12] = ft_strdup("1000111001111001001001001");
   map[13] = ft_strdup("10000010000001001001101001111111");
   map[14] = ft_strdup("10011111111001001000000001000001");
   map[15] = ft_strdup("10000010111111111111111111111111");
   map[16] = ft_strdup("101000001");
   map[17] = ft_strdup("11110010111111111111111111111111");
   map[18] = ft_strdup("10000010010101001111001111001001");
   map[19] = ft_strdup("10000010010101011001001000001001");
   map[20] = ft_strdup("10011110010101000001001001001001");
   map[21] = ft_strdup("10010000010001001001001001111001");
   map[22] = ft_strdup("11110000010101001000001000001001");
   map[23] = ft_strdup("10000011110101001000001001001001");
   map[24] = ft_strdup("10000010010101111111111111111001");
   map[25] = ft_strdup("10011110010101000000000000001001");
   map[26] = ft_strdup("10000000010101001001001001001001");
   map[27] = ft_strdup("10000000010001001111111111001001");
   map[28] = ft_strdup("10100000010000001000000000001001");
   map[29] = ft_strdup("10100000010010001000100001001001");
   map[30] = ft_strdup("10101100000010000000111001001001");
   map[31] = ft_strdup("1000100001000E000100001001001001");
   map[32] = ft_strdup("10001000010000000100001000001001");
   map[33] = ft_strdup("11111111111111111111111111111111");
   map[34] = NULL;
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void init_map(t_map_info *map_info)
{
    map_info->c_ceilling = create_trgb(0x00, 0x00, 0x2A, 0x41);
    map_info->c_floor = create_trgb(0x00, 0x90, 0x94, 0x90);
    map_info->ea = ft_strdup("./assets/ea.xpm");
    map_info->no = ft_strdup("./assets/no.xpm");
    map_info->so = ft_strdup("./assets/so.xpm");
    map_info->we = ft_strdup("./assets/we.xpm");
    map_info->map = (char **)malloc(sizeof(char *) * 35);
    if (!map_info->map)
        return ;
    get_map(map_info->map);
}