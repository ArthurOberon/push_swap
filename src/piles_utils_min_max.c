/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_utils_min_max.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:47:31 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/04 11:58:33 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_element_min(t_list *lst)
{
	t_list	*min;
	t_list	*last;

	last = lst->prev;
	min = last;
	while (lst != last)
	{
		if (lst->index < min->index)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

t_list	*ft_find_element_max(t_list *lst)
{
	t_list	*last;
	t_list	*max;

	last = lst->prev;
	max = last;
	while (lst != last)
	{
		if (lst->index > max->index)
			max = lst;
		lst = lst->next;
	}
	return (max);
}

t_instruction	*ft_push_before_min(t_push_swap list_pack,
	t_instruction **tmp_instruction)
{
	t_list	**tmp_a;
	t_list	*min;

	tmp_a = list_pack.pile_a;
	min = ft_find_element_min(*list_pack.pile_a);
	if (ft_find_optimize_rotation(list_pack.pile_a, min) == OPTIMIZE_R)
	{
		while ((*tmp_a) != min)
			ft_move_temporary("ra", list_pack, tmp_instruction);
		ft_move_temporary("pa", list_pack, tmp_instruction);
		return (*tmp_instruction);
	}
	while ((*tmp_a) != min)
		ft_move_temporary("rra", list_pack, tmp_instruction);
	ft_move_temporary("pa", list_pack, tmp_instruction);
	return (*tmp_instruction);
}

t_instruction	*ft_push_after_max(t_push_swap list_pack,
	t_instruction **tmp_instruction)
{
	t_list	**tmp_a;
	t_list	*max;

	tmp_a = list_pack.pile_a;
	max = ft_find_element_max(*list_pack.pile_a);
	if (ft_find_optimize_rotation(list_pack.pile_a, max) == OPTIMIZE_R)
	{
		while ((*tmp_a) != max->next)
			ft_move_temporary("ra", list_pack, tmp_instruction);
		ft_move_temporary("pa", list_pack, tmp_instruction);
		return (*tmp_instruction);
	}
	while ((*tmp_a) != max->next)
		ft_move_temporary("rra", list_pack, tmp_instruction);
	ft_move_temporary("pa", list_pack, tmp_instruction);
	return (*tmp_instruction);
}
