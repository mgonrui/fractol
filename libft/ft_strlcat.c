/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:09:15 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 13:44:53 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dest_len;
	size_t	j;
	size_t	return_value;

	dest_len = ft_strlen(dest);
	return_value = ft_strlen(src);
	if (size <= dest_len)
		return_value += size;
	else
		return_value += dest_len;
	j = 0;
	while (src[j] != '\0' && dest_len + 1 < size)
	{
		dest[dest_len] = src[j];
		dest_len++;
		j++;
	}
	dest[dest_len] = '\0';
	return (return_value);
}
// #include <stdio.h>

// int main(void)
// {
// 	char dest[20] = "1234";
// 	char *src = "567890";
// 	size_t size = 7;
// 	printf("return value: %lu\n", ft_strlcat(dest, src, size));
// 	printf("dest content: %s\n", dest);
// 	return 0;
// }