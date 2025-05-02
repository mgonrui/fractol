/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:03:10 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 12:56:57 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*p_calloc;

	p_calloc = malloc(num * size);
	if (!(p_calloc))
		return (NULL);
	ft_bzero(p_calloc, num * size);
	return ((void *)p_calloc);
}

// #include <stdio.h>
// #include <complex.h>
// void count_nulls(int i, int num, char *prueba)
// {
// 	int null_count = 0;
// 	while (i < sizeof(char) * num)
// 	{
// 		if (prueba[i] == '\0')
// 			null_count++;
// 		i++;
// 	}
// 	printf("null count: %d\n", null_count);
// }
// int main(void)
// {
// 	int num = 3;
// 	int i = 0;
// 	char *prueba = "hello world";
// 	count_nulls(i, num, prueba);
// 	prueba = ft_calloc(num, sizeof(char));
// 	count_nulls(i, num, prueba);
// 	return 0;
// }