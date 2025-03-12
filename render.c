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

void fill_img(t_mlx *mlx, int color)
{
	int x;
	int y;
	int x_zero;
	int y_zero;
	t_complex_number axis;
	x_zero = WINDOW_WIDTH / 2;
	y_zero = WINDOW_HEIGHT / 2;
	axis.imaginary = 0 - y_zero;


	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		axis.real = 0 - x_zero;
		while (x < WINDOW_WIDTH)
		{

			if (inside_set(axis))
				my_mlx_pixel_put(&mlx->img, x_zero + axis.real, y_zero + axis.imaginary, encode_rgb(0, 0, 255));
			x++;
			axis.real++;
		}
		y++;
		axis.imaginary++;
	}
}

void render_img(t_mlx *mlx)
{
	fill_img(mlx, encode_rgb(255, 0, 0));
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->img.ptr, 0, 0);
}
