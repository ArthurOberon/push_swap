/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:02:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/09 12:12:15 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_top_pile_a(t_push_swap list_pack, t_list *element)
{
	t_list	**tmp;

	tmp = list_pack.pile_a;
	if (ft_find_optimize_rotation(list_pack.pile_a, element) == OPTIMIZE_R)
	{
		while (*tmp != element)
			ft_move("ra", list_pack);
	}
	else
	{
		while (*tmp != element)
		{
			ft_move("rra", list_pack);
		}
	}
}

void	ft_move_to_top_pile_b(t_push_swap list_pack, t_list *element,
	t_instruction **lst_instruction)
{
	t_list	**tmp;

	tmp = list_pack.pile_b;
	if (ft_find_optimize_rotation(list_pack.pile_b, element) == OPTIMIZE_R)
	{
		while (*tmp != element)
		{
			ft_move_temporary("rb", list_pack, lst_instruction);
		}
	}
	else
	{
		while (*tmp != element)
		{
			ft_move_temporary("rrb", list_pack, lst_instruction);
		}
	}
}
