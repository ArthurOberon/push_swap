/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:17:56 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/04 10:49:24 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_list **lst_from, t_list **lst_to)
{
	t_list	*tmp;

	if (*lst_from)
	{
		tmp = ft_lstmoveout(lst_from);
		ft_lstadd_back(lst_to, tmp);
		(*lst_to) = (*lst_to)->prev;
	}
}

static void	ft_swap(char *str, t_list **lst_a, t_list **lst_b)
{
	int	swap;
	int	swap_index;

	if ((*str == 'a' || *str == 's') && *lst_a)
	{
		swap = (*lst_a)->value;
		(*lst_a)->value = (*lst_a)->next->value;
		(*lst_a)->next->value = swap;
		swap_index = (*lst_a)->index;
		(*lst_a)->index = (*lst_a)->next->index;
		(*lst_a)->next->index = swap_index;
	}
	if ((*str == 'b' || *str == 's') && *lst_b)
	{
		swap = (*lst_b)->value;
		(*lst_b)->value = (*lst_b)->next->value;
		(*lst_b)->next->value = swap;
		(*lst_b)->next->value = swap;
		swap_index = (*lst_b)->index;
		(*lst_b)->index = (*lst_b)->next->index;
		(*lst_b)->next->index = swap_index;
	}
}

static void	ft_do_rotate(t_list **lst, int reverse)
{
	if (reverse == 1)
		(*lst) = (*lst)->prev;
	else
		(*lst) = (*lst)->next;
}

static void	ft_rotate(char *str, t_list **lst_a, t_list **lst_b)
{
	int	reverse;

	reverse = (str[0] == 'r' && str[1]);
	str += reverse;
	if ((*str == 'a' || *str == 'r') && *lst_a)
		ft_do_rotate(lst_a, reverse);
	if ((*str == 'b' || *str == 'r') && *lst_b)
		ft_do_rotate(lst_b, reverse);
}

void	ft_do_operation(char *str, t_list **lst_a, t_list **lst_b)
{
	printf("%s\n", str);
	if (*str == 'p')
	{
		str++;
		if (*str == 'a')
			ft_push(lst_b, lst_a);
		if (*str == 'b')
			ft_push(lst_a, lst_b);
	}
	else if (*str == 's')
		ft_swap(str + 1, lst_a, lst_b);
	else if (*str == 'r')
		ft_rotate(str + 1, lst_a, lst_b);
}
