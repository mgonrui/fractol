


#ifndef FRACTOL_H
#define FRACTOL_H

#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <error.h>
#include "mlx_linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define INPUT_ERROR "please enter a correct input:\n \"./fractol mandelbroot\" or\n \"./fractol julia <value_1> <value_2>\"\n"
#define MAX_ITERATIONS 100

typedef	unsigned char	byte;

typedef struct s_img{
	void *ptr;
	char *addr;
	int bits_per_pixel;
	int line_len;
	int endian;
} t_img;

typedef struct s_complex_number {
	float real;
	float imaginary;
} t_complex_number;

typedef struct s_scale {
	float max;
	float min;
} t_scale;


typedef struct s_mlx{
	char *name;
	void *connection;
	void *window;
	t_img img;
	float zoom;
	t_scale x;
	t_scale y;
} t_mlx;


int	inside_set(t_complex_number c);
int close_my_program(t_mlx *mlx);
int key_events(int keysym, t_mlx *mlx);
void listen_input(t_mlx *mlx);
void render_img(t_mlx *mlx);
void move_img_left(t_mlx *mlx);
void move_img_right(t_mlx *mlx);
void move_img_down(t_mlx *mlx);
void move_img_up(t_mlx *mlx);
int mouse_events(int button, int x, int y,t_mlx *mlx);
#endif // FRACT-OL_H
