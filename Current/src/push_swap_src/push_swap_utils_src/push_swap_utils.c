/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:54:31 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/23 14:39:35 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_ascending(t_list *lst)
{
	t_list	*last;
	t_list	*min;

	min = ft_find_element_min(lst);
	if (min->index != 0)
		return (2);
	last = min->prev;
	while (min != last)
	{
		if (min->next->index != min->index + 1)
			return (0);
		min = min->next;
	}
	return (1);
}

static int	ft_find_optimize_rotation(t_list **lst, t_list *lst_destination)
{
	int		r_number;
	int		rr_number;
	t_list	*tmp;

	tmp = *lst;
	r_number = 0;
	rr_number = 0;
	while (tmp != lst_destination)
	{
		r_number++;
		tmp = tmp->next;
	}
	tmp = *lst;
	while (tmp != lst_destination)
	{
		rr_number++;
		tmp = tmp->prev;
	}
	if (r_number <= rr_number)
		return (OPTIMIZE_R);
	return (OPTIMIZE_RR);
}

void	ft_move_to_top_pile_a(t_push_swap p, t_list *element)
{
	t_list	**tmp;

	tmp = p.pile_a;
	if (ft_find_optimize_rotation(p.pile_a, element) == OPTIMIZE_R)
	{
		while (*tmp != element)
			ft_move("ra", p);
	}
	else
	{
		while (*tmp != element)
		{
			ft_move("rra", p);
		}
	}
}
