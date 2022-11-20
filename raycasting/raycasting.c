#include "../cub3d.h"

void raycasting(t_cub3d *cub3d)
{
    int x0, y0;
    double first_step_x, first_step_y;
    double second_step_x, second_step_y;
    int wall_x, wall_y;
    if (cub3d->angle >= M_PI_2 && cub3d->angle <= 3 * M_PI_2)
    {
        x0 = (cub3d->p_x / 64) * 64;
        first_step_x = (cub3d->p_x - x0) * -1;
        first_step_y = round(tan(cub3d->angle) * first_step_x);

        second_step_x = -64;
        second_step_y = round(tan(cub3d->angle) * second_step_x);
    }
    else
    {
        x0 = (cub3d->p_x / 64) * 64 + 64;
        first_step_x = x0 - cub3d->p_x;
        first_step_y = round(tan(cub3d->angle) * first_step_x);

        second_step_x = 64;
        second_step_y = round(tan(cub3d->angle) * second_step_x);
    }
    // wall_x = cub3d->p_x + first_step_x;
    // wall_y = cub3d->p_y + first_step_x;
    int x = first_step_x + cub3d->p_x;
    int y = first_step_y + cub3d->p_y;
    if (cub3d->angle >= M_PI_2 && cub3d->angle <= 3 * M_PI_2)
    {
        if ((first_step_x < 1000 && first_step_y < 10000 && first_step_x > -1000 && first_step_y > -10000))
        {
            if (((x / 64 > 0 && x / 64 < 14) && (y / 64 > 0 && y / 64 < 8)))
            {
                printf("maps[%d][%d] = %c\n", y / 64, x / 64, cub3d->map[y / 64][x / 64]);
                y--;
                x--;
                if (cub3d->map[(y / 64)][(x / 64)] == '1')
                    draw_line(cub3d, cub3d->p_x, cub3d->p_y, first_step_x + cub3d->p_x, first_step_y + cub3d->p_y, 0xf0ffffff / 6);
            }
        }
    }
    else
    {
        if ((first_step_x < 1000 && first_step_y < 10000 && first_step_x > -1000 && first_step_y > -10000))
        {
            if (((x / 64 > 0 && x / 64 < 14) && (y / 64 > 0 && y / 64 < 8)))
            {
                printf("maps[%d][%d] = %c\n", y / 64, x / 64, cub3d->map[y / 64][x / 64]);
                if (cub3d->map[(y / 64)][(x / 64)] == '1')
                    draw_line(cub3d, cub3d->p_x, cub3d->p_y, first_step_x + cub3d->p_x, first_step_y + cub3d->p_y, 0xf0ffffff / 6);
            }
        }
    }
}