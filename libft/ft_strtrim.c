/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:32:11 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 14:52:07 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_match(char const *set, char c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (1);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		start_i;
	int		end_i;

	i = 0;
	start_i = 0;
	end_i = ft_strlen(s1) - 1;
	if (!(s1))
		return (NULL);
	while (s1[start_i] && ft_is_match(set, s1[start_i]))
		start_i++;
	while (s1[end_i] && ft_is_match(set, s1[end_i]))
		end_i--;
	if (start_i == ft_strlen(s1))
		return (result = ft_strdup(""));
	result = malloc(sizeof(char) * (end_i - start_i) + 2);
	if (result == NULL)
		return (NULL);
	while (start_i <= end_i)
		result[i++] = s1[start_i++];
	result[i] = '\0';
	return (result);
}
// int	main(void)
// {
// 	char *s3 = "  \t \t \n   \n\n\n\t";
//     // char *s4 = "";
//     printf("%s\n", ft_strtrim(s3, " \n\t"));
// 	// char s1[] = "honlapipo";
// 	// char s2[] = "hola"; 
//  	// printf("%s", ft_strtrim(s1, s2));
// 	return (0);
// } 