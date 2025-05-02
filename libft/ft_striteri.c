/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:08:45 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 12:23:39 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <ctype.h>

// void uppercase(unsigned int index, char *ch)
// {
//     *ch = toupper(*ch);
// }

// int main(void)
// {
// 	char str[] = "hello world";
// 	ft_striteri(str, uppercase);
// 	printf("%s\n", str);
// 	return 0;
// }