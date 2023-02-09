/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:12:51 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/09 10:31:47 by aoberon          ###   ########.fr       */
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

int	ft_calcul_gap(t_list **coordonate_a, t_list **coordonate_b)
{
	int		a;
	int		b;
	t_list	*tmp_a;
	t_list	*tmp_b;

	a = 0;
	b = 0;
	tmp_a = coordonate_a[0];
	tmp_b = coordonate_b[0];
	while (tmp_a != coordonate_a[1])
	{
		tmp_a = tmp_a->next;
		a++;
	}
	while (tmp_b != coordonate_b[1])
	{
		tmp_b = tmp_b->next;
		b++;
	}
	printf("%d %d", a, b);
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
