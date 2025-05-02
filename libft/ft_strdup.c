/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:08:20 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 13:37:25 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*p_string;

	p_string = malloc(sizeof(char) * ft_strlen(string) + 1);
	if (p_string == NULL)
		return (0);
	ft_memcpy(p_string, string, ft_strlen(string) + 1);
	return (p_string);
}
// #include <stdio.h>

// int main(void)
// {
// 	const char *string = "hello world";
// 	char *duplicate = ft_strdup(string);
// 	printf("%s\n", duplicate);
// 	return 0;
// }