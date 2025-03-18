#include "fractol.h"
#include <stdio.h>

static int	rgb(byte red, byte green, byte blue)
{
    return (red << 16 | green << 8 | blue);
}

static void	mypp(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len+ x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static float scale(float unnu, float nemi, float nema, float olmi, float olma)
{
    return (nema - nemi) * (unnu - olmi) / (olma - olmi) + nemi;
}


static void fill_img(t_mlx *mlx)
{
	int x;
	int y;
	int iter;

	y = 0;
	while (y < HEI)
	{
		x = 0;
		mlx->c.imag = (scale(y, -2, + 2, 0, HEI) / mlx->zoom) + mlx->shft_y;
		while (x < WID)
		{
			mlx->c.real = (scale(x, -2, + 2, 0, WID) / mlx->zoom) + mlx->shft_x;
			iter = inside_set(mlx);
			if (iter > 1  && iter <= 20)
				mypp(&mlx->img, x, y, rgb(scale(iter, 0, 255, 1, 50), 0, 0));
			else if (iter > 20  && iter <= 50)
				mypp(&mlx->img, x, y, rgb(0, 0, scale(iter, 0, 255, 1, 50)));
			else if (iter > 50  && iter <= MAX_ITER)
				mypp(&mlx->img, x, y, rgb(0, scale(iter, 0, 255, 1, 50), 0));
			else
				mypp(&mlx->img, x, y, rgb(0, 0, 0));
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
