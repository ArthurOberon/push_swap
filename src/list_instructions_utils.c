/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:17:10 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/08 18:13:14 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear_instruction(t_instruction **lst)
{
	t_instruction	*tmp;
	t_instruction	*tmp_next;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	tmp_next = *lst;
	while (tmp)
	{
		tmp_next = tmp_next->next;
		free(tmp->operation);
		free(tmp);
		tmp = tmp_next;
	}
	*lst = NULL;
}

char	*ft_invert_operation(char *operation)
{
	if (*operation == 'p')
	{
		operation++;
		if (*operation == 'a')
			return ("pb");
		return ("pa");
	}
	else if (*operation == 's')
		return (operation);
	else if (*operation == 'r')
	{
		operation++;
		if (*operation == 'r')
		{
			operation++;
			if (*operation == 'a')
				return ("ra");
			return ("rb");
		}
		else if (*operation == 'a')
			return ("rra");
		return ("rrb");
	}
	return (NULL);
}

t_instruction	*ft_lstnew_instruction(char *operation)
{
	t_instruction	*newlist;

	newlist = malloc(sizeof(t_instruction));
	if (newlist)
	{
		if (operation[ft_strlen(operation) - 1] == '\n')
			operation[ft_strlen(operation) - 1] = '\0';
		newlist->operation = ft_strdup(operation);
		if (!newlist->operation)
			return (NULL);
		newlist->invert_operation = ft_invert_operation(operation);
		newlist->next = NULL;
		newlist->prev = NULL;
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
	new->prev = tmp;
}

int	ft_add_instruction(char *operation, t_instruction **lst_instruction)
{
	t_instruction	*new;

	new = ft_lstnew_instruction(operation);
	if (!new)
		return (-1);
	ft_lstadd_back_instruction(lst_instruction, new);
	return (0);
}
