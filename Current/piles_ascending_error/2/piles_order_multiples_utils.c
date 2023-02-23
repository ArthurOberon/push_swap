/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_order_multiples_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:24:50 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/22 16:02:29 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_while_number_return(int size, int n)
{
	if (size <= 5)
		return (2 + n);
	if (size <= 15)
		return (5 + n);
	if (size <= 25)
		return (10 + n);
	else if (size <= 50)
		return (13 + n);
	else if (size <= 100)
		return (15 + n);
	else if (size <= 200)
		return (20 + n);
	else if (size <= 500)
		return (23 + n);
	return (0);
}

int	ft_get_while_number(t_list *lst)
{
	int		pos_zero;
	int		pos_max;
	int		size;
	int		n;
	t_list	*max;

	pos_zero = 0;
	pos_max = 0;
	max = lst;
	size = ft_lstsize(lst);
	while (lst->index != 0)
	{
		lst = lst->next;
		pos_zero++;
	}
	while (max->index != size - 1)
	{
		max = max->next;
		pos_max++;
	}
	if (pos_zero < size / 2 && pos_max < size / 2)
		n = 1;
	else
		n = 0;
	return (ft_get_while_number_return(size, n));
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
