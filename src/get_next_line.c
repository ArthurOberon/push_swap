/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:50:55 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/16 15:29:40 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_lst_from_read(t_list **buf, ssize_t *read_size, int fd)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (0);
	*read_size = read(fd, tmp->content, BUFFER_SIZE);
	if (*read_size <= 0)
		return (free(tmp), 1);
	tmp->buffer_size = *read_size;
	tmp->size_of_element = *read_size;
	tmp->content[*read_size] = '\0';
	tmp->n_pos = -1;
	tmp->next = NULL;
	*buf = tmp;
	return (1);
}

size_t	ft_size_of_line(t_list *lst)
{
	size_t	line_size;

	line_size = 0;
	while (lst)
	{
		line_size += lst->size_of_element;
		lst = lst->next;
	}
	return (line_size);
}

char	*ft_lst_concatenation(t_list **lst)
{
	char	*result;
	t_list	*lst_tmp;
	size_t	line_size;

	line_size = ft_size_of_line(*lst);
	result = malloc(sizeof(char) * (line_size + 1));
	if (!result)
		return (NULL);
	result[0] = '\0';
	result[line_size] = '\0';
	while ((*lst))
	{
		ft_strncat(result, (*lst)->content, (*lst)->size_of_element);
		if ((*lst)->n_pos != -1)
		{
			ft_substr((*lst));
			if ((*lst)->content[0] != '\0')
				return (result);
		}
		lst_tmp = (*lst);
		(*lst) = (*lst)->next;
		free(lst_tmp);
	}
	return (result);
}

char	*ft_get_line(t_list **lst, int fd)
{
	t_list	*buf;
	ssize_t	read_size;

	if ((*lst) && (*lst)->content[0] != '\0'
		&& ft_is_backslash_n((*lst), (*lst)->size_of_element) != -1)
		return (ft_lst_concatenation(lst));
	if (ft_lst_from_read(&buf, &read_size, fd) == 0)
		return (NULL);
	while (read_size > 0)
	{
		ft_lstadd_back_gnl(lst, buf);
		if (ft_is_backslash_n(buf, read_size) != -1)
			return (ft_lst_concatenation(lst));
		if (ft_lst_from_read(&buf, &read_size, fd) == 0)
			return (NULL);
	}
	if ((*lst) && (*lst)->content[0] != '\0')
		return (ft_lst_concatenation(lst));
	return (free(*lst), NULL);
}

char	*get_next_line(int fd)
{
	static t_list		*lst = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (ft_get_line(&lst, fd));
}
