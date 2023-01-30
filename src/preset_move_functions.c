/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset_move_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:37:29 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/30 11:27:48 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_preset_1_3_2(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, char list)
{
	if (list == 'A')
	{
		ft_move("sa", lst_a, lst_b, lst_instruction);
		ft_move("ra", lst_a, lst_b, lst_instruction);
	}
	if (list == 'B')
	{
		ft_move("sb", lst_a, lst_b, lst_instruction);
		ft_move("rrb", lst_a, lst_b, lst_instruction);
	}
}

void	ft_preset_2_3_1(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, char list)
{
	if (list == 'A')
		ft_move("rra", lst_a, lst_b, lst_instruction);
	if (list == 'B')
		ft_move("rrb", lst_a, lst_b, lst_instruction);
}

void	ft_preset_2_1_3(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, char list)
{
	if (list == 'A')
		ft_move("sa", lst_a, lst_b, lst_instruction);
	if (list == 'B')
		ft_move("sb", lst_a, lst_b, lst_instruction);
}

void	ft_preset_3_2_1(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, char list)
{
	if (list == 'A')
	{
		ft_move("sa", lst_a, lst_b, lst_instruction);
		ft_move("rra", lst_a, lst_b, lst_instruction);
	}
	if (list == 'B')
	{
		ft_move("sb", lst_a, lst_b, lst_instruction);
		ft_move("rrb", lst_a, lst_b, lst_instruction);
	}
}

void	ft_preset_3_1_2(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, char list)
{
	if (list == 'A')
		ft_move("ra", lst_a, lst_b, lst_instruction);
	if (list == 'B')
		ft_move("rb", lst_a, lst_b, lst_instruction);
}
