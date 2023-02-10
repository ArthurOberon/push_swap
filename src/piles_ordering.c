/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_ordering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:48:12 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/10 14:49:52 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_coordonate	ft_get_ascending_sequence(t_list **lst)
{
	t_coordonate	coordonate;
	t_coordonate	coordonate_tmp;
	int				i;
	int				size;

	i = -1;
	size = ft_lstsize(*lst);
	coordonate = ft_coordonate_from_list(*lst);
	coordonate_tmp = ft_coordonate_from_list(*lst);
	while (++i < size)
	{
		if (coordonate_tmp.end->value > coordonate_tmp.end->next->value)
		{
			if (ft_calcul_gap(coordonate, coordonate_tmp))
					coordonate = coordonate_tmp;
			ft_go_to_element_pile(&coordonate_tmp.start,
				coordonate_tmp.end->next);
		}
		coordonate_tmp.end = coordonate_tmp.end->next;
	}
	return (coordonate);
}

static void	ft_push_top(t_push_swap list_pack, t_list **coordonate)
{
	t_list	**tmp;
	t_list	*stop;

	tmp = list_pack.pile_a;
	stop = *coordonate;
	while (*tmp != stop)
	{
		if ((*tmp)->index < (*coordonate)->index)
		{
			*coordonate = *tmp;
			ft_move("ra", list_pack);
		}
		else
			ft_move("pb", list_pack);
	}
}

static void	ft_push_bottom(t_push_swap list_pack, t_coordonate *coordonate)
{
	t_list	**tmp;
	t_list	*stop;

	tmp = list_pack.pile_a;
	stop = coordonate->start;
	while (*tmp != stop)
	{
		if ((*tmp)->index > coordonate->end->index
			&& (*tmp)->index < coordonate->start->index)
		{
			coordonate->end = *tmp;
			ft_move("ra", list_pack);
		}
		else if ((*tmp)->index > coordonate->end->index)
		{
			coordonate->end = *tmp;
			ft_move("ra", list_pack);
		}
		else
			ft_move("pb", list_pack);
	}
}

void	ft_get_order(t_push_swap list_pack)
{
	t_coordonate	coordonate;

	ft_check_obvious(list_pack);
	coordonate = ft_get_ascending_sequence(list_pack.pile_a);
	ft_push_top(list_pack, &(coordonate.start));
	if (coordonate.end->next != coordonate.start)
	{
		if (coordonate.end->next->index < coordonate.start->index
			&& coordonate.end->next->next == coordonate.start)
			ft_move_to_top_pile_a(list_pack, coordonate.end->next->next);
		else
			ft_move_to_top_pile_a(list_pack, coordonate.end->next);
		ft_push_bottom(list_pack, &coordonate);
	}
}
