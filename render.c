#include "fractol.h"

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
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(&mlx->img, x, y, color);
			x++;
		}
		y++;
	}
}

void render_img(t_mlx *mlx)
{
	fill_img(mlx, encode_rgb(255, 0, 0));
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->img.ptr, 0, 0);
}
