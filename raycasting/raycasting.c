#include "../cub3d.h"

t_ray vertical_line_left(t_cub3d *cub3d)
{
    t_ray step_left;
    int x0;

    x0 = (int)(cub3d->p_x / 64) * 64;
    step_left.first_x = (cub3d->p_x - x0) * -1;
    step_left.first_y = tan(cub3d->angle) * step_left.first_x;
    return (step_left);
}

t_ray vertical_line_right(t_cub3d *cub3d)
{
    t_ray step_right;
    int x0;

    x0 = (int)(cub3d->p_x / 64) * 64 + 64;
    step_right.first_x = x0 - cub3d->p_x;
    step_right.first_y = tan(cub3d->angle) * step_right.first_x;
    return (step_right);
}

t_ray horizental_line_up(t_cub3d *cub3d)
{
    t_ray step_up;
    int y0;

    y0 = (int)(cub3d->p_y / 64) * 64;
    step_up.first_y = (cub3d->p_y - y0) * -1;
    step_up.first_x = step_up.first_y / tan(cub3d->angle);
    return (step_up);
}

t_ray horizental_line_down(t_cub3d *cub3d)
{
    t_ray step_down;
    int y0;

    y0 = (int)(cub3d->p_y / 64) * 64 + 64;
    step_down.first_y = y0 - cub3d->p_y;
    step_down.first_x = step_down.first_y / tan(cub3d->angle);
    return (step_down);
}
void raycasting(t_cub3d *cub3d)
{
    t_ray step_left;
    t_ray step_right;
    t_ray step_up;
    t_ray step_down;
    double x_h;
    double y_h;
    double x_v;
    double y_v;

    // if (cub3d->angle >= M_PI_2 && cub3d->angle <= 3 * M_PI_2)
    // {
    //     step_left = vertical_line_left(cub3d);
    //     x_v = step_left.first_x + cub3d->p_x;
    //     y_v = step_left.first_y + cub3d->p_y;
    //     x_v--;
    //     while ((x_v < WIDTH && y_v < HIGHT && x_v > 0 && y_v > 0))
    //     {
    //         if (cub3d->map[(int)(y_v / 64)][(int)(x_v / 64)] == '1')
    //             break;
    //         x_v -= 64;
    //         y_v += tan(cub3d->angle) * -64;
    //     }
    // }
    // else if (cub3d->angle >= 3 * M_PI_2 || cub3d->angle <= M_PI_2)
    // {
    //     step_right = vertical_line_right(cub3d);
    //     x_v = step_right.first_x + cub3d->p_x;
    //     y_v = step_right.first_y + cub3d->p_y;
    //     while ((x_v < WIDTH && y_v < HIGHT && x_v > 0 && y_v > 0))
    //     {
    //         if (cub3d->map[(int)(y_v / 64)][(int)(x_v / 64)] == '1')
    //             break;
    //         x_v += 64;
    //         y_v += tan(cub3d->angle) * 64;
    //     }
    // }
    if (cub3d->angle <= 0 && cub3d->angle >= M_PI)
    {
        step_up = horizental_line_up(cub3d);
        x_h = step_up.first_x + cub3d->p_x;
        y_h = step_up.first_y + cub3d->p_y;
        while ((x_h < WIDTH && y_h < HIGHT && x_h > 0 && y_h > 0))
        {
            if (cub3d->map[(int)(y_h / 64)][(int)(x_h / 64)] == '1')
                break;
            y_h -= 64;
            x_h += tan(cub3d->angle) * -64;
        }
    }
    else if (cub3d->angle <= M_PI && cub3d->angle >= 0)
    {
        step_down = horizental_line_down(cub3d);
        x_h = step_down.first_x + cub3d->p_x;
        y_h = step_down.first_y + cub3d->p_y;
        while ((x_h < WIDTH && y_h < HIGHT && x_h > 0 && y_h > 0))
        {
            if (cub3d->map[(int)(y_h / 64)][(int)(x_h / 64)] == '1')
                break;
            y_h += 64;
            x_h += tan(cub3d->angle) * 64;
        }
    }
    int x, y;
    // if (x_h > x_v && y_h > y_v)
    // {
    x = x_h;
    y = y_h;
    // }
    // else
    // {
    //     x = x_h;
    //     y = y_h;
    // }
    printf("%d | %d\n", x, y);
    if ((x < WIDTH && y < HIGHT && x > 0 && y > 0))
        draw_line(cub3d, cub3d->p_x, cub3d->p_y, x, y, 0xf0ffffff / 6);
}