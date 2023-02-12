/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:27:11 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/12 18:34:00 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_find_value_max(t_list *lst)
{
	t_list	*last;
	t_list	*max;

	last = lst->prev;
	max = last;
	while (lst != last)
	{
		if (lst->value > max->value)
			max = lst;
		lst = lst->next;
	}
	return (max->value);
}

int	maxvalue(t_list *p, int *pop)
{
	t_list	*cur;
	int		max;

	max = ft_abs(p->value);
	cur = p->next;
	*pop = 1;
	while (cur != p)
	{
		if (ft_abs(cur->value) > max)
			max = ft_abs(cur->value);
		cur = cur->next;
		(*pop)++;
	}
	return (max);
}
