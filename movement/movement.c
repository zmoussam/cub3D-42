#include "../cub3d.h"

void draw_line(t_cub3d *cub, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX = endX - beginX;                            // 10
    double deltaY = endY - beginY;                            // 5
    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY)); // 11.1
    deltaX /= pixels;                                         // 0
    deltaY /= pixels;                                         // 0
    double pixelX = beginX;                                   // 10
    double pixelY = beginY;                                   // 5
    while (pixels)
    {
        mlx_pixel_put(cub->mlx, cub->window, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
}
void ft_mov(t_cub3d *cub3d)
{
    int y = cub3d->p_y - 2;
    while (y < cub3d->p_y + 2)
    {
        int x = cub3d->p_x - 2;
        while (x < cub3d->p_x + 2)
            mlx_pixel_put(cub3d->mlx, cub3d->window, x++, y, 0xf0ffffff / 10);
        y++;
    }
    // draw_line(cub3d, cub3d->p_x, cub3d->p_y, cub3d->p_x + cos(cub3d->angle) * 50,
    //           cub3d->p_y + sin(cub3d->angle) * 50, 0xf0ffffff / 4);
}

int movement(int key, t_cub3d *cub3d)
{
    if (key == M_L)
        cub3d->angle -= RETAION;
    if (key == M_R)
        cub3d->angle += RETAION;
    if (key == W)
    {
        cub3d->p_y += round(8 * sin(cub3d->angle));
        cub3d->p_x += round(8 * cos(cub3d->angle));
        

        printf("maps[%d][%d]\n", cub3d->p_y, cub3d->p_x);
    }
    if (key == S)
    {
        cub3d->p_y -= round(8 * sin(cub3d->angle));
        cub3d->p_x -= round(8 * cos(cub3d->angle));
        
        printf("maps[%d][%d]\n", cub3d->p_y, cub3d->p_x);
    }
    if (key == A)
    {

        cub3d->p_x -= round(8 * cos(cub3d->angle + M_PI_2));
        cub3d->p_y -= round(8 * sin(cub3d->angle + M_PI_2));
       

        printf("maps[%d][%d]\n", cub3d->p_y, cub3d->p_x);
    }
    if (key == D)
    {
        cub3d->p_y += round(8 * sin(cub3d->angle + M_PI_2));
        cub3d->p_x += round(8 * cos(cub3d->angle + M_PI_2));

        printf("maps[%d][%d]\n", cub3d->p_y, cub3d->p_x);
    }
    if (key == ESC)
        exit(0);
    mlx_clear_window(cub3d->mlx, cub3d->window);
    add_image(cub3d);
    ft_mov(cub3d);
    raycasting(cub3d);

    return (0);
}