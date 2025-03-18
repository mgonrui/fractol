#include "fractol.h"
#include <stdio.h>

static int	encode_rgb(byte red, byte green, byte blue)
{
    return (red << 16 | green << 8 | blue);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len+ x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}


static void fill_img(t_mlx *mlx)
{
	int x;
	int y;
	int iterations;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		mlx->c.imaginary = (scale(y, -2, + 2, 0, WINDOW_HEIGHT) / mlx->zoom) + mlx->shift_y;
		while (x < WINDOW_WIDTH)
		{
			mlx->c.real = (scale(x, -2, + 2, 0, WINDOW_WIDTH) / mlx->zoom) + mlx->shift_x;
			iterations = inside_set(mlx);
			if (iterations > 1  && iterations <= 20)
				my_mlx_pixel_put(&mlx->img, x, y, encode_rgb(scale(iterations, 0, 255, 1, 50), 0, 0));
			else if (iterations > 20  && iterations <= 50)
				my_mlx_pixel_put(&mlx->img, x, y, encode_rgb(0, 0, scale(iterations, 0, 255, 1, 50)));
			else if (iterations > 50  && iterations <= MAX_ITERATIONS)
				my_mlx_pixel_put(&mlx->img, x, y, encode_rgb(0, scale(iterations, 0, 255, 1, 50), 0));
			else
				my_mlx_pixel_put(&mlx->img, x, y, encode_rgb(0, 0, 0));
			x++;
		}
		y++;
	}
}

void render_img(t_mlx *mlx)
{
	fill_img(mlx);
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->img.ptr, 0, 0);
}
