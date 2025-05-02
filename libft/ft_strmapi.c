/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:10:18 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 12:24:21 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
// #include <ctype.h>
// char uppercase(unsigned int i, char c)
// {
//     if (i % 2 == 0)
//         return toupper(c);
//     else
//         return tolower(c);
// }

// int main(void)
// {
// 	char *res = ft_strmapi("Hello, World!", uppercase);
// 	printf("%s\n", res);
// 	return 0;
// }