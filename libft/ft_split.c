/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:01:59 by mariogo2          #+#    #+#             */
/*   Updated: 2024/09/12 14:50:06 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_count_words(char const *s, char delim)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == delim && s[i] != '\0')
			i++;
		while (s[i] != delim && s[i] != '\0')
			i++;
		count++;
	}
	if (s[i - 1] == delim && delim != '\0')
		count--;
	return (count);
}

static void	ft_free(char **p_to_strs)
{
	int	i;

	i = 0;
	while (p_to_strs[i] != NULL)
	{
		free(p_to_strs[i++]);
	}
	free(p_to_strs);
}

static void	ft_add(int *substr_size, int *i)
{
	(*substr_size)++;
	(*i)++;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**p_to_strs;
	int		count;
	int		substr_size;

	count = 0;
	i = 0;
	p_to_strs = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!p_to_strs)
		return (NULL);
	while (count < ft_count_words(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		substr_size = 0;
		while (s[i] != c && s[i] != '\0')
			ft_add(&substr_size, &i);
		p_to_strs[count] = ft_substr(s, i - substr_size, substr_size);
		if (!p_to_strs[count])
			return (ft_free(p_to_strs), NULL);
		count++;
	}
	p_to_strs[ft_count_words(s, c)] = NULL;
	return (p_to_strs);
}
// int main(void)
//  {
//  	// char *s = "split  ||this|for|me|||||!|";
//  	char *s = "gggggggggggggggggg";
//  	char c = 'g';
//      int i = 0;
//      char **result = ft_split(s, c);	
//  	printf("%d\n", ft_count_words(s, c));
//  	while (result[i])
//  	{
//  		printf("result[%d] = (%s)\n", i, result[i]);
// 		i++;
//  	}
//  	printf("result[%d] = (%s)\n", i, result[6]);
//  	return 0;
//  }