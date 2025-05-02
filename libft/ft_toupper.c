/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:36:36 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 12:25:41 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch + ('A' - 'a'));
	return (ch);
}

// #include <stdio.h>
// int main() {
//     char c;
//     c = 'm';
//     printf("%c -> %c", c, ft_toupper(c));
//     c = 'D';
//     printf("\n%c -> %c", c, ft_toupper(c));
//     c = '9';
//     printf("\n%c -> %c", c, ft_toupper(c));
//     return 0;
// }
