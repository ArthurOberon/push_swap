/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:34:24 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/11 18:40:56 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_lstdelone(t_list **lst)
{
	t_list	*tmp_next;
	t_list	*tmp_prev;

	tmp_next = (*lst)->next;
	tmp_prev = (*lst)->prev;
	tmp_prev = tmp_next->prev;
	tmp_next = tmp_prev->next;
	(*lst) = tmp_next;
	return (*lst);
}

t_list	*ft_lstnew(int content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (newlist)
	{
		newlist->value = content;
		newlist->next = NULL;
		newlist->prev = NULL;
	}
	return (newlist);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !del)
		return ;
	tmp = *lst;
	tmp2 = *lst;
	while (tmp)
	{
		tmp2 = tmp2->next;
		// ft_lstdelone(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	tmp = (*lst)->prev;
	(*lst)->prev = new;
	new->next = (*lst);
	new->prev = tmp;
	tmp->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	ft_lstadd_back(lst, new);
	(*lst) = (*lst)->prev;
}
