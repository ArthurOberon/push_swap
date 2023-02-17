/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_ascending_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:24:50 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/17 18:05:03 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_while_number(t_list *lst)
{
	int	size;

	size = ft_lstsize(lst);
	if (size <= 25)
		return (5);
	else if (size <= 50)
		return (15);
	else if (size <= 100)
		return (15);
	else if (size <= 200)
		return (45);
	else if (size <= 500)
		return (50);
	return (100);
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
