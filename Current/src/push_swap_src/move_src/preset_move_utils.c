/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:54:08 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/22 16:02:29 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_preset_1_3_2(t_push_swap p, char pile)
{
	if (pile == 'A')
	{
		ft_move("sa", p);
		ft_move("ra", p);
	}
	if (pile == 'B')
	{
		ft_move("sb", p);
		ft_move("rrb", p);
	}
}

void	ft_preset_2_3_1(t_push_swap p, char pile)
{
	if (pile == 'A')
		ft_move("rra", p);
	if (pile == 'B')
		ft_move("rrb", p);
}

void	ft_preset_2_1_3(t_push_swap p, char pile)
{
	if (pile == 'A')
		ft_move("sa", p);
	if (pile == 'B')
		ft_move("sb", p);
}

void	ft_preset_3_2_1(t_push_swap p, char pile)
{
	if (pile == 'A')
	{
		ft_move("sa", p);
		ft_move("rra", p);
	}
	if (pile == 'B')
	{
		ft_move("sb", p);
		ft_move("rrb", p);
	}
}

void	ft_preset_3_1_2(t_push_swap p, char pile)
{
	if (pile == 'A')
		ft_move("ra", p);
	if (pile == 'B')
		ft_move("rb", p);
}
