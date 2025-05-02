/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:06:42 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 12:22:36 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*p_dst;
	char	*p_src;

	p_dst = (char *)dst;
	p_src = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len--)
			p_dst[len] = p_src[len];
	}
	else
	{
		ft_memcpy(p_dst, p_src, len);
	}
	return (dst);
}
// #include <string.h>
// #include <stdio.h>
// int main() {
//     char str[50] = "123456";

//     // Copy the string to the middle of itself
// 	// memmove(str, str + 1, 9);
//     // memcpy(str + 7, str, 13);
//     ft_memmove(str, str,4);
//     // memmove(str, str,4);

//     printf("Modified string: %s\n", str);

//     return 0;
// }