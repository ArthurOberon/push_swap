/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:37:29 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/06 16:57:18 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_preset_1_3_2(t_push_swap list_pack, char pile)
{
	if (pile == 'A')
	{
		ft_move("sa", list_pack);
		ft_move("ra", list_pack);
	}
	if (pile == 'B')
	{
		ft_move("sb", list_pack);
		ft_move("rrb", list_pack);
	}
}

void	ft_preset_2_3_1(t_push_swap list_pack, char pile)
{
	if (pile == 'A')
		ft_move("rra", list_pack);
	if (pile == 'B')
		ft_move("rrb", list_pack);
}

void	ft_preset_2_1_3(t_push_swap list_pack, char pile)
{
	if (pile == 'A')
		ft_move("sa", list_pack);
	if (pile == 'B')
		ft_move("sb", list_pack);
}

void	ft_preset_3_2_1(t_push_swap list_pack, char pile)
{
	if (pile == 'A')
	{
		ft_move("sa", list_pack);
		ft_move("rra", list_pack);
	}
	if (pile == 'B')
	{
		ft_move("sb", list_pack);
		ft_move("rrb", list_pack);
	}
}

void	ft_preset_3_1_2(t_push_swap list_pack, char pile)
{
	if (pile == 'A')
		ft_move("ra", list_pack);
	if (pile == 'B')
		ft_move("rb", list_pack);
}

void	ft_3_elements(t_push_swap list_pack)
{
	int	first;
	int	second;
	int	third;

	first = (*list_pack.pile_a)->index;
	second = (*list_pack.pile_a)->next->index;
	third = (*list_pack.pile_a)->next->next->index;
	if (second == 2 && third == 1)
		ft_preset_1_3_2(list_pack, 'A');
	else if (first == 1 && second == 2)
		ft_preset_2_3_1(list_pack, 'A');
	else if (first == 1 && third == 2)
		ft_preset_2_1_3(list_pack, 'A');
	else if (second == 1 && first == 2)
		ft_preset_3_2_1(list_pack, 'A');
	else if (third == 1 && first == 2)
		ft_preset_3_1_2(list_pack, 'A');
}
