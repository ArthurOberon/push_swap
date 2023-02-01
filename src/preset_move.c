/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:37:29 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/01 13:39:51 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_preset_1_3_2(t_push_swap *list_pack, char list)
{
	if (list == 'A')
	{
		ft_move("sa", list_pack);
		ft_move("ra", list_pack);
	}
	if (list == 'B')
	{
		ft_move("sb", list_pack);
		ft_move("rrb", list_pack);
	}
}

void	ft_preset_2_3_1(t_push_swap *list_pack, char list)
{
	if (list == 'A')
		ft_move("rra", list_pack);
	if (list == 'B')
		ft_move("rrb", list_pack);
}

void	ft_preset_2_1_3(t_push_swap *list_pack, char list)
{
	if (list == 'A')
		ft_move("sa", list_pack);
	if (list == 'B')
		ft_move("sb", list_pack);
}

void	ft_preset_3_2_1(t_push_swap *list_pack, char list)
{
	if (list == 'A')
	{
		ft_move("sa", list_pack);
		ft_move("rra", list_pack);
	}
	if (list == 'B')
	{
		ft_move("sb", list_pack);
		ft_move("rrb", list_pack);
	}
}

void	ft_preset_3_1_2(t_push_swap *list_pack, char list)
{
	if (list == 'A')
		ft_move("ra", list_pack);
	if (list == 'B')
		ft_move("rb", list_pack);
}
