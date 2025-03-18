#include "fractol.h"

int close_my_program(t_mlx *mlx)
{
		mlx_destroy_image(mlx->connection, mlx->img.ptr);
		mlx_destroy_window(mlx->connection, mlx->window);
		mlx_destroy_display(mlx->connection);
		free(mlx->connection);
		exit (1);
}

void move_img_left(t_mlx *mlx)
{
	float shft = 0.5;
	if (mlx->zoom > 1)
		mlx->shft_x -= shft / mlx->zoom;
	else
		mlx->shft_x -= shft;
	render_img(mlx);
}

void move_img_right(t_mlx *mlx)
{
	float shft = 0.5;
	if (mlx->zoom > 1)
		mlx->shft_x += shft / mlx->zoom;
	else
		mlx->shft_x += shft;
	render_img(mlx);
}

void move_img_up(t_mlx *mlx)
{
	float shft = 0.5;
	if (mlx->zoom > 1)
		mlx->shft_y -= shft / mlx->zoom;
	else
		mlx->shft_y -= shft;
	render_img(mlx);
}

void move_img_down(t_mlx *mlx)
{
	float shft = 0.5;
	if (mlx->zoom > 1)
		mlx->shft_y += shft / mlx->zoom;
	else
		mlx->shft_y += shft;
	render_img(mlx);
}
