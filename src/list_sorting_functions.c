/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorting_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:08:14 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/24 20:26:58 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// USELESS ??

// static int	ft_is_ascending(t_list **lst)
// {
// 	t_list	*first;
// 	t_list	*tmp;

// 	first = *lst;
// 	tmp = first->next;
// 	if (first->value > tmp->value)
// 		return (0);
// 	while (tmp->next != first)
// 	{
// 		if (tmp->value > tmp->next->value)
// 			return (0);
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }

// static int	ft_is_descending(t_list **lst)
// {
// 	t_list	*first;
// 	t_list	*tmp;

// 	first = *lst;
// 	tmp = first->next;
// 	if (first->value < tmp->value)
// 		return (0);
// 	while (tmp->next != first)
// 	{
// 		if (tmp->value < tmp->next->value)
// 			return (0);
// 		tmp = tmp->next;
// 	}
// 	return (1);
// }

// static void	ft_get_ascending_stack_a(t_list **lst_a, t_list **lst_b,
// 	t_instruction **lst_instruction)
// {
// 	t_list	*tmp;
// 	int		i;
// 	int		lst_length;
// 	int		value_min;
// 	int		value_max;

// 	i = 1;
// 	lst_length = ft_lstsize(lst_a);
// 	value_min = ft_found_value_min(lst_a, lst_length);
// 	value_max = ft_found_value_max(lst_a, lst_length);
// 	tmp = *lst_a;
// 	while (i <= lst_length)
// 	{
// 		printf("[%d] => [%d]\n", i, lst_length);
// 		printf("??? [%d] > [%d] ???\n", tmp->value, tmp->next->value);
// 		if (tmp->value == value_max && tmp->next->value != value_min)
// 		{
// 			ft_do_operation("ra", lst_a, lst_b);
// 			ft_print_piles("ra", lst_a, lst_b);
// 		}
// 		else if (tmp->value > tmp->next->value && tmp->value != value_max)
// 		{
// 			printf("	[%d] > [%d]\n", tmp->value, tmp->next->value);
// 			ft_do_operation("pb", lst_a, lst_b);
// 			ft_print_piles("pb", lst_a, lst_b);
// 			lst_length--;
// 		}
// 		else
// 		{
// 			ft_do_operation("ra", lst_a, lst_b);
// 			ft_print_piles("ra", lst_a, lst_b);
// 		}
// 		tmp = *lst_a;
// 		i++;
// 	}
// }

static void	ft_get_ascending_stack_a(t_list **lst_a, t_list **lst_b,
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
	printf("LENGTH = [%d]\nmax = [%d]\nmin = [%d]\n", lst_length, max_value, min_value);
	while (i <= lst_length)
	{
		printf("? [%d] > [%d] ?\n", tmp->prev->value, tmp->value);
		printf("[%d] <-- [%d] --> [%d]\n", tmp->prev->value, tmp->value, tmp->next->value);
		if (tmp->value == min_value)
		{
			ft_do_operation("ra", lst_a, lst_b);
			ft_print_piles("ra", lst_a, lst_b);
			// i--;
		}
		else if (tmp->value == max_value)
		{
			ft_do_operation("pb", lst_a, lst_b);
			ft_print_piles("pb", lst_a, lst_b);
		}
		else if (tmp->prev->value > tmp->value)
		{
			ft_do_operation("pb", lst_a, lst_b);
			ft_print_piles("pb", lst_a, lst_b);
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

static void	ft_get_descending_stack_b(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	t_list	*tmp;
	int		i;
	int		lst_length;
	int		max_value;
	int		min_value;

	i = 1;
	lst_length = ft_lstsize(lst_b);
	max_value = ft_found_value_max(lst_b, lst_length);
	min_value = ft_found_value_min(lst_b, lst_length);
	tmp = *lst_b;
	while (i <= lst_length)
	{
		if (tmp->value == max_value || tmp->value == min_value
			|| tmp->prev->value == min_value)
		{
			if (tmp->prev->value == min_value)
			{
				ft_do_operation("pa", lst_a, lst_b);
				ft_print_piles("pa", lst_a, lst_b);
			}
			else
			{
				ft_do_operation("rb", lst_a, lst_b);
				ft_print_piles("rb", lst_a, lst_b);
			}
		}
		else if (tmp->prev->value < tmp->value)
		{
			ft_do_operation("pa", lst_a, lst_b);
			ft_print_piles("pa", lst_a, lst_b);
		}
		{
			ft_do_operation("rb", lst_a, lst_b);
			ft_print_piles("rb", lst_a, lst_b);
		}
	}
	tmp = *lst_b;
	i++;
}

// static void	ft_get_descending_stack_b(t_list **lst_a, t_list **lst_b,
// 	t_instruction **lst_instruction)
// {
// 	t_list	*tmp;
// 	int		i;
// 	int		lst_length;
// 	int		value_min;
// 	int		value_max;

// 	i = 1;
// 	lst_length = ft_lstsize(lst_b);
// 	value_min = ft_found_value_min(lst_b, lst_length);
// 	value_max = ft_found_value_max(lst_b, lst_length);
// 	tmp = *lst_b;
// 	while (i <= lst_length)
// 	{
// 		printf("[%d] => [%d]\n", i, lst_length);
// 		printf("??? [%d] < [%d] ???\n", tmp->value, tmp->next->value);
// 		if (tmp->value == value_min && tmp->next->value != value_max)
// 		{
// 			ft_do_operation("rb", lst_a, lst_b);
// 			ft_print_piles("rb", lst_a, lst_b);
// 		}
// 		else if (tmp->value < tmp->next->value && tmp->value != value_min)
// 		{
// 			printf("	[%d] < [%d]\n", tmp->value, tmp->next->value);
// 			ft_do_operation("pa", lst_a, lst_b);
// 			ft_print_piles("pa", lst_a, lst_b);
// 			lst_length--;
// 		}
// 		else
// 		{
// 			ft_do_operation("rb", lst_a, lst_b);
// 			ft_print_piles("rb", lst_a, lst_b);
// 		}
// 		tmp = *lst_b;
// 		i++;
// 	}
// }

void	ft_get_order(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, char lst_keeping)
{
	printf("A or B ?\n");
	if (lst_keeping == 'A')
	{
		printf("A !\n");
		ft_get_ascending_stack_a(lst_a, lst_b, lst_instruction);
	}
	else if (lst_keeping == 'B')
	{
		printf("B !\n");
		ft_get_descending_stack_b(lst_a, lst_b, lst_instruction);
	}
}
