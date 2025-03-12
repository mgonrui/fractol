#include "fractol.h"
#include "libft/libft.h"
#include <stdio.h>

int	inside_set(t_complex_number c)
{
	float temp;
	t_complex_number z;

	c.imaginary /= 100;
	c.real /= 100;
	z.real = 0;
	z.imaginary = 0;
	int reiterations = 0;
	while (reiterations < 1000)
	{
		temp = (z.real * z.real) - (z.imaginary * z.imaginary);
		z.imaginary = 2 * z.imaginary * z.real;
		z.real = temp;
		z.real += c.real;
		z.imaginary += c.imaginary;
		if (z.imaginary > 2 || z.imaginary < -2 || z.real > 2 || z.real < -2)
			return 0;
		reiterations++;
	}
	return 1;
}
