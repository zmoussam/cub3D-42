#include "cub3d.h"

int main()
{
    t_cub3d *cub3d;

    cub3d = malloc(sizeof(t_cub3d));
    cub3d->p_x = 5 * BLOCK;
    cub3d->p_y = 3 * BLOCK;
    cub3d->angle = M_PI_2;
    init_maps(cub3d);
    cub3d->mlx = mlx_init();
    cub3d->window = mlx_new_window(cub3d->mlx, WIDTH, HIGHT, "CUB3D");
    add_image(cub3d);
    ft_mov(cub3d);
    mlx_hook(cub3d->window, 2, 1L << 1, movement, cub3d);
    mlx_loop(cub3d->mlx);
    return (0);
}
