/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:51:25 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/16 15:29:47 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	ft_lstadd_back_gnl(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	ft_is_backslash_n(t_list *lst_tmp, ssize_t read_size)
{
	int		i;

	i = 0;
	while (i < read_size)
	{
		if (lst_tmp->content[i] == '\n')
		{
			lst_tmp->n_pos = i;
			lst_tmp->size_of_element = i + 1;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	ft_strncat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dst[j] != '\0')
		j++;
	while (i < size)
		dst[j++] = src[i++];
	dst[j] = '\0';
}

void	ft_substr(t_list *lst)
{
	size_t		i;
	size_t		size;
	size_t		start;

	i = 0;
	start = lst->size_of_element;
	size = lst->buffer_size - lst->size_of_element;
	while (i < size)
		lst->content[i++] = lst->content[start++];
	lst->content[i] = '\0';
	lst->buffer_size = size;
	lst->size_of_element = size;
}
