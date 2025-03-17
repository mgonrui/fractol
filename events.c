#include "fractol.h"

int close_my_program(t_mlx *mlx)
{
		mlx_destroy_image(mlx->connection, mlx->img.ptr);
		mlx_destroy_window(mlx->connection, mlx->window);
		mlx_destroy_display(mlx->connection);
		free(mlx->connection);
		exit (1);
}

void move_img_right(t_mlx *mlx)
{
	float shift = 0.5;

	if (mlx->zoom > 1)
	{
	mlx->x.max += shift / mlx->zoom;
	mlx->x.min += shift / mlx->zoom;
	}
	else
	{
	mlx->x.max += shift;
	mlx->x.min += shift;
	}
	render_img(mlx);
}

void move_img_left(t_mlx *mlx)
{
	float shift = 0.5;
	if (mlx->zoom > 1)
	{
	mlx->x.max -= shift / mlx->zoom;
	mlx->x.min -= shift / mlx->zoom;
	}
	else
	{
	mlx->x.max -= shift;
	mlx->x.min -= shift;
	}
	render_img(mlx);
}

void move_img_down(t_mlx *mlx)
{
	float shift = 0.5;
	if (mlx->zoom > 1)
	{
		mlx->y.max += shift / mlx->zoom;
		mlx->y.min += shift / mlx->zoom;
	}
	else
	{
		mlx->y.max += shift;
		mlx->y.min += shift;
	}
	render_img(mlx);
}

void move_img_up(t_mlx *mlx)
{
	float shift = 0.5;
	if (mlx->zoom > 1)
	{
		mlx->y.max -= shift / mlx->zoom;
		mlx->y.min -= shift / mlx->zoom;

	}
	else
	{
		mlx->y.max -= shift;
		mlx->y.min -= shift;
	}
	render_img(mlx);
}
