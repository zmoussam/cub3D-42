/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:31:05 by zmoussam          #+#    #+#             */
/*   Updated: 2023/02/12 12:12:55 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
    int i = 1000;
    int j = 500;
    int tmpi = 10;
    int tmpj = 1080;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    while(j < 550)
    {
        i = 1000;
        while(i < 1050)
        {
	        my_mlx_pixel_put(&img, i, j, 0x00FF0000);
            i++;
        }
        j++;
    }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
void drawLine(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
    int dx, dy, p;
    int x, y;
    
    dx = x2 - x1;
    dy = y2 - y1;
    
    x = x1;
    y = y1;
    
    p = 2 * dy - dx;
    
    while (x < x2)
    {
        if (p >= 0)
        {
            mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
            p = p + 2 * dy;
        }
        
        x = x + 1;
    }
}

int main()
{
    void *mlx;
    void *win;
    
    mlx = mlx_init();
    win = mlx_new_window(mlx, 400, 400, "Line Example");
    drawLine(mlx, win, 100, 100, 200, 200);
    mlx_loop(mlx);
    return 0;
}
// This code initializes the MLX library, creates a window with a width of 400 and a height of 400, calls the drawLine function to draw a line from the point (100,100) to the point (200,200), and enters the MLX event loop. The drawLine function uses the Bresenham's Line Algorithm to plot pixels along the line and draw the line on the screen using the MLX library.



