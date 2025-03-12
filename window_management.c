#include "fractol.h"
#include "mlx_linux/mlx.h"

// TODO La rueda del ratón hace zoom in y zoom out y lo hace casi infinitamente (dentro de los límites del ordenador). Ese es el concepto de un fractal.
// TODO El manejo de tu ventana debe ser fluido (cambio a otra ventana, minimización y demás)
// TODO ESC debe cerrar la ventana y salir del programa de manera limpia.

#define WINDOW_SIZE 400

typedef	unsigned char	byte;

typedef struct s_img_data{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_len;
	int endian;
} t_img_data;

typedef struct s_mlx_data{
	void *connection;
	void *window;
	t_img_data img_data;
} t_mlx_data;


int	encode_rgb(byte red, byte green, byte blue)
{
    return (red << 16 | green << 8 | blue);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len+ x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void fill_screen(t_mlx_data *mlx_data, int color)
{
	int x;
	int y;
	y = 0;
	while (y < WINDOW_SIZE)
	{
		x = 0;
		while (x < WINDOW_SIZE)
		{
			my_mlx_pixel_put(&mlx_data->img_data, x, y, color);
			x++;
		}
		y++;
	}
}

int print_color(int keysym, t_mlx_data *mlx_data)
{
	int color;
	if (keysym == XK_r)
	{
		color = encode_rgb(255, 0, 0);
		fill_screen(mlx_data, color);
	}
	else if (keysym == XK_g)
	{
		color = encode_rgb(0, 255, 0);
		fill_screen(mlx_data, color);
	}
	else if (keysym == XK_b)
	{
		color = encode_rgb(0, 0, 255);
		fill_screen(mlx_data, color);
	}
	mlx_put_image_to_window(mlx_data->connection, mlx_data->window, mlx_data->img_data.img, 0, 0);
	return 0;
}


int	main(void)
{
	t_mlx_data mlx_data;
	mlx_data.connection = mlx_init();
	mlx_data.window = mlx_new_window(mlx_data.connection, WINDOW_SIZE, WINDOW_SIZE, "test window");
	mlx_data.img_data.img = mlx_new_image(mlx_data.connection, WINDOW_SIZE, WINDOW_SIZE);
	mlx_data.img_data.addr = mlx_get_data_addr(mlx_data.img_data.img,
								 &mlx_data.img_data.bits_per_pixel,
								 &mlx_data.img_data.line_len,
								 &mlx_data.img_data.endian);
	mlx_key_hook(mlx_data.window, print_color,  &mlx_data);
	mlx_loop(mlx_data.connection);
}
