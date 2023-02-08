/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_ordering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:48:12 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/08 18:08:51 by aoberon          ###   ########.fr       */
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

void	ft_check_obvious(t_push_swap list_pack)
{
	t_list	*tmp;

	if (ft_lstsize(*list_pack.pile_a) == 3)
		ft_3_elements(list_pack);
	tmp = *(list_pack.pile_a);
	if (tmp->index > tmp->next->index)
		ft_move("sa", list_pack);
}

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
