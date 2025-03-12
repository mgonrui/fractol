#include "fractol.h"
#include "mlx_linux/mlx.h"
#include <stdio.h>

static void init_mlx(char **argv, t_mlx *mlx)
{
	mlx->connection = mlx_init();
	if (mlx->connection == NULL)
		perror("error trying to establish mlx connection"), exit(1);
	mlx->name = argv[1];
	mlx->window = mlx_new_window(mlx->connection,
								WINDOW_WIDTH,
								WINDOW_HEIGHT,
								mlx->name);
	mlx->img.ptr= mlx_new_image(mlx->connection,
							   WINDOW_WIDTH,
							   WINDOW_HEIGHT);
	mlx->img.addr= mlx_get_data_addr(mlx->img.ptr,
										 &mlx->img.bits_per_pixel,
										 &mlx->img.line_len,
										 &mlx->img.endian);
}

static void check_args(int argc, char **argv)
{
	if ((argc == 2 && !ft_strncmp("mandelbrot", argv[1], 11)) ||
		(argc == 4 && !ft_strncmp("julia", argv[1], 6)))
		return;
	else
		perror(INPUT_ERROR), exit(1);
}



int main(int argc, char **argv)
{
	t_mlx mlx;
	check_args(argc, argv);
	init_mlx(argv, &mlx);
	render_img(&mlx);
	mlx_loop(mlx.connection);
	return 0;
}
