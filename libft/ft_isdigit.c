/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:04:35 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 14:13:47 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int argument)
{
	if (argument >= '0' && argument <= '9')
		return (1);
	return (0);
}
// #include <stdio.h>

// int main(void)
// {
// 	printf("%d", ft_isdigit('4'));
// 	printf("%d", ft_isdigit('g'));
// 	return 0;
// }