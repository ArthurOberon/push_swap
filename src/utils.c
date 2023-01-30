/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:37:41 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/19 14:05:57 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

static char	*ft_malloc_zero(size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * size);
	if (!ptr)
		return (0);
	while (ptr && i < size)
		ptr[i++] = 0;
	return (ptr);
}

static char	*ft_strcat(char *dst, char *src)
{
	size_t	i;
	size_t	dst_length;

	i = 0;
	dst_length = ft_strlen(dst);
	while (src[i])
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (dst);
}

char	*ft_str_merge(char **str, int space, int size)
{
	char	*result;
	size_t	length;
	int		i;
	int		j;

	i = 0;
	length = 0;
	while (i < size)
		length += ft_strlen(str[i++]) + space;
	length -= space;
	result = ft_malloc_zero(length + 1);
	i = 0;
	j = 0;
	while (i < size)
	{
		ft_strcat(result, str[i++]);
		while (result[j])
			j++;
		if (i < size && space)
			result[j] = ' ';
		else
			result[j] = '\0';
	}
	return (result);
}
