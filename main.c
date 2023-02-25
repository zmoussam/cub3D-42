/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:11 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/25 16:25:31 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	t_img_data	img;
  t_player_data player;

  player.map.c_ceiling = create_trgb(0x00, 0x00, 0x2A, 0x41);
  player.map.c_floor = create_trgb(0x00, 0x90, 0x94, 0x90);
  player.map.ea = ft_strdup("./assets/ea.xpm");
  player.map.so = ft_strdup("./assets/so.xpm");
  player.map.no = ft_strdup("./assets/no.xpm");
  player.map.we = ft_strdup("./assets/we.xpm");

  player.map.map = (char **)malloc(sizeof(char *) * 18);
  player.map.map[0] =  ft_strdup("1111111111111111111111");
  player.map.map[1] =  ft_strdup("10000000000000000000001");
  player.map.map[2] =  ft_strdup("10000000000000000000011");
  player.map.map[3] =  ft_strdup("10000000000000000000011");
  player.map.map[4] =  ft_strdup("10000000000000000000011");
  player.map.map[5] =  ft_strdup("10000000000000000000011");
  player.map.map[6] =  ft_strdup("10000000000000000000011");
  player.map.map[7] =  ft_strdup("10000000000000000000011");
  player.map.map[8] =  ft_strdup("10000000000000000000011");
  player.map.map[9] =  ft_strdup("10000000000000000000001");
  player.map.map[10] = ft_strdup("10000000000000000000001");
  player.map.map[11] = ft_strdup("11111111111111111111111");
  player.map.map[12] = ft_strdup("11111111111111111111111");
  player.map.map[13] = ft_strdup("11111111111111111111111");
  player.map.map[14] = ft_strdup("11111111111111111111111");
  player.map.map[15] = ft_strdup("11111111111111111111111");
  player.map.map[16] = ft_strdup("11111111111111111111111");
  player.map.map[17] = NULL;
  
  player.radius = 2;
  player.position.x = TILE_SIZE + (TILE_SIZE / 2); 
  player.position.y =  TILE_SIZE + (TILE_SIZE / 2);
  
  player.movespeed = (TILE_SIZE * 2) / 50;
  player.viewangle = PI / 2;
  player.movesleft_or_right = 0;
  player.rotationspeed = 3 * (PI / 180);
  player.turndirection = 0;
  player.walkdirection = 0;
  
	player.mlx = mlx_init();
	player.mlx_win = mlx_new_window(player.mlx, SCREENWIDTH, SCREENHEIGHT, "Awesome cub3d!");
	img.img = mlx_new_image(player.mlx, SCREENWIDTH, SCREENHEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
  player.texture = get_texture_data(player.mlx, "./assets/we.xpm");
  player.img = &img;
  mlx_hook(player.mlx_win, 2, 1L << 0, presskey , &player);
  mlx_hook(player.mlx_win, 3, 1L << 0, releaskey , &player);
  mlx_loop_hook(player.mlx, &moveplayer, &player);
	mlx_loop(player.mlx);
}
