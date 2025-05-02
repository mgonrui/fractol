/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:04:15 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 12:21:47 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int argument)
{
	if (argument >= 0 && argument <= 127)
		return (1);
	return (0);
}
// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
//     char c;
//     int result;

//     c = '5';
//     result = isalnum(c);
//     printf("When %c is passed, return value is %d\n", c, result);

//     c = 'Q';
//     result = isalnum(c);
//     printf("When %c is passed, return value is %d\n", c, result);

//     c = 'l';
//     result = isalnum(c);
//     printf("When %c is passed, return value is %d\n", c, result);

//     c = '+';
//     result = isalnum(c);
//     printf("When %c is passed, return value is %d\n", c, result);

//     return 0;
// }