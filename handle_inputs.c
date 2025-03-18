#include "fractol.h"
#include <stdio.h>

void listen_input(t_mlx *mlx)
{
	mlx_key_hook(mlx->window, key_events, mlx);
	mlx_hook(mlx->window, ButtonPress, ButtonPressMask, mouse_events, mlx);
	mlx_hook(mlx->window, DestroyNotify, StructureNotifyMask, close_my_program, mlx);
}

int key_events(int keysym, t_mlx *mlx)
{

	if (keysym == XK_Escape)
		close_my_program(mlx);
	else if (keysym == XK_Left)
		move_img_left(mlx);
	else if (keysym == XK_Right)
		move_img_right(mlx);
	else if (keysym == XK_Up)
		move_img_up(mlx);
	else if (keysym == XK_Down)
		move_img_down(mlx);
	return 0;
}


int mouse_events(int button, int x, int y, t_mlx *mlx)
{
	x = x + y;
	// scroll up
	if (button == Button4)
		mlx->zoom *= 1.05;
	// scroll down
	else if (button == Button5)
		mlx->zoom *= 0.95;
	render_img(mlx);
	return 0;

}
