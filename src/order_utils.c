/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:02:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/31 16:05:33 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_go_to_element(t_list **start, t_list *end)
{
	while (*start != end)
	{
		*start = (*start)->next;
	}
}

int	ft_calcul_gap(t_list *start_a, t_list *end_a,
	t_list *start_b, t_list *end_b)
{
	int		a;
	int		b;
	t_list	*tmp_a;
	t_list	*tmp_b;

	a = 0;
	b = 0;
	tmp_a = start_a;
	tmp_b = start_b;
	while (tmp_a != end_a)
	{
		tmp_a = tmp_a->next;
		a++;
	}
	while (tmp_b != end_b)
	{
		tmp_b = tmp_b->next;
		b++;
	}
	return (a > b);
}
