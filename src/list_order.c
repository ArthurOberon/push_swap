/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:48:12 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/02 17:14:11 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	**ft_get_ascending_sequence(t_list **lst)
{
	t_list	*coordonate[2];
	t_list	**coordonate_tmp;
	int		i;
	int		size;

	i = -1;
	size = ft_lstsize(*lst);
	coordonate[0] = *lst;
	coordonate[1] = *lst;
	coordonate_tmp = malloc(sizeof(t_list *) * 2);
	if (!coordonate_tmp)
		return (NULL);
	coordonate_tmp[0] = *lst;
	coordonate_tmp[1] = *lst;
	while (++i < size)
	{
		if (coordonate[1]->value > coordonate[1]->next->value)
		{
			if (ft_calcul_gap(coordonate[0], coordonate[1],
					coordonate_tmp[0], coordonate_tmp[1]))
			{
				coordonate_tmp[0] = coordonate[0];
				coordonate_tmp[1] = coordonate[1];
			}
			ft_go_to_element_pile(&coordonate[0], coordonate[1]->next);
		}
		coordonate[1] = coordonate[1]->next;
	}
	return (coordonate_tmp);
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

static void	ft_push_bottom(t_push_swap list_pack, t_list **coordonate)
{
	t_list	**tmp;
	t_list	*stop;

	tmp = list_pack.pile_a;
	stop = coordonate[0];
	while (*tmp != stop)
	{
		if ((*tmp)->index > (coordonate[1])->index)
		{
			coordonate[1] = *tmp;
			ft_move("ra", list_pack);
		}
		else
			ft_move("pb", list_pack);
	}
}

void	ft_get_order(t_push_swap list_pack)
{
	t_list	**coordonate;

	coordonate = ft_get_ascending_sequence(list_pack.pile_a);
	if (!coordonate)
		printf("Panic ! Do a function to exit and free\n");
	ft_push_top(list_pack, &coordonate[0]);
	if ((coordonate[1])->next != coordonate[0])
	{
		ft_move_to_top_pile_a(list_pack, coordonate[1]->next);
		ft_push_bottom(list_pack, coordonate);
	}
	free(coordonate);
}
