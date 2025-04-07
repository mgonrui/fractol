#include "fractol.h"

int	inside_set(t_mlx *mlx)
{
	float temp;

	int iterations = 0;
	while (iterations <= MAX_ITER)
	{
		temp = (mlx->z.real * mlx->z.real) - (mlx->z.imag * mlx->z.imag);
		mlx->z.imag = 2 * mlx->z.imag * mlx->z.real;
		mlx->z.real = temp;
		mlx->z.real += mlx->c.real;
		mlx->z.imag += mlx->c.imag;
		if (((mlx->z.imag *  mlx->z.imag) + (mlx->z.real * mlx->z.real)) > 4)
			return iterations ;
		iterations++;
	}
	return iterations;
}
