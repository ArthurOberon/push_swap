/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:48:12 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/31 12:07:57 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_get_ascendent_sequence(t_list **lst)
{
	int		*coordonate[2];
	int		*coordonate_tmp[2];
	t_list	*last;
	t_list	*tmp;

	*coordonate = 0;
	*coordonate_tmp = 0;
	last = (*lst)->prev;
	tmp = last->next;
	while (tmp != last)
	{
		if (tmp->value < tmp->next->value)
		{
			if ((coordonate[1] - coordonate[0])
				> (coordonate_tmp[1] - coordonate_tmp[0]))
				*coordonate_tmp = *coordonate;
			coordonate[0] = coordonate[1];
		}
		coordonate[1]++;
		tmp = tmp->next;
	}
	return (*coordonate);
}

void	ft_get_order(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	int	*coordonate[2];

	*coordonate = ft_get_ascendent_sequence(lst_a);
	
}
