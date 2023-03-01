/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:11 by zmoussam          #+#    #+#             */
/*   Updated: 2023/03/01 05:17:17 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int	esc_hook(t_mlx *mlx)
{
	printf("game over!!!\n");
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

t_texture *get_texture(t_mlx *mlx, char *file_name)
{
    t_texture *texture;
    
    texture = (t_texture *)malloc(sizeof(t_texture));
    texture->info = (t_img_data *)malloc(sizeof(t_img_data));
    texture->info->img = mlx_xpm_file_to_image(mlx->mlx, file_name, \
    &texture->_width, &texture->_heigth);
    return (texture);
}
int handle_mouse(int x, int y, t_collect_data *data)
{
    static int mouse_pos;
    
    // printf("x = %d\n", button);
    data->player->release_mouse = 1;
    if (x > mouse_pos)
        data->player->turndirection = 1;
    else if (x < mouse_pos)
        data->player->turndirection = -1;
    y = 0;
        mouse_pos = x;
    return (0);
}
t_texture **get_weapon_texture(t_mlx *mlx)
{
    t_texture **weapon;

    weapon = (t_texture **)malloc(sizeof(t_texture *) * 3);
    if (!weapon)
        return (NULL);
    weapon[0] = get_texture(mlx, "./assets/weapon_1.xpm");
    weapon[1] = get_texture(mlx, "./assets/weapon_2.xpm");
    weapon[2] = get_texture(mlx, "./assets/weapon_3.xpm");
    return (weapon);
}
t_texture **get_digit_texture(t_mlx *mlx)
{
    t_texture **digit;

    digit = (t_texture **)malloc(sizeof(t_texture *) * 10);
    if (!digit)
        return (NULL);
    digit[0] = get_texture(mlx, "./assets/0.xpm");
    digit[1] = get_texture(mlx, "./assets/1.xpm");
    digit[2] = get_texture(mlx, "./assets/2.xpm");
    digit[3] = get_texture(mlx, "./assets/3.xpm");
    digit[4] = get_texture(mlx, "./assets/4.xpm");
    digit[5] = get_texture(mlx, "./assets/5.xpm");
    digit[6] = get_texture(mlx, "./assets/6.xpm");
    digit[7] = get_texture(mlx, "./assets/7.xpm");
    digit[8] = get_texture(mlx, "./assets/8.xpm");
    digit[9] = get_texture(mlx, "./assets/9.xpm");
    
    return (digit);
}
int main(int arc, char **arv)
{
    t_map_info map_info;
    t_collect_data all_data;
    t_player player;
    t_mlx mlx;
    t_img_data img;
    t_img_data mini_map;
    t_texture *shooting_target;
    t_texture **weapon;
    t_texture *texture;
    t_texture **digit;
    t_texture *amo;
    arc = 0;
    (void)arv;
    base_parsing(arv[1], &map_info);
    // init_map(&map_info);
    init_player(&player, map_info.map);
    
    mlx.mlx = mlx_init();
    mlx.mlx_win = mlx_new_window(mlx.mlx, SCREENWIDTH, SCREENHEIGHT, "Awesome cub3d!");
    img.img = mlx_new_image(mlx.mlx, SCREENWIDTH, SCREENHEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    mini_map.img = mlx_new_image(mlx.mlx, MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
    mini_map.addr = mlx_get_data_addr(mini_map.img, &mini_map.bits_per_pixel, &mini_map.line_length, &mini_map.endian);
    texture = get_wall_texture(mlx.mlx, &map_info);
    shooting_target = get_texture(&mlx, "./assets/shooting_target.xpm");
    weapon = get_weapon_texture(&mlx);
    digit = get_digit_texture(&mlx);
    amo = get_texture(&mlx, "./assets/amo.xpm");
    mlx.img = &img;
    all_data.map_info = &map_info;
    all_data.mlx = &mlx;
    all_data.player = &player;
    all_data.texture = get_wall_texture(mlx.mlx, &map_info);
    all_data.mini_map = &mini_map;
    all_data.shooting_target = shooting_target;
    all_data.weapon = weapon;
    all_data.digit = digit;
    all_data.amo = amo;
    
    mlx_hook(mlx.mlx_win, 2, 1L << 0, presskey, all_data.player);
    mlx_hook(mlx.mlx_win, 3, 1L << 1, releaskey, all_data.player);
    mlx_hook(mlx.mlx_win, 17, 1L, esc_hook, &mlx);
    mlx_hook(mlx.mlx_win, 6, 1 << 6 , handle_mouse, &all_data);
    mlx_loop_hook(mlx.mlx, moveplayer, &all_data);
    mlx_loop(mlx.mlx);
}