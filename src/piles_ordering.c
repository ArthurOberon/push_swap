/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_ordering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:48:12 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/09 08:24:18 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	**ft_get_ascending_sequence(t_list **lst)
{
	t_list	**coordonate;
	t_list	**coordonate_tmp;
	int		i;
	int		size;

	i = -1;
	size = ft_lstsize(*lst);
	coordonate = ft_listdup(*lst, 2);
	coordonate_tmp = ft_listdup(*lst, 2);
	if (!coordonate || !coordonate_tmp)
		return (NULL);
	while (++i < size)
	{
		if (coordonate_tmp[1]->value > coordonate_tmp[1]->next->value)
		{
			if (ft_calcul_gap(coordonate, coordonate_tmp))
				ft_listcpy(coordonate, coordonate_tmp);
			ft_go_to_element_pile(&coordonate_tmp[0], coordonate_tmp[1]->next);
		}
		coordonate_tmp[1] = coordonate_tmp[1]->next;
	}
	free(coordonate_tmp);
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

static void	ft_push_bottom(t_push_swap list_pack, t_list **coordonate)
{
	t_list	**tmp;
	t_list	*stop;

	tmp = list_pack.pile_a;
	stop = coordonate[0];
	while (*tmp != stop)
	{
		if (((*tmp)->index > coordonate[1]->index))
		{
			coordonate[1] = *tmp;
			ft_move("ra", list_pack);
		}
		else
			ft_move("pb", list_pack);
	}
}

		// else if ((*tmp)->index < coordonate[0]->index)
		// {
		// 	coordonate[0] = *tmp;
		// 	ft_move("ra", list_pack);
		// 	printf("NEW C[0] = %d[%d]\n", coordonate[0]->value,
			// coordonate[0]->index);
			// ft_print_piles("", list_pack);
		// }

void	ft_get_order(t_push_swap list_pack)
{
	t_list	**coordonate;

	ft_check_obvious(list_pack);
	coordonate = ft_get_ascending_sequence(list_pack.pile_a);
	if (!coordonate)
	{
		ft_lstclear(list_pack.pile_a);
		ft_lstclear(list_pack.pile_b);
		ft_lstclear_instruction(list_pack.instructions);
		ft_putstr_fd("Error with a malloc\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_push_top(list_pack, &coordonate[0]);
	if ((coordonate[1])->next != coordonate[0])
	{
		if (coordonate[1]->next->index < coordonate[0]->index
			&& coordonate[1]->next->next == coordonate[0])
			ft_move_to_top_pile_a(list_pack, coordonate[1]->next->next);
		else
			ft_move_to_top_pile_a(list_pack, coordonate[1]->next);
		ft_push_bottom(list_pack, coordonate);
	}
	free(coordonate);
}
