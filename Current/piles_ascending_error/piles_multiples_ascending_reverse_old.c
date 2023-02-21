/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_multiples_ascending_reverse.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:55:52 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/20 17:33:56 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_ascending_reverse_from_n(t_list *tmp_a, int n)
{
	t_list	*first;
	int		i;
	int		count;
	int		current_index;

	i = -1;
	count = 1;
	first = tmp_a;
	while (++i < n)
		tmp_a = tmp_a->next;
	printf("TMP[%d] = %d\n", i, tmp_a->index);
	current_index = tmp_a->index;
	tmp_a = tmp_a->prev;
	while (tmp_a != first)
	{
		if (current_index > tmp_a->index)
		{
			current_index = tmp_a->index;
			count++;
		}
		tmp_a = tmp_a->prev;
	}
	if (current_index > tmp_a->index)
	{
		current_index = tmp_a->index;
		count++;
	}
	return (count);
}

void	ft_get_ascending_reverse_from_n(t_push_swap p, int n)
{
	int		i;
	t_list	*pile_a;
	t_list	*starter;
	t_list	*ender;
	t_list	*current;

	i = 0;
	pile_a = *p.pile_a;
	starter = *p.pile_a;
	while (i++ < n)
		starter = starter->next;
	ender = starter;
	while (pile_a != starter)
	{
		printf("\ncurrent = %d & starter = %d\n", pile_a->index, starter->index);
		ft_print_piles("REVERSE GET ASCENDING", p);
		if (pile_a->index > starter->index)
		{
			ender = pile_a;
			ft_move("ra", p);
		}
		else
			ft_move("pb", p);
		pile_a = *p.pile_a;
		printf("ENDER = %d\n", ender->index);
	}
	current = pile_a;
	ft_move("ra", p);
	pile_a = *p.pile_a;
	while (pile_a != ender)
	{
		printf("STARTER =  %d\n", starter->index);
		printf("\n pile_a = %d & current = %d\n", pile_a->index, current->index);
		ft_print_piles("REVERSE GET ASCENDING", p);
		if (pile_a->index > current->index)
		{
			current = pile_a;
			ft_move("ra", p);
		}
		else
			ft_move("pb", p);
		pile_a = *p.pile_a;
	}
}


int	ft_piles_multiples_ascending_reverse(t_push_swap p, int *pos)
{
	int	i;
	int	n;
	int	size;
	int	current;
	int	biggest;

	size = ft_lstsize(*p.pile_a);
	i = size - 1;
	biggest = 0;
	ft_print_piles("", p);
	while (i >= 0)
	{
		printf("I = %d\n", i);
		current = ft_count_ascending_reverse_from_n(*p.pile_a, i);
		printf("REVERSE ==> CURRENT = %d && BIG = %d\n", current, biggest);
		if (current > biggest || biggest == 0)
		{
			biggest = current;
			n = i;
		}
		i--;
	}
	printf("REVERSE ==> BIGGEST = %d && N = %d\n", biggest, n);
	*pos = n;
	return (biggest);
}
