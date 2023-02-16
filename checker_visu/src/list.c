/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:28:57 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/16 08:50:10 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include"visu.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*last;
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !*lst)
		return ;
	tmp = (*lst);
	last = tmp->prev;
	while (tmp != last)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	free(tmp);
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

t_list	*ft_lstnew(int value)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (newlist)
	{
		newlist->value = value;
		newlist->next = NULL;
		newlist->prev = NULL;
	}
	return (newlist);
}
