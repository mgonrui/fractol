#ifndef FRACTOL_H
#define FRACTOL_H

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <error.h>
#include "mlx_linux/mlx.h"
#include <X11/keysym.h>
#include "libft/libft.h"
#include <stdio.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400
#define INPUT_ERROR "please enter a correct input:\n \"./fractol mandelbroot\" or\n \"./fractol julia <value_1> <value_2>\n\""

typedef	unsigned char	byte;

typedef struct s_img{
	void *ptr;
	char *addr;
	int bits_per_pixel;
	int line_len;
	int endian;
} t_img;

typedef struct s_mlx{
	char *name;
	void *connection;
	void *window;
	t_img img;
} t_mlx;


typedef struct s_complex_number {
	double real;
	double imaginary;
} t_complex_number;

void render_img(t_mlx *mlx);

#endif // FRACT-OL_H
