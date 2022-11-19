#include "../cub3d.h"

void raycasting(t_cub3d *cub3d)
{
    int x0, y0;
    double Dx, Dy;
    if (cub3d->angle >= M_PI_2 && cub3d->angle <= 3 * M_PI_2)
    {
        x0 = (cub3d->p_x / 64) * 64 + 64;
        Dx = x0 - cub3d->p_x + cub3d->p_x;
        Dy = tan(cub3d->angle) * Dx + cub3d->p_y;
        printf("->>>maps[%d][%d]\n", (int)Dy, (int)Dx);
        if (Dx < 1000 && Dy < 10000 && Dx > -1000 && Dy > -10000)
            draw_line(cub3d, cub3d->p_x, cub3d->p_y, Dx, Dy, 0xf0ffffff / 6);
    }
    else
    {
        
    }
}