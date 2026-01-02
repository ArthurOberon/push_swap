/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:27:11 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/17 12:38:59 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

int	ft_find_value_max(t_list *lst, int *size)
{
	t_list	*last;
	t_list	*max;

	last = lst->prev;
	max = last;
	*size = 1;
	while (lst != last)
	{
		if (lst->value > max->value)
			max = lst;
		lst = lst->next;
		(*size)++;
	}
	return (max->index);
}
