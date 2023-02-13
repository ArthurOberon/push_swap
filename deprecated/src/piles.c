/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:12:51 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/09 15:27:52 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_go_to_element_pile(t_list **start, t_list *dst)
{
	while (*start != dst)
	{
		*start = (*start)->next;
	}
}

t_list	*ft_get_the_n_element_pile(t_list *start, int n)
{
	int		i;
	t_list	*last;

	i = 0;
	last = start->prev;
	while (i < n && start != last)
	{
		start = start->next;
		i++;
	}
	return (start);
}

int	ft_calcul_gap(t_coordonate coordonate_a, t_coordonate coordonate_b)
{
	int		a;
	int		b;
	t_list	*tmp_a;
	t_list	*tmp_b;

	a = 0;
	b = 0;
	tmp_a = coordonate_a.start;
	tmp_b = coordonate_b.start;
	while (tmp_a != coordonate_a.end)
	{
		tmp_a = tmp_a->next;
		a++;
	}
	while (tmp_b != coordonate_b.end)
	{
		tmp_b = tmp_b->next;
		b++;
	}
	return (a < b);
}

int	ft_is_ascending(t_list *lst)
{
	t_list	*last;
	t_list	*min;

	min = ft_find_element_min(lst);
	if (min->index != 0)
		return (0);
	last = min->prev;
	while (min != last)
	{
		if (min->next->index != min->index + 1)
			return (0);
		min = min->next;
	}
	return (1);
}
