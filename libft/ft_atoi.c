/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:02:24 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/13 13:30:39 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static int	ft_sign_type(char c)
{
	if (c == '+')
		return (1);
	else
		return (-1);
}

static int	ft_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	number = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_is_sign(str[i]))
		sign = ft_sign_type(str[i++]);
	while (ft_isdigit(str[i]))
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * sign);
}
// #include <stdio.h>

// int main(void)
// {
// 	printf("%d\n", ft_atoi("-234"));
// 	return 0;
// }
