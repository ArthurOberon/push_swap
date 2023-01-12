/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:37:31 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/12 12:04:46 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static size_t	ft_word_length(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_word_count(char *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = ft_word_length(s, c);
		s += i;
		if (i)
			count++;
	}
	return (count);
}

static char	*ft_strcpy(char *src, int n)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (0);
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**ft_rewind_free(char	**result, size_t y)
{
	while (y <= 0)
	{
		free(result[y]);
		y--;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	y;
	size_t	count;
	char	**result;

	i = 0;
	count = ft_word_count((char *)s, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (0);
	while (i < count)
	{
		while (*s == c)
			s++;
		y = ft_word_length((char *)s, c);
		result[i] = ft_strcpy((char *)s, y);
		if (!y)
			return (ft_rewind_free(result, y));
		s += y;
		i++;
	}
	result[count] = 0;
	return (result);
}
