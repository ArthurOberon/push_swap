/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:34:24 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/16 17:44:44 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmoveout(t_list **lst)
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

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst)
		return ;
	tmp = *lst;
	tmp2 = *lst;
	while (tmp)
	{
		tmp2 = tmp2->next;
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}

void	ft_lstclear_instruction(t_instruction **lst)
{
	t_instruction	*tmp;
	t_instruction	*tmp2;

	if (!lst)
		return ;
	tmp = *lst;
	tmp2 = *lst;
	while (tmp)
	{
		tmp2 = tmp2->next;
		free(tmp);
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

t_instruction	*ft_lstnew_instruction(char *operation)
{
	t_instruction	*newlist;

	newlist = malloc(sizeof(t_instruction));
	if (newlist)
	{
		operation[ft_strlen(operation) - 1] = '\0';
		newlist->operation = operation;
		newlist->next = NULL;
	}
	return (newlist);
}

void	ft_lstadd_back_instruction(t_instruction **lst, t_instruction *new)
{
	t_instruction	*tmp;

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

//	|==========================|
//	|===== USELESS...??? ===== |
//	|==========================|

// static t_instruction	*ft_lstlast(t_instruction *lst)
// {
// 	while (lst && lst->next)
// 	{
// 		lst = lst->next;
// 	}
// 	return (lst);
// }

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	ft_lstadd_back(lst, new);
// 	(*lst) = (*lst)->prev;
// }
