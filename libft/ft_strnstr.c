/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:10:29 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 14:53:05 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((little != NULL) && (little[0] == '\0'))
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (little[j] == big[j + i] && (j + i) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
// int main(void)
// {
//     char *str1 = "12345";
//     char *str2 = "123";
//     // printf("%d\n", ft_little_match(str, str));
//     printf("%s\n", ft_strnstr(str1, str2, 1));
//     return 0;
// }