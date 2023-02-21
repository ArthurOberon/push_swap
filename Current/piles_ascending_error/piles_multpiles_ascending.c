/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_multpiles_ascending.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:30:47 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/21 18:31:14 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	ft_count_ascending_from_n(t_list *tmp_a, int n)
// {
// 	t_list	*last;
// 	int		i;
// 	int		count;
// 	int		current_index;

// 	i = -1;
// 	count = 1;
// 	while (++i < n)
// 		tmp_a = tmp_a->next;
// 	last = tmp_a->prev;
// 	current_index = tmp_a->index;
// 	tmp_a = tmp_a->next;
// 	while (tmp_a != last)
// 	{
// 		if (current_index < tmp_a->index)
// 		{
// 			current_index = tmp_a->index;
// 			count++;
// 		}
// 		tmp_a = tmp_a->next;
// 	}
// 	if (current_index < tmp_a->index)
// 	{
// 		current_index = tmp_a->index;
// 		count++;
// 	}
// 	return (count);
// }

// int	ft_piles_multiples_ascending(t_push_swap p, int *pos)
// {
// 	int	i;
// 	int	n;
// 	int	size;
// 	int	current;
// 	int	biggest;

// 	i = 0;
// 	biggest = 0;
// 	size = ft_lstsize(*p.pile_a);
// 	ft_print_piles("", p);
// 	while (i < size - 1)
// 	{
// 		printf("I = %d\n", i);
// 		current = ft_count_ascending_from_n(*p.pile_a, i);
// 		printf("CURRENT = %d && BIG = %d\n", current, biggest);
// 		if (current > biggest || biggest == 0)
// 		{
// 			biggest = current;
// 			n = i;
// 		}
// 		i++;
// 	}
// 	printf("BIGGEST = %d && N = %d\n", biggest, n);
// 	*pos = n;
// 	return (biggest);
// }

// void	ft_get_ascending_from_n(t_push_swap p, t_sequence_data sequence)
// {
// 	int		previous_current;
// 	t_list	*pile_a;

// 	pile_a = *p.pile_a;
// 	previous_current = sequence.first;
// 	while (pile_a->index != sequence.first)
// 	{
// 		ft_move("pb", p);
// 		pile_a = *p.pile_a;
// 	}
// 	ft_move("ra", p);
// 	pile_a = *p.pile_a;
// 	while (pile_a->index != sequence.last)
// 	{
// 		ft_print_piles("REVERSE", p);
// 		if (pile_a->index > previous_current && pile_a->index < sequence.last)
// 		{
// 			previous_current = pile_a->index;
// 			ft_move("ra", p);
// 		}
// 		else
// 			ft_move("pb", p);
// 		pile_a = *p.pile_a;
// 	}
// }

// void	ft_get_ascending_from_n(t_push_swap p, int n)
// {
// 	t_list	*pile_a;
// 	t_list	*starter;
// 	t_list	*ender;
// 	int		current;
// 	int		smaller;

// 	pile_a = *p.pile_a;
// 	starter = *p.pile_a;
// 	while (n-- > 0)
// 		starter = starter->next;
// 	ender = starter;
// 	smaller = -1;
// 	while (pile_a != starter)
// 	{
// 		printf("\ncurrent = %d & starter = %d\n", pile_a->index, starter->index);
// 		ft_print_piles("GET ASCENDING", p);
// 		if (pile_a->index < starter->index && pile_a->index > smaller)
// 		{
// 			smaller = pile_a->index;
// 			if (ender->index == starter->index)
// 				ender = pile_a;
// 			ft_move("ra", p);
// 		}
// 		else
// 			ft_move("pb", p);
// 		pile_a = *p.pile_a;
// 	}
// 	current = pile_a->index;
// 	ft_move("ra", p);
// 	pile_a = *p.pile_a;
// 	printf("ENDER = %d\n", ender->index);
// 	while (pile_a != ender->prev)
// 	{
// 		printf("\npile_a = %d & current_index = %d\n", pile_a->index, current);
// 		ft_print_piles("GET ASCENDING", p);
// 		if (pile_a->index > current)
// 		{
// 			current = pile_a->index;
// 			ft_move("ra", p);
// 		}
// 		else
// 			ft_move("pb", p);
// 		pile_a = *p.pile_a;
// 	}
// 	if (pile_a->index <= current)
// 		ft_move("pb", p);
// }
