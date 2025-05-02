/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:04:50 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 14:46:59 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_count_digits(long int n)
{
	long int	ndigits;

	ndigits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		ndigits++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		ndigits++;
	}
	return (ndigits);
}

char	*ft_itoa(int n)
{
	char		*char_arr;
	int			i;
	long int	lng_n;

	lng_n = n;
	i = ft_count_digits(lng_n);
	char_arr = (char *)malloc(sizeof(char) * ft_count_digits(lng_n) + 1);
	if (!char_arr)
		return (NULL);
	char_arr[i--] = '\0';
	if (lng_n == 0)
		char_arr[i--] = '0';
	if (lng_n < 0)
	{
		char_arr[0] = '-';
		lng_n = -lng_n;
	}
	while (lng_n > 0)
	{
		char_arr[i--] = (lng_n % 10) + '0';
		lng_n = lng_n / 10;
	}
	return (char_arr);
}

// #include <stdio.h>
// int main(void)
// {
//     printf("%s\n", ft_itoa(0));
//     // printf("%ld\n", ft_count_digits(0));

// }