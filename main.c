#include "fractol.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"
#include <X11/X.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
	mlx->zoom = 1;
	mlx->x.min = -2;
	mlx->x.max= 2;
	mlx->y.min = -2;
	mlx->y.max= 2;
}

static void check_args(int argc, char **argv)
{
	if ((argc == 2 && !ft_strncmp("mandelbrot", argv[1], 11)) ||
		(argc == 4 && !ft_strncmp("julia", argv[1], 6)))
		return;
	else
		ft_putstr(INPUT_ERROR), _exit(1);
}


int main(int argc, char **argv)
{
	t_mlx mlx;
	check_args(argc, argv);
	init_mlx(argv, &mlx);
	render_img(&mlx);
	listen_input(&mlx);
	mlx_loop(mlx.connection);
	return 0;
}
