/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:48:12 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/31 10:28:00 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_get_ascendent_sequence(t_list **lst)
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

int	ft_get_stack_info(t_list **lst)
{
	return (0);
}
