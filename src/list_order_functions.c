/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_order_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:06:43 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/24 19:21:07 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_found_value_max(t_list **lst, int lst_length)
{
	int		i;
	int		value_max;
	t_list	*tmp;

	i = 1;
	value_max = 0;
	tmp = *lst;
	value_max = tmp->value;
	tmp = tmp->next;
	while (i <= lst_length)
	{
		if (tmp->value > value_max)
			value_max = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (value_max);
}

int	ft_found_value_min(t_list **lst, int lst_length)
{
	int		i;
	int		value_min;
	t_list	*tmp;

	i = 1;
	value_min = 0;
	tmp = *lst;
	value_min = tmp->value;
	tmp = tmp->next;
	while (i <= lst_length)
	{
		if (tmp->value < value_min)
			value_min = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (value_min);
}

static int	ft_is_in_order_ascending(t_list **tmp, int value_max, int value_min)
{
	if ((*tmp)->value == value_max && (*tmp)->next->value != value_min)
	{
		(*tmp) = (*tmp)->next;
		return (0);
	}
	else if ((*tmp)->value > (*tmp)->next->value && (*tmp)->value != value_max)
	{
		(*tmp) = (*tmp)->next;
		return (0);
	}
	(*tmp) = (*tmp)->next;
	return (1);
}

static int	ft_is_in_order_descending(t_list **tmp, int value_max,
	int value_min)
{
	if ((*tmp)->value == value_min && (*tmp)->next->value != value_max)
	{
		(*tmp) = (*tmp)->next;
		return (0);
	}
	else if ((*tmp)->value < (*tmp)->next->value && (*tmp)->value != value_min)
	{
		(*tmp) = (*tmp)->next;
		return (0);
	}
	(*tmp) = (*tmp)->next;
	return (1);
}

int	ft_is_in_order(t_list **lst)
{
	int		value_min;
	int		value_max;
	int		lst_length;
	int		i;
	t_list	*tmp;

	i = 0;
	lst_length = ft_lstsize(lst);
	value_min = ft_found_value_min(lst, lst_length);
	value_max = ft_found_value_max(lst, lst_length);
	tmp = *lst;
	while (++i < lst_length)
	{
		if (ft_is_in_order_ascending(&tmp, value_max, value_min) == 0)
			break ;
	}
	if (i == lst_length)
		return (ASCENDING);
	i = 0;
	while (++i < lst_length)
	{
		if (ft_is_in_order_descending(&tmp, value_max, value_min) == 0)
			break ;
	}
	if (i == lst_length)
		return (DESCENDING);
	return (0);
}
