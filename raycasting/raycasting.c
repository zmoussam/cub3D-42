#include "../cub3d.h"

void vertical_line_left(t_cub3d *cub3d)
{
    int x0;

    x0 = (int)(cub3d->p_x / 64) * 64;
    cub3d->ray_vertical.first_x = (cub3d->p_x - x0) * -1;
    cub3d->ray_vertical.first_y = tan(cub3d->angle) * cub3d->ray_vertical.first_x;
}

void vertical_line_right(t_cub3d *cub3d)
{
    int x0;

    x0 = (int)(cub3d->p_x / 64) * 64 + 64;
    cub3d->ray_vertical.first_x = x0 - cub3d->p_x;
    cub3d->ray_vertical.first_y = tan(cub3d->angle) * cub3d->ray_vertical.first_x;
}

/*- - -  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void horizental_line_up(t_cub3d *cub3d)
{
    int y0;

    y0 = (int)(cub3d->p_y / 64) * 64;
    cub3d->ray_horizental.first_y = (cub3d->p_y - y0) * -1;
    cub3d->ray_horizental.first_x = cub3d->ray_horizental.first_y / tan(cub3d->angle);
}

void horizental_line_down(t_cub3d *cub3d)
{
    int y0;

    y0 = (int)(cub3d->p_y / 64) * 64 + 64;
    cub3d->ray_horizental.first_y = y0 - cub3d->p_y;
    cub3d->ray_horizental.first_x = cub3d->ray_horizental.first_y / tan(cub3d->angle);
}

/*- - -  - - - - - - - - - - - - - - - - vertical  - - - - - - - - - - - - - - - */

int raycasting_vertical(t_cub3d *cub3d)
{
    int flag_vertical = 0;

    if (cub3d->angle >= M_PI_2 && cub3d->angle <= 3 * M_PI_2)
    {
        vertical_line_left(cub3d);
        cub3d->ray_vertical.x = cub3d->ray_vertical.first_x + cub3d->p_x;
        cub3d->ray_vertical.y = cub3d->ray_vertical.first_y + cub3d->p_y;
        cub3d->ray_vertical.x--;
        while ((cub3d->ray_vertical.x < WIDTH && cub3d->ray_vertical.y < HIGHT && cub3d->ray_vertical.x > 0 && cub3d->ray_vertical.y > 0))
        {
            if (cub3d->map[(int)(cub3d->ray_vertical.y / 64)][(int)(cub3d->ray_vertical.x / 64)] == '1')
            {
                flag_vertical = 1;
                break;
            }
            cub3d->ray_vertical.x -= 64;
            cub3d->ray_vertical.y += tan(cub3d->angle) * -64;
        }
    }

    else
    {
        vertical_line_right(cub3d);
        cub3d->ray_vertical.x = cub3d->ray_vertical.first_x + cub3d->p_x;
        cub3d->ray_vertical.y = cub3d->ray_vertical.first_y + cub3d->p_y;
        while ((cub3d->ray_vertical.x < WIDTH && cub3d->ray_vertical.y < HIGHT && cub3d->ray_vertical.x > 0 && cub3d->ray_vertical.y > 0))
        {
            if (cub3d->map[(int)(cub3d->ray_vertical.y / 64)][(int)(cub3d->ray_vertical.x / 64)] == '1')
            {
                flag_vertical = 1;
                break;
            }
            cub3d->ray_vertical.x += 64;
            cub3d->ray_vertical.y += tan(cub3d->angle) * 64;
        }
    }
    return (flag_vertical);
}

/*- - -  - - - - - - - - - - - - - - - horizental - - - - - - - - - - - - - - - - - - - */

