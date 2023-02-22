/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_multiples_ascending.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:55:52 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/21 21:01:38 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 2 lines to removes
static int	*ft_create_ascending_tab(t_list *tmp_a, int size, int n)
{
	int		i;
	int		last;
	int		*tab;
	t_list	*end;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (n-- > 0)
		tmp_a = tmp_a->next;
	i = -1;
	tab[++i] = tmp_a->index;
	last = tmp_a->index;
	end = tmp_a->prev;
	tmp_a = tmp_a->next;
	while (tmp_a != end)
	{
		if (last < tmp_a->index)
		{
			last = tmp_a->index;
			tab[++i] = tmp_a->index;
		}
		tmp_a = tmp_a->next;
	}
	if (last < tmp_a->index)
		tab[++i] = tmp_a->index;
	return (tab);
}

// 7 lines to removes
static t_sequence_data	ft_count_ascending_from_n(t_list *tmp_a, int n)
{
	int				i;
	t_list			*end;
	t_list			*lst;
	t_sequence_data	sequence_data;

	i = -1;
	sequence_data.pos = n;
	sequence_data.count = 1;
	lst = tmp_a;
	while (++i < n)
		tmp_a = tmp_a->next;
	end = tmp_a->prev;
	sequence_data.first = tmp_a->index;
	sequence_data.last = tmp_a->index;
	tmp_a = tmp_a->next;
	while (tmp_a != end)
	{
		if (sequence_data.last < tmp_a->index)
		{
			sequence_data.last = tmp_a->index;
			sequence_data.count++;
		}
		tmp_a = tmp_a->next;
	}
	if (sequence_data.last < tmp_a->index)
	{
		sequence_data.last = tmp_a->index;
		sequence_data.count++;
	}
	// printf("COUNT = %d\n", sequence_data.count);
	sequence_data.tab = ft_create_ascending_tab(lst, sequence_data.count, n);
	// ft_print_tab_int(sequence_data.tab, sequence_data.count);
	return (sequence_data);
}

t_sequence_data	ft_piles_multiples_ascending(t_push_swap p)
{
	int				i;
	int				size;
	t_sequence_data	current_data;
	t_sequence_data	biggest_data;

	size = ft_lstsize(*p.pile_a);
	i = 0;
	biggest_data.count = 0;
	// ft_print_piles("", p);
	while (i < size - 1)
	{
		// printf("I = %d\n", i);
		current_data = ft_count_ascending_from_n(*p.pile_a, i);
		// printf("CURRENT = %d && BIG = %d\n", current_data.count, biggest_data.count);
		if (current_data.count > biggest_data.count || biggest_data.count == 0)
		{
			if (biggest_data.count != 0)
				free(biggest_data.tab);
			biggest_data = current_data;
		}
		else
			free(current_data.tab);
		i++;
	}
	// printf("BIGGEST = %d && N = %d\n", biggest_data.count, biggest_data.pos);
	// printf("		FIRST = %d & LAST = %d\n", biggest_data.first, biggest_data.last);
	return (biggest_data);
}
