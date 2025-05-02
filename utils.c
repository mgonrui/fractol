/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:48:04 by mariogo2          #+#    #+#             */
/*   Updated: 2025/05/02 15:48:06 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

bool	valid_number2(char *str)
{
	int		i;
	bool	dot;

	dot = false;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			if (i == 0)
				return (false);
			if (dot == false)
			{
				dot = true;
				i++;
			}
			else
				return (false);
		}
		if (!ft_isdigit(str[i++]))
			return (false);
	}
	return (true);
}

bool	valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == '\0')
			return (false);
		else
			i++;
	}
	if (valid_number2(&str[i]) == true)
		return (true);
	else
		return (false);
}

char	*jump_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (&str[i]);
}

char	*set_sign(char *str, int *sign)
{
	int	i;

	*sign = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		*sign = -1;
	}
	return (&str[i]);
}

float	ft_atof(char *str)
{
	int		sign;
	float	number;
	int		i;
	float	float_mult;

	float_mult = 1;
	i = 0;
	number = 0;
	str = jump_spaces(str);
	str = set_sign(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i++] - '0';
	}
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		float_mult /= 10;
		number += (str[i++] - '0') * float_mult;
	}
	return (number * sign);
}
