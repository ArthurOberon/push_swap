/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:02:50 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/31 11:03:35 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
