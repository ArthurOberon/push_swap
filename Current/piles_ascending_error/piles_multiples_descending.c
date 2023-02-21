/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_multiples_descending.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:31:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/21 18:32:00 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_get_descending_from_n(t_push_swap p, t_sequence_data sequence)
// {
// 	int		previous_current;
// 	t_list	*pile_a;

// 	pile_a = *p.pile_a;
// 	previous_current = sequence.last;
// 	while (pile_a->index != sequence.last)
// 	{
// 		ft_move("pb", p);
// 		pile_a = *p.pile_a;
// 	}
// 	ft_move("ra", p);
// 	pile_a = *p.pile_a;
// 	while (pile_a->index != sequence.first)
// 	{
// 		ft_print_piles("REVERSE", p);
// 		if (pile_a->index > previous_current && pile_a->index < sequence.first)
// 		{
// 			previous_current = pile_a->index;
// 			ft_move("ra", p);
// 		}
// 		else
// 			ft_move("pb", p);
// 		pile_a = *p.pile_a;
// 	}
// 	ft_move("ra", p);
// 	pile_a = *p.pile_a;
// 	while (pile_a->index != sequence.last)
// 	{
// 		ft_print_piles("REVERSE 2", p);
// 		ft_move("pb", p);
// 		pile_a = *p.pile_a;
// 	}
// }

// void	ft_get_descending_from_n(t_push_swap p, int n)
// {
// 	int		i;
// 	t_list	*pile_a;
// 	t_list	*starter;
// 	t_list	*ender;
// 	t_list	*current;

// 	i = 0;
// 	pile_a = *p.pile_a;
// 	starter = *p.pile_a;
// 	while (i++ < n)
// 		starter = starter->next;
// 	ender = starter;
// 	while (pile_a != starter)
// 	{
// 		printf("\ncurrent = %d & starter = %d\n", pile_a->index, starter->index);
// 		ft_print_piles("REVERSE GET ASCENDING", p);
// 		if (pile_a->index > starter->index)
// 		{
// 			ender = pile_a;
// 			ft_move("ra", p);
// 		}
// 		else
// 			ft_move("pb", p);
// 		pile_a = *p.pile_a;
// 		printf("ENDER = %d\n", ender->index);
// 	}
// 	current = pile_a;
// 	ft_move("ra", p);
// 	pile_a = *p.pile_a;
// 	while (pile_a != ender)
// 	{
// 		printf("STARTER =  %d\n", starter->index);
// 		printf("\n pile_a = %d & current = %d\n", pile_a->index, current->index);
// 		ft_print_piles("REVERSE GET ASCENDING", p);
// 		if (pile_a->index > current->index)
// 		{
// 			current = pile_a;
// 			ft_move("ra", p);
// 		}
// 		else
// 			ft_move("pb", p);
// 		pile_a = *p.pile_a;
// 	}
// }
