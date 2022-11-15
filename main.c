#include "cub3d.h"

void init_maps(t_cub3d *cub3d)
{
    cub3d->map = malloc(sizeof(char *) * 13);
    cub3d->map[0] = ft_strdup("111111111111111111111111111111111111111111");
    cub3d->map[1] = ft_strdup("100100001000000000000000000000000000000001");
    cub3d->map[2] = ft_strdup("101000001000000000000000000000000000000001");
    cub3d->map[3] = ft_strdup("10010N001010000000000000000000000000000000");
    cub3d->map[4] = ft_strdup("101000001010000000000000000000000000000001");
    cub3d->map[5] = ft_strdup("100000000000000000000000000000000000001001");
    cub3d->map[6] = ft_strdup("100000000000000000000000000000000000001001");
    cub3d->map[7] = ft_strdup("100000000000000000000000000000000000000101");
    cub3d->map[8] = ft_strdup("100000000000000000000000000000000000000101");
    cub3d->map[9] = ft_strdup("100000000000000000000000000000000000000101");
    cub3d->map[10] = ft_strdup("100000000000000000000000000000000000000101");
    cub3d->map[11] = ft_strdup("111111111111111111111111111111111111111111");
    cub3d->map[12] = NULL;
}

void ft_mov(t_cub3d *cub3d)
{
    int i = 64;
    while (i < 64 * cub3d->p_x)
    {
        int j = 64;
        while (j < 64 * cub3d->p_y)
            mlx_pixel_put(cub3d->mlx, cub3d->window, i, j++, 0xf0f0ffff / 4);
        i++;
    }
}

int movemment(int key, t_cub3d *cub3d)
{
    if (key == W)
    {
        mlx_clear_window(cub3d->mlx, cub3d->window);
        ft_mov(cub3d);
        cub3d->p_y--;
    }
    if (key == S)
    {
        mlx_clear_window(cub3d->mlx, cub3d->window);
        ft_mov(cub3d);
        cub3d->p_y++;
    }
    if (key == A)
    {
        mlx_clear_window(cub3d->mlx, cub3d->window);
        ft_mov(cub3d);
        cub3d->p_x--;
    }
    if (key == D)
    {
        mlx_clear_window(cub3d->mlx, cub3d->window);
        ft_mov(cub3d);
        cub3d->p_x++;
    }
    if (key == ESC)
        exit(0);
    return (0);
}

int main()
{
    int p_x = 3;
    int p_y = 5;
    t_cub3d *cub3d;
    cub3d = malloc(sizeof(t_cub3d));
    cub3d->p_x = p_x;
    cub3d->p_y = p_y;
    init_maps(cub3d);
    cub3d->mlx = mlx_init();
    cub3d->window = mlx_new_window(cub3d->mlx, WIDTH, HIGHT, "./a.out");
    mlx_hook(cub3d->window, 2, 1L << 1, movemment, cub3d);
    // mlx_clear_window(cub3d->mlx, cub3d->window);
    mlx_loop(cub3d->mlx);
    return (0);
}
