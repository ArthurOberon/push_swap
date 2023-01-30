/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorting_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:08:14 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/25 17:31:19 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_order(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, char lst_keeping)
{
	if (lst_keeping == 'A')
	{
		ft_get_ascending_stack_a(lst_a, lst_b, lst_instruction);
	}
	else if (lst_keeping == 'B')
	{
		ft_get_descending_stack_b(lst_a, lst_b, lst_instruction);
	}
}
