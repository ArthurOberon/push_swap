/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:17:56 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/12 17:17:30 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_list **lst_from, t_list **lst_to)
{
	t_list	*tmp;

	tmp = ft_lstdelone(lst_from);
	ft_lstadd_back(lst_to, tmp);
}

static void	ft_swap(char *str, t_list **lst_a, t_list **lst_b)
{
	int	swap;

	if ((*str == 'a' || *str == 's') && *lst_a)
	{
		swap = (*lst_a)->value;
		(*lst_a)->value = (*lst_a)->prev->value;
		(*lst_a)->prev->value = swap;
	}
	if ((*str == 'b' || *str == 's') && *lst_b)
	{
		swap = (*lst_b)->value;
		(*lst_b)->value = (*lst_b)->prev->value;
		(*lst_b)->prev->value = swap;
	}
}

static void	ft_do_rotate(t_list **lst, int reverse)
{
	if (reverse == 0)
		(*lst) = (*lst)->prev;
	else
		(*lst) = (*lst)->next;
}

static void	ft_rotate(char *str, t_list **lst_a, t_list **lst_b)
{
	int	reverse;

	reverse = (str[0] == 'r');
	if ((*str == 'a' || *str == 'r') && *lst_a)
		ft_do_rotate(lst_a, reverse);
	if ((*str == 'b' || *str == 's') && *lst_b)
		ft_do_rotate(lst_b, reverse);
}

void	ft_do_operation(char *str, t_list **lst_a, t_list **lst_b)
{
	if (*str == 'p')
	{
		str++;
		if (*str == 'a')
			ft_push(lst_a, lst_b);
		if (*str == 'b')
			ft_push(lst_b, lst_a);
	}
	else if (*str == 's')
		ft_swap(str + 1, lst_a, lst_b);
	else if (*str == 'r')
		ft_rotate(str + 1, lst_a, lst_b);
}
