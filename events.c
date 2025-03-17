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
	mlx->x.max += 0.5 / mlx->zoom;
	mlx->x.min += 0.5 / mlx->zoom;
	render_img(mlx);
}

void move_img_left(t_mlx *mlx)
{
	mlx->x.max -= 0.5 / mlx->zoom;
	mlx->x.min -= 0.5 / mlx->zoom;
	render_img(mlx);
}

void move_img_down(t_mlx *mlx)
{
	mlx->y.max += 0.5 / mlx->zoom;
	mlx->y.min += 0.5 / mlx->zoom;
	render_img(mlx);
}

void move_img_up(t_mlx *mlx)
{
	mlx->y.max -= 0.5 / mlx->zoom;
	mlx->y.min -= 0.5 / mlx->zoom;
	render_img(mlx);
}
