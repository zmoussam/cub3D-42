#include "../cub3d.h"

t_ray vertical_line_left(t_cub3d *cub3d)
{
    t_ray step_left;
    int x0;

    x0 = (cub3d->p_x / 64) * 64;
    step_left.first_x = (cub3d->p_x - x0) * -1;
    step_left.first_y = round(tan(cub3d->angle) * step_left.first_x);
    step_left.second_x = -64;
    step_left.second_y = round(tan(cub3d->angle) * step_left.second_x);
    return (step_left);
}

t_ray vertical_line_right(t_cub3d *cub3d)
{
    t_ray step_right;
    int x0;

    x0 = (cub3d->p_x / 64) * 64 + 64;
    step_right.first_x = x0 - cub3d->p_x;
    step_right.first_y = round(tan(cub3d->angle) * step_right.first_x);
    step_right.second_x = 64;
    step_right.second_y = round(tan(cub3d->angle) * step_right.second_x);
    return (step_right);
}
void raycasting(t_cub3d *cub3d)
{
    t_ray step_left;
    t_ray step_right;
    t_ray step_up;
    t_ray step_down;

    if (cub3d->angle >= M_PI_2 && cub3d->angle <= 3 * M_PI_2)
    {
        step_left = vertical_line_left(cub3d);
        int x = (int)step_left.first_x + cub3d->p_x;
        int y = (int)step_left.first_y + cub3d->p_y;
        x--;
        // printf("x = %d\n",x);
        // printf("y = %d\n",y);
        // while ((x < WIDTH && y < HIGHT && x > 0 && y > 0))
        // {
        //     if (cub3d->map[y / 64][x / 64] == '1')
        //     {
        //         break;
        //     }
        //     x += step_left.second_x;
        //     y += step_left.second_y;
        //     printf("---\n");
        // }
        draw_line(cub3d, cub3d->p_x, cub3d->p_y, x, y, 0xf0ffffff / 6);
    }
    // else if (cub3d->angle >= 3 * M_PI_2 || cub3d->angle <= M_PI_2)
    // {
    //     step_right = vertical_line_right(cub3d);
    //     int x = step_right.first_x + cub3d->p_x;
    //     int y = step_right.first_y + cub3d->p_y;
    //     if ((step_right.first_x < 1000 && step_right.first_y < 10000 && step_right.first_x > -1000 && step_right.first_y > -10000))
    //     {
    //         draw_line(cub3d, cub3d->p_x, cub3d->p_y, x, y, 0xf0ffffff / 6);
    //     }
    // }
}