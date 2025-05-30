/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:47:24 by mariogo2          #+#    #+#             */
/*   Updated: 2025/05/02 15:47:26 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <error.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WID 1000
# define HEI 1000
# define INPUT_ERROR "please enter a correct input:\n \"./fractol mandelbroot\" or\n \"./fractol julia <value_1> <value_2>\"\n"

# ifndef MAX_ITER
#  define MAX_ITER 100
# endif // MAX_ITER

typedef unsigned char	byte;

/* # define malloc(x) 0 */

typedef struct s_complex_number
{
	float				real;
	float				imag;
}						t_complex_number;

typedef struct s_img
{
	void				*ptr;
	char				*addr;
	int					bits_per_pixel;
	int					line_len;
	int					endian;
}						t_img;

typedef struct s_mlx
{
	// MLX
	char				*name;
	void				*connection;
	void				*window;
	t_img				img;
	// FRACTAL
	float				zoom;
	float				shft_x;
	float				shft_y;
	t_complex_number	c;
	t_complex_number	z;

}						t_mlx;

int						check_point_inside_set(t_complex_number z,
							t_complex_number c);
float					ft_atof(char *str);
int						close_my_program(t_mlx *mlx);
int						key_events(int keysym, t_mlx *mlx);
void					listen_input(t_mlx *mlx);
void					render_img(t_mlx *mlx);
void					move_img_left(t_mlx *mlx);
void					move_img_right(t_mlx *mlx);
void					move_img_down(t_mlx *mlx);
void					move_img_up(t_mlx *mlx);
int						mouse_events(int button, int x, int y, t_mlx *mlx);
bool					valid_number(char *str);
#endif // FRACTOL_H
