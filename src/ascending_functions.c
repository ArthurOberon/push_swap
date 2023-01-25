/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascending_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:23:06 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/25 17:27:31 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_to_ascending(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, int order)
{
	t_list	*tmp;
	int		lst_length;
	int		value_min;

	tmp = *lst_a;
	lst_length = ft_lstsize(lst_a);
	value_min = ft_found_value_min(lst_a, lst_length);
	printf("ORDER = [%d]\n", order);
	if (order == ASCENDING)
	{
		while (tmp->value != value_min)
		{
			ft_do_operation("ra", lst_a, lst_b);
			ft_print_piles("ra", lst_a, lst_b);
			tmp = *lst_a;
		}
	}
	else if (order == DESCENDING)
	{
		while (tmp->value != value_min)
		{
			ft_do_operation("ra", lst_a, lst_b);
			ft_print_piles("ra", lst_a, lst_b);
			tmp = *lst_a;
		}
		printf("Do function to invert the all stack\n");
	}
}


void	ft_get_ascending_stack_a(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	t_list	*tmp;
	int		i;
	int		lst_length;
	int		max_value;
	int		min_value;

	i = 0;
	lst_length = ft_lstsize(lst_a);
	max_value = ft_found_value_max(lst_a, lst_length);
	min_value = ft_found_value_min(lst_a, lst_length);
	tmp = *lst_a;
	while (i <= lst_length)
	{
		if (tmp->value == min_value)
		{
			ft_do_operation("pb", lst_a, lst_b);
			ft_print_piles("pb", lst_a, lst_b);
		}
		else if (tmp->prev->value == max_value)
		{
			if (tmp->value > tmp->next->value)
			{
				ft_do_operation("pb", lst_a, lst_b);
				ft_print_piles("pb", lst_a, lst_b);
				lst_length--;
			}
			else
			{
				ft_do_operation("ra", lst_a, lst_b);
				ft_print_piles("ra", lst_a, lst_b);
			}
		}
		else if (tmp->value == max_value)
		{
			ft_do_operation("ra", lst_a, lst_b);
			ft_print_piles("ra", lst_a, lst_b);
		}
		else if (tmp->next->value == max_value)
		{
			if (tmp->prev->value > tmp->value)
			{
				ft_do_operation("pb", lst_a, lst_b);
				ft_print_piles("pb", lst_a, lst_b);
				lst_length--;
			}
			else
			{
				ft_do_operation("ra", lst_a, lst_b);
				ft_print_piles("ra", lst_a, lst_b);
			}
		}
		else if (tmp->prev->value > tmp->value || tmp->value > tmp->next->value)
		{
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
