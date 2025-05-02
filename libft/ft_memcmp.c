/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:05:54 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 13:27:26 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*unsigned_char_str1;
	unsigned char	*unsigned_char_str2;

	unsigned_char_str1 = (unsigned char *)str1;
	unsigned_char_str2 = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (unsigned_char_str1[i] != unsigned_char_str2[i])
		{
			return (unsigned_char_str1[i] - unsigned_char_str2[i]);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	const char *string1 = "123456";	
// 	const char *string2 = "12345";
// 	const int n = 6;
// 	printf("%d\n", ft_memcmp((const void *)string1, (const void *)string2, n));
// 	return 0;
// }