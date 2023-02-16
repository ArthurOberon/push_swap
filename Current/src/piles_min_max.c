/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:23:28 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/16 16:53:09 by aoberon          ###   ########.fr       */
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
