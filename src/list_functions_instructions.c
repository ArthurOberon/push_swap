/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:12:24 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/30 10:55:39 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		free(tmp->operation);
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
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

void	ft_add_instruction(char *operation, t_instruction **lst_instruction)
{
	ft_lstnew_instruction(operation);
	ft_lstadd_back_instruction(lst_instruction, operation);
}
