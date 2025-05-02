/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:47:40 by mariogo2          #+#    #+#             */
/*   Updated: 2025/05/02 15:49:07 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

static void	init_mlx(char **argv, t_mlx *mlx)
{
	mlx->connection = mlx_init();
	if (mlx->connection == NULL)
	{
		perror("error trying to establish mlx connection");
		exit(1);
	}
	mlx->name = argv[1];
	mlx->window = mlx_new_window(mlx->connection, WID, HEI, mlx->name);
	mlx->img.ptr = mlx_new_image(mlx->connection, WID, HEI);
	mlx->img.addr = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bits_per_pixel,
			&mlx->img.line_len, &mlx->img.endian);
}

static void	init_fractal(t_mlx *mlx, char **argv)
{
	mlx->zoom = 1;
	mlx->shft_x = 0;
	mlx->shft_y = 0;
	if (!ft_strncmp(mlx->name, "julia", 6))
	{
		mlx->c.real = ft_atof(argv[2]);
		mlx->c.imag = ft_atof(argv[3]);
	}
}

static void	check_args(int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp("mandelbrot", argv[1], 11))
		return ;
	if (argc == 4 && !ft_strncmp("julia", argv[1], 6) && valid_number(argv[2])
		&& valid_number(argv[3]))
		return ;
	else
	{
		ft_putstr_fd(INPUT_ERROR, 2);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	check_args(argc, argv);
	init_mlx(argv, &mlx);
	init_fractal(&mlx, argv);
	render_img(&mlx);
	listen_input(&mlx);
	mlx_loop(mlx.connection);
	return (0);
}
