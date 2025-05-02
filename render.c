/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:47:59 by mariogo2          #+#    #+#             */
/*   Updated: 2025/05/02 15:58:08 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}

static void	mypp(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static float	scale(float unscaled_num, float new_min, float new_max,
		float old_max)
{
	float	old_min;

	old_min = 0;
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min)
		+ new_min);
}

static void	fill_img(int y, int x, t_mlx *mlx)
{
	int	iter;

	mlx->z.real = (scale(x, -2, +2, WID) / mlx->zoom) + mlx->shft_x;
	mlx->z.imag = (scale(y, -2, +2, HEI) / mlx->zoom) + mlx->shft_y;
	if (!ft_strncmp(mlx->name, "mandelbrot", 11))
	{
		mlx->c.real = mlx->z.real;
		mlx->c.imag = mlx->z.imag;
	}
	iter = check_point_inside_set(mlx->z, mlx->c);
	if (iter > 1 && iter <= 20)
		mypp(&mlx->img, x, y, rgb(scale(iter, 0, 255, 50), 0, 0));
	else if (iter > 20 && iter <= 50)
		mypp(&mlx->img, x, y, rgb(0, 0, scale(iter, 0, 255, 50)));
	else if (iter > 50 && iter <= MAX_ITER)
		mypp(&mlx->img, x, y, rgb(0, scale(iter, 0, 255, 50), 0));
	else
		mypp(&mlx->img, x, y, rgb(0, 0, 0));
}

void	render_img(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEI)
	{
		x = 0;
		while (x < WID)
		{
			fill_img(y, x, mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->img.ptr, 0, 0);
	return ;
}
