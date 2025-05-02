/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:04:06 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 12:21:20 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int argument)
{
	if ((argument >= 'a' && argument <= 'z') || (argument >= 'A'
			&& argument <= 'Z'))
		return (1);
	return (0);
}
// #include <stdio.h>
// int main()
// {
//     char c;
//     c = 'Q';
//     printf("\nResult when uppercase alphabet is passed: %d", ft_isalpha(c));
//     c = 'q';
//     printf("\nResult when lowercase alphabet is passed: %d", ft_isalpha(c));
//     c='+';
//     printf("\nResult when non-alpha character is passed: %d", ft_isalpha(c));
//     return 0;
// }