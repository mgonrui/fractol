#include "fractol.h"

int	inside_set(t_mlx *mlx)
{
	float temp;

	mlx->z.real = 0;
	mlx->z.imaginary = 0;
	int iterations = 0;
	while (iterations <= MAX_ITERATIONS)
	{
		temp = (mlx->z.real * mlx->z.real) - (mlx->z.imaginary * mlx->z.imaginary);
		mlx->z.imaginary = 2 * mlx->z.imaginary * mlx->z.real;
		mlx->z.real = temp;
		mlx->z.real += mlx->c.real;
		mlx->z.imaginary += mlx->c.imaginary;
		if (((mlx->z.imaginary *  mlx->z.imaginary) + (mlx->z.real * mlx->z.real)) > 4)
			return iterations ;
		iterations++;
	}
	return iterations;
}