int raycasting_horizental(t_cub3d *cub3d)
{
    int flag_horizental;

    flag_horizental = 0;
    if (cub3d->angle <= 2 * M_PI && cub3d->angle >= M_PI)
    {
        horizental_line_up(cub3d);
        cub3d->ray_horizental.x = cub3d->ray_horizental.first_x + cub3d->p_x;
        cub3d->ray_horizental.y = cub3d->ray_horizental.first_y + cub3d->p_y;
        cub3d->ray_horizental.y--;
        while ((cub3d->ray_horizental.x < WIDTH && cub3d->ray_horizental.y < HIGHT && cub3d->ray_horizental.x > 0 && cub3d->ray_horizental.y > 0))
        {
            if (cub3d->map[(int)(cub3d->ray_horizental.y / 64)][(int)(cub3d->ray_horizental.x / 64)] == '1')
            {
                flag_horizental = 1;
                break;
            }
            cub3d->ray_horizental.y -= 64;
            cub3d->ray_horizental.x += -64 / tan(cub3d->angle);
        }
    }
    else
    {
        horizental_line_down(cub3d);
        cub3d->ray_horizental.x = cub3d->ray_horizental.first_x + cub3d->p_x;
        cub3d->ray_horizental.y = cub3d->ray_horizental.first_y + cub3d->p_y;
        while ((cub3d->ray_horizental.x < WIDTH && cub3d->ray_horizental.y < HIGHT && cub3d->ray_horizental.x > 0 && cub3d->ray_horizental.y > 0))
        {
            if (cub3d->map[(int)(cub3d->ray_horizental.y / 64)][(int)(cub3d->ray_horizental.x / 64)] == '1')
            {
                flag_horizental = 1;
                break;
            }
            cub3d->ray_horizental.y += 64;
            cub3d->ray_horizental.x += 64 / tan(cub3d->angle);
        }
    }
    return (flag_horizental);
}
void initialisation(t_cub3d *cub3d)
{
    cub3d->ray_horizental.first_y = 0;
    cub3d->ray_horizental.first_x = 0;
    cub3d->ray_horizental.flag_horizental = 0;
    cub3d->ray_horizental.flag_vertical = 0;
    cub3d->ray_horizental.x = 0;
    cub3d->ray_horizental.y = 0;
    cub3d->ray_vertical.first_y = 0;
    cub3d->ray_vertical.first_x = 0;
    cub3d->ray_vertical.flag_vertical = 0;
    cub3d->ray_vertical.flag_vertical = 0;
    cub3d->ray_vertical.x = 0;
    cub3d->ray_vertical.y = 0;
}
void raycasting(t_cub3d *cub3d)
{
    initialisation(cub3d);
    double z_h, z_v;
    int flag_v = raycasting_vertical(cub3d);
    int flag_h = raycasting_horizental(cub3d);

    if (cub3d->ray_vertical.y < 0)
        cub3d->ray_vertical.y = 0;
    if (cub3d->ray_vertical.y > HIGHT)
        cub3d->ray_vertical.y = HIGHT;
    if (flag_v == 1)
        z_v = sqrt(cub3d->ray_vertical.x * cub3d->ray_vertical.x + cub3d->ray_vertical.y * cub3d->ray_vertical.y);
    else
        z_v = MAX_INT;
    if (flag_h == 1)
        z_h = sqrt(cub3d->ray_horizental.x * cub3d->ray_horizental.x + cub3d->ray_horizental.y * cub3d->ray_horizental.y);
    else
        z_h = MAX_INT;
    if (z_h > z_v)
    {
        if ((cub3d->ray_vertical.x <= WIDTH && cub3d->ray_vertical.y <= HIGHT && cub3d->ray_vertical.x >= 0 && cub3d->ray_vertical.y >= 0))
            draw_line(cub3d, cub3d->p_x, cub3d->p_y, cub3d->ray_vertical.x, cub3d->ray_vertical.y, 0xf0ffffff / 6);
    }
    else
    {
        if ((cub3d->ray_horizental.x <= WIDTH && cub3d->ray_horizental.y <= HIGHT && cub3d->ray_horizental.x >= 0 && cub3d->ray_horizental.y >= 0))
            draw_line(cub3d, cub3d->p_x, cub3d->p_y, cub3d->ray_horizental.x, cub3d->ray_horizental.y, 0xf0ffffff / 6);
    }
    printf("%f | %f\n", z_v, z_h);
    printf("%f\n", cub3d->angle);
}
