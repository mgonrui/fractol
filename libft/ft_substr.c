/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:18:20 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 14:10:53 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	size_to_malloc;

	i = 0;
	if (start >= (size_t)ft_strlen(s))
		return (ft_strdup(""));
	if (start + len < (size_t)ft_strlen(s))
	{
		size_to_malloc = len;
	}
	else
	{
		size_to_malloc = ft_strlen(&s[start]);
	}
	substr = malloc(sizeof(char) * size_to_malloc + 1);
	if (substr == NULL)
		return (NULL);
	while (i < size_to_malloc)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
// #include <stdio.h>

// int main(void)
// {
// 	const char *string = "123456789";
// 	printf("%s\n", ft_substr(string,9, 5));
// 	return 0;
// }