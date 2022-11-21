#include "cub3d.h"

int main(int ac, char **av)
{
  t_cub3d *cub3d;
  int i;

  if (ac != 2)
    _error("cub3d: error: invalid argument!!\n");
  cub3d = malloc(sizeof(t_cub3d));
  if (!cub3d)
    return (0);
  i = 0;
  cub3d->ea = NULL;
  cub3d->no = NULL;
  cub3d->so = NULL;
  cub3d->we = NULL;
  cub3d->floor = -1;
  cub3d->ceilling = -1;
  if (!parsing(cub3d, av[1]))
    exit(1);
  cub3d->p_x = 5 * BLOCK;
  cub3d->p_y = 3 * BLOCK;
  cub3d->angle = M_PI_2;
  cub3d->mlx = mlx_init();
  cub3d->window = mlx_new_window(cub3d->mlx, WIDTH, HIGHT, "CUB3D");
  add_image(cub3d);
  ft_mov(cub3d);
  mlx_hook(cub3d->window, 2, 1L << 1, movement, cub3d);
  mlx_loop(cub3d->mlx);
  return (0);
}
