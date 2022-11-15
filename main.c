#include "cub3d.h"

void init_maps(t_cub3d *cub3d)
{
    cub3d->map = malloc(sizeof(char *) * 8);
    cub3d->map[0] = ft_strdup("11111111111");
    cub3d->map[1] = ft_strdup("10010000101");
    cub3d->map[2] = ft_strdup("10100000101");
    cub3d->map[3] = ft_strdup("10010N00101");
    cub3d->map[4] = ft_strdup("10100000101");
    cub3d->map[5] = ft_strdup("10000000101");
    cub3d->map[6] = ft_strdup("11111111111");
    cub3d->map[7] = NULL;
}

int movemment(int key, t_cub3d *cub3d)
{
    int width;
    int height;
    if (key == W)
    {
        cub3d->p = mlx_xpm_file_to_image(cub3d->mlx, "player.xpm", &width, &height);
        mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->p, cub3d->i, cub3d->i);
        cub3d->i -= 64;
    }
    if (key == S)
    {
        cub3d->p = mlx_xpm_file_to_image(cub3d->mlx, "player.xpm", &width, &height);
        mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->p, cub3d->i, cub3d->i);
        cub3d->i += 64;
    }
    if (key == A)
    {
        cub3d->p = mlx_xpm_file_to_image(cub3d->mlx, "player.xpm", &width, &height);
        mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->p, cub3d->i, cub3d->i);
        cub3d->i -= 64;
    }
    if (key == D)
    {
        cub3d->p = mlx_xpm_file_to_image(cub3d->mlx, "player.xpm", &width, &height);
        mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->p, cub3d->i, cub3d->i);
        cub3d->i += 64;
    }
    if (key == ESC)
        exit(0);
    return (0);
}

int main()
{
    t_cub3d *cub3d;
    cub3d = malloc(sizeof(t_cub3d));
    cub3d->i = 64;
    init_maps(cub3d);
    cub3d->mlx = mlx_init();
    cub3d->window = mlx_new_window(cub3d->mlx, WIDTH, HIGHT, "./a.out");
    mlx_hook(cub3d->window, 2, 1L << 1, movemment, cub3d);
    mlx_loop(cub3d->mlx);
    return (0);
}