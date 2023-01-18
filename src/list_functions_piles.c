/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_piles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:34:24 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/18 16:40:58 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmoveout(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp->next == tmp)
	{
		*lst = NULL;
		return (tmp);
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	*lst = tmp->next;
	tmp->prev = tmp;
	tmp->next = tmp;
	return (tmp);
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

void	ft_lstclear(t_list **lst)
{
	t_list	*first;
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !*lst)
		return ;
	first = (*lst);
	tmp = first->next;
	tmp2 = first->next;
	while (tmp != first)
	{
		tmp2 = tmp2->next;
		free(tmp);
		tmp = tmp2;
	}
	free(tmp);
	*lst = NULL;
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
