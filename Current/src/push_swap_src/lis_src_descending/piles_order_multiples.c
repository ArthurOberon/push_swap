/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_order_multiples.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:27:55 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/22 15:46:55 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_int_tabchr(int *tab, int size, t_list *tmp)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (tab[i] == tmp->index)
			return (1);
	}
	return (0);
}

static void	ft_get_ascending_descending(t_push_swap p, t_sequence_data sequence)
{
	t_list	*pile_a;
	t_list	*last;

	pile_a = *p.pile_a;
	last = pile_a->prev;
	while (pile_a != last)
	{
		if (ft_int_tabchr(sequence.tab, sequence.count, pile_a) == 1)
			ft_move("ra", p);
		else
			ft_move("pb", p);
		pile_a = *p.pile_a;
	}
	if (ft_int_tabchr(sequence.tab, sequence.count, pile_a) == 0)
		ft_move("pb", p);
}

void	ft_piles_order_multiples(t_push_swap p)
{
	t_sequence_data	ascending;
	t_sequence_data	descending;

	ascending = ft_piles_multiples_ascending(p);
	descending = ft_piles_multiples_descending(p);
	if (ascending.count > descending.count)
		ft_get_ascending_descending(p, ascending);
	else
		ft_get_ascending_descending(p, descending);
	free(ascending.tab);
	free(descending.tab);
}
