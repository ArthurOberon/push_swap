/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:37:29 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/22 16:02:29 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_3_elements(t_push_swap p)
{
	int	first;
	int	second;
	int	third;

	first = (*p.pile_a)->index;
	second = (*p.pile_a)->next->index;
	third = (*p.pile_a)->next->next->index;
	if (second == 2 && third == 1)
		ft_preset_1_3_2(p, 'A');
	else if (first == 1 && second == 2)
		ft_preset_2_3_1(p, 'A');
	else if (first == 1 && third == 2)
		ft_preset_2_1_3(p, 'A');
	else if (second == 1 && first == 2)
		ft_preset_3_2_1(p, 'A');
	else if (third == 1 && first == 2)
		ft_preset_3_1_2(p, 'A');
}
