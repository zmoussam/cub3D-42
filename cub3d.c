#include "cub3d.h"

void init_maps(t_cub3d *cub3d)
{
    cub3d->map = malloc(sizeof(char *) * 13);
    cub3d->map[0] = ft_strdup("111111111111111111111111111111");
    cub3d->map[1] = ft_strdup("100100001000000000000000000001");
    cub3d->map[2] = ft_strdup("101000001000000000000000000001");
    cub3d->map[3] = ft_strdup("100100001010000000000000000001");
    cub3d->map[4] = ft_strdup("101000001010000000000000000001");
    cub3d->map[5] = ft_strdup("100000000000000000000000000001");
    cub3d->map[6] = ft_strdup("100000000000000000011111100001");
    cub3d->map[7] = ft_strdup("100000000000000000000000100001");
    cub3d->map[8] = ft_strdup("100000000000000000000000100001");
    cub3d->map[9] = ft_strdup("100000000000000000001111100001");
    cub3d->map[10] = ft_strdup("100000000000000000000000000001");
    cub3d->map[11] = ft_strdup("111111111111111111111111111111");
    cub3d->map[12] = NULL;
}

void ft_mov(t_cub3d *cub3d)
{
    int i = cub3d->p_x - 16;
    while (i < cub3d->p_x + 16)
    {
        int j = cub3d->p_y - 16;
        while (j < cub3d->p_y + 16)
            mlx_pixel_put(cub3d->mlx, cub3d->window, i, j++, 0xf0ffffff/10);
        i++;
    }
}


void    add_image(t_cub3d *cub3d)
{
    int	width;
	int	height;
    cub3d->space = mlx_xpm_file_to_image(cub3d->mlx,"image/space.xpm",&width, &height);
    cub3d->wall = mlx_xpm_file_to_image(cub3d->mlx,"image/wall.xpm",&width, &height);
    int i = 0;
    while (cub3d->map[i])
    {
        int j = 0;
        while (cub3d->map[i][j])
        {
            if (cub3d->map[i][j] == '0')
                    mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->space, j*64,i*64);
            else if (cub3d->map[i][j] == '1')
                    mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->wall, j*64,i*64);
            j++;
        }
        i++;
    }
}

int movemment(int key, t_cub3d *cub3d)
{
    printf("%d\n",key);
    if (key == W)
    {
        if (cub3d->map[(cub3d->p_y -16)/64][cub3d->p_x/64] == '1');
        else
            cub3d->p_y-=16;
    }
    if (key == S)
    {
        if (cub3d->map[(cub3d->p_y +16 )/64][cub3d->p_x/64] == '1');
        else
            cub3d->p_y+=16;
    }
    if (key == A)
    {
        if (cub3d->map[(cub3d->p_y)/64][(cub3d->p_x - 16)/64] == '1');
        else
            cub3d->p_x-=16;
    }
    if (key == D)
    {
        if (cub3d->map[(cub3d->p_y)/64][(cub3d->p_x + 16)/64] == '1');
        else
            cub3d->p_x+=16;
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
    int p_x = 300;
    int p_y = 300;
    t_cub3d *cub3d;
    cub3d = malloc(sizeof(t_cub3d));
    cub3d->p_x = p_x;
    cub3d->p_y = p_y;
    init_maps(cub3d);
    cub3d->mlx = mlx_init();
    cub3d->window = mlx_new_window(cub3d->mlx, WIDTH, HIGHT, "./a.out");
    mlx_hook(cub3d->window, 2, 1L << 1, movemment, cub3d);
    mlx_loop(cub3d->mlx);
    return (0);
}
