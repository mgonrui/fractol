/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:05:02 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 13:20:23 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*unsigned_char_str;
	unsigned char	unsigned_char_c;
	size_t			i;

	unsigned_char_str = (unsigned char *)str;
	unsigned_char_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (unsigned_char_str[i] == unsigned_char_c)
			return (&unsigned_char_str[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int main(void)
// {
// 	const char *string = "hello world";
// 	const char character = 'o';
// 	void *vp_string = ft_memchr(string, character, 7);	
// 	printf("%s", (char *)vp_string);
// 	return 0;
// }
