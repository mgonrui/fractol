/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:42:21 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 12:23:23 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*p_str;
	char	c_is_char;

	p_str = (char *)str;
	c_is_char = (char)c;
	while (*p_str)
	{
		if (c_is_char == *p_str)
		{
			return (p_str);
		}
		p_str++;
	}
	if (c == 0 || c == 1024)
		return (p_str);
	else
		return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "teste";
// 	int		c = 'e';

// 	printf("%s\n", ft_strchr(str, c));
// 	printf("%s\n", ft_strchr(str, '\0'));
// }