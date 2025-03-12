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

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
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
	float real;
	float imaginary;
} t_complex_number;

void render_img(t_mlx *mlx);
int	inside_set(t_complex_number c);
#endif // FRACT-OL_H
