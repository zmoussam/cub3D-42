#include "cub3d.h"

void init_maps(t_cub3d *cub3d)
{
    cub3d->map = malloc(sizeof(char *) * 9);
    cub3d->map[0] = ft_strdup("11111111111111");
    cub3d->map[1] = ft_strdup("10000100100001");
    cub3d->map[2] = ft_strdup("10000000000001");
    cub3d->map[3] = ft_strdup("10000010000011");
    cub3d->map[4] = ft_strdup("10001001000001");
    cub3d->map[5] = ft_strdup("10001000100011");
    cub3d->map[6] = ft_strdup("10001000100001");
    cub3d->map[7] = ft_strdup("11111111111111");
    cub3d->map[8] = NULL;
}
