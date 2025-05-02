/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:18:24 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 12:24:49 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*s_converted;
	int				i;
	unsigned char	unsigned_c;

	unsigned_c = c;
	i = ft_strlen(s);
	s_converted = (char *)s;
	while (i >= 0)
	{
		if (unsigned_c == s_converted[i])
			return (&s_converted[i]);
		i--;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int main (void) {
// //    int len;
//    const char str[] = "";
//    const char ch = '.';
//    char *ret;

// //    ret = strrchr(str, ch);
//    ret = ft_strrchr(str, ch);

//    printf("String after |%c| is - |%s|\n", ch, ret);

//    return(0);
// }