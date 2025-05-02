/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:46:43 by mariogo2          #+#    #+#             */
/*   Updated: 2025/05/02 15:46:51 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_number	sum_complex_numbers(t_complex_number n1,
		t_complex_number n2)
{
	t_complex_number	sum;

	sum.real = n1.real + n2.real;
	sum.imag = n1.imag + n2.imag;
	return (sum);
}

t_complex_number	sqr_complex_number(t_complex_number n)
{
	t_complex_number	sqr;

	sqr.real = (n.real * n.real) - (n.imag * n.imag);
	sqr.imag = 2 * n.real * n.imag;
	return (sqr);
}

int	check_point_inside_set(t_complex_number z, t_complex_number c)
{
	int	iterations;

	iterations = 0;
	while (iterations <= MAX_ITER)
	{
		z = sum_complex_numbers(sqr_complex_number(z), c);
		if (((z.imag * z.imag) + (z.real * z.real)) > 4)
			return (iterations);
		iterations++;
	}
	return (iterations);
}
