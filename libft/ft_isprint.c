/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:56:49 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 14:14:24 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int argument)
{
	if (argument >= 32 && argument < 127)
		return (argument);
	return (0);
}
// #include <stdio.h>

// int main(void)
// {
// 	printf("%d", ft_isprint('4'));
// 	printf("%d", ft_isprint(1));
// 	return 0;
// }