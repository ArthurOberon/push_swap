/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_multiples_ascending.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:55:52 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/19 19:53:15 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_ascending_from_n(t_list *tmp_a, int n)
{
	t_list	*last;
	int		i;
	int		count;
	int		current_index;

	i = -1;
	count = 1;
	last = tmp_a->prev;
	while (++i < n)
		tmp_a = tmp_a->next;
	current_index = tmp_a->index;
	tmp_a = tmp_a->next;
	while (tmp_a != last)
	{
		if (current_index < tmp_a->index)
		{
			current_index = tmp_a->index;
			count++;
		}
		tmp_a = tmp_a->next;
	}
	if (current_index < tmp_a->index)
	{
		current_index = tmp_a->index;
		count++;
	}
	return (count);
}

static void	ft_get_ascending_from_n(t_push_swap p, int n)
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
		ft_print_piles("GET ASCENDING", p);
		if (pile_a->index > starter->index)
		{
			ender = pile_a;
			ft_move("ra", p);
		}
		else
			ft_move("pb", p);
		pile_a = *p.pile_a;
	}
	current = pile_a;
	ft_move("ra", p);
	while (pile_a != ender)
	{
		ft_print_piles("GET ASCENDING", p);
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

void	ft_piles_multiples_ascending(t_push_swap p)
{
	int	i;
	int	n;
	int	size;
	int	current;
	int	biggest;

	i = 0;
	biggest = 0;
	size = ft_lstsize(*p.pile_a);
	ft_print_piles("", p);
	while (i < size - 1)
	{
		printf("I = %d\n", i);
		current = ft_count_ascending_from_n(*p.pile_a, i);
		printf("CURRENT = %d && BIG = %d\n", current, biggest);
		if (current > biggest || biggest == 0)
		{
			biggest = current;
			n = i;
		}
		i++;
	}
	printf("BIGGEST = %d && N = %d\n", biggest, n);
	ft_get_ascending_from_n(p, n);
}
