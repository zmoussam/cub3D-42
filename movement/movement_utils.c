#include "../cub3d.h"

void add_image(t_cub3d *cub3d)
{
    int width;
    int height;
    cub3d->space = mlx_xpm_file_to_image(cub3d->mlx, "image/space.xpm", &width, &height);
    cub3d->wall = mlx_xpm_file_to_image(cub3d->mlx, "image/wall.xpm", &width, &height);
    int i = 0;
    while (cub3d->map[i])
    {
        int j = 0;
        while (cub3d->map[i][j])
        {
            if (cub3d->map[i][j] == '1')
                mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->wall, j * 64, i * 64);
            // else
            //     mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->space, j * 64, i * 64);
            j++;
        }
        i++;
    }
}
