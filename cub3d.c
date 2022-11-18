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
    draw_line(cub3d, cub3d->p_x, cub3d->p_y, cub3d->p_x + cos(cub3d->angle) * 50,
              cub3d->p_y + sin(cub3d->angle) * 50, 0xf0ffffff / 4);
}

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
            // if (cub3d->map[i][j] == '0')
            //     mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->space, j * 64, i * 64);
            if (cub3d->map[i][j] == '1')
                mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->wall, j * 64, i * 64);
            j++;
        }
        i++;
    }
}

int movemment(int key, t_cub3d *cub3d)
{
    if (key == M_L)
        cub3d->angle -= RETAION;
    if (key == M_R)
        cub3d->angle += RETAION;
    if (key == W)
    {
        // if (cub3d->map[(cub3d->p_y - 16)/64][(cub3d->p_x - 16)/64] == '1')
        //     ;
        // else
        // {
            cub3d->p_y += round(8 * sin(cub3d->angle));
            cub3d->p_x += round(8 * cos(cub3d->angle));
        // }
    }
    if (key == S)
    {
        // if (cub3d->map[(cub3d->p_y + 16)/64][(cub3d->p_x + 16)/64] == '1')
        //     ;
        // else
        // {
            cub3d->p_y -= round(8 * sin(cub3d->angle));
            cub3d->p_x -= round(8 * cos(cub3d->angle));
        // }
    }
    if (key == A)
    {
        // if (cub3d->map[(cub3d->p_y + 16)/64][(cub3d->p_x + 16)/64] == '1')
        //     ;
        // else
        // {
            cub3d->p_x -= round(8 * cos(cub3d->angle + M_PI_2));
            cub3d->p_y -= round(8 * sin(cub3d->angle + M_PI_2));
        // }
    }
    if (key == D)
    {
        // if (cub3d->map[(cub3d->p_y - 16)/64][(cub3d->p_x - 16)/64] == '1')
        //     ;
        // else
        // {
            cub3d->p_y += round(8 * sin(cub3d->angle + M_PI_2));
            cub3d->p_x += round(8 * cos(cub3d->angle + M_PI_2));
        // }
    }

    if (key == ESC)
        exit(0);
    mlx_clear_window(cub3d->mlx, cub3d->window);
    add_image(cub3d);
    ft_mov(cub3d);
    return (0);
}

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
    mlx_hook(cub3d->window, 2, 1L << 1, movemment, cub3d);
    mlx_loop(cub3d->mlx);
    return (0);
}
