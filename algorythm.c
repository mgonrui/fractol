#include "fractol.h"

int	inside_set(t_complex_number c)
{
	float temp;
	t_complex_number z;

	z.real = 0;
	z.imaginary = 0;
	int iterations = 0;
	while (iterations <= MAX_ITERATIONS)
	{
		temp = (z.real * z.real) - (z.imaginary * z.imaginary);
		z.imaginary = 2 * z.imaginary * z.real;
		z.real = temp;
		z.real += c.real;
		z.imaginary += c.imaginary;
		if (((z.imaginary *  z.imaginary) + (z.real * z.real)) > 4)
			return iterations ;
		iterations++;
	}
	return iterations;
}
