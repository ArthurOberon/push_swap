/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorting_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:08:14 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/24 14:16:38 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_ascending(t_list **lst)
{
	t_list	*first;
	t_list	*tmp;

	first = *lst;
	tmp = first->next;
	if (first->value > tmp->value)
		return (0);
	while (tmp->next != first)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	ft_is_descending(t_list **lst)
{
	t_list	*first;
	t_list	*tmp;

	first = *lst;
	tmp = first->next;
	if (first->value < tmp->value)
		return (0);
	while (tmp->next != first)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_keep_ascending_stack_a(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	t_list	*tmp;
	int		i;
	int		lst_length;

	i = 1;
	lst_length = ft_lstsize(lst_a);
	tmp = *lst_a;
	while (i <= lst_length)
	{
		printf("[%d] => [%d]\n", i, lst_length);
		printf("??? [%d] > [%d] ???\n", tmp->value, tmp->next->value);
		if (tmp->value > tmp->next->value)
		{
			printf("	[%d] > [%d]\n", tmp->value, tmp->next->value);
			ft_do_operation("pb", lst_a, lst_b);
			ft_print_piles("pb", lst_a, lst_b);
			lst_length--;
		}
		else
		{
			ft_do_operation("ra", lst_a, lst_b);
			ft_print_piles("ra", lst_a, lst_b);
		}
		tmp = *lst_a;
		i++;
	}
}

// static void	ft_keep_ascending_stack_b(t_list **lst_a, t_list **lst_b,
// 	t_instruction **lst_instruction)
// {
// }

void	ft_keep_ascending_number(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, char lst_keeping)
{
	// printf("A or B ?\n");
	// if (lst_keeping == 'A')
	// {
	// 	printf("A !\n");
	// 	ft_keep_ascending_stack_a(lst_a, lst_b, lst_instruction);
	// }
	// else if (lst_keeping == 'B')
	// {
	// 	printf("B !\n");
	// 	ft_keep_ascending_stack_b(lst_a, lst_b, lst_instruction);
	// }
}
