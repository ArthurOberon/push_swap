/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:20:44 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/23 20:13:34 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_int_tabchr(int *tab, int size, t_list *tmp)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (tab[i] == tmp->index)
			return (1);
	}
	return (0);
}

int	find_median(t_push_swap p, int *lis_tab_index)
{
	int		size;
	int		*tab;
	int		median;

	size = ft_lstsize(*p.pile_a);
	tab = ft_tab_from_list(p.pile_a, size);
	if (!tab)
	{
		free(lis_tab_index);
		ft_exit_t_push_swap(p);
	}
	ft_sort_int_tab(tab, size);
	median = tab[size / 2];
	free(tab);
	return (median);
}

static int	*ft_create_lis(int**lis_tab, int pile_size, int lis_size,
	int lis_pos)
{
	int	j;
	int	k;
	int	*lis_tab_index;

	j = lis_pos + 1;
	k = -1;
	lis_tab_index = malloc(sizeof(int) * lis_size);
	if (!lis_tab_index)
		return (NULL);
	lis_tab_index[++k] = lis_tab[0][lis_pos];
	while (j < pile_size)
	{
		if (lis_tab[0][lis_pos] < lis_tab[0][j])
		{
			if (lis_tab[1][j] == lis_tab[1][lis_pos] - (k + 1))
			{
				lis_tab_index[++k] = lis_tab[0][j];
			}
		}
		j++;
	}
	return (lis_tab_index);
}

int	*ft_get_biggest_lis(int	**lis_tab, int pile_size, int *lis_size)
{
	int	i;
	int	lis_pos;

	i = -1;
	*lis_size = 0;
	while (++i < pile_size)
	{
		if (lis_tab[1][i] > *lis_size)
		{
			*lis_size = lis_tab[1][i];
			lis_pos = i;
		}
	}
	i = -1;
	return (ft_create_lis(lis_tab, pile_size, *lis_size, lis_pos));
}

int	**ft_init_lis_tab(t_list *pile_a, int pile_size)
{
	t_list	*last;
	int		i;
	int		**lis_tab;

	i = 0;
	lis_tab = malloc(sizeof(int *) * 2);
	if (!lis_tab)
		return (NULL);
	lis_tab[0] = NULL;
	lis_tab[1] = NULL;
	lis_tab[0] = malloc(sizeof(int) * pile_size);
	lis_tab[1] = malloc(sizeof(int) * pile_size);
	if (!lis_tab[0] || !lis_tab[1])
		return (free(lis_tab[0]), free(lis_tab[1]), NULL);
	last = pile_a->prev;
	while (pile_a != last)
	{
		lis_tab[0][i] = pile_a->index;
		lis_tab[1][i] = 1;
		pile_a = pile_a->next;
		i++;
	}
	lis_tab[0][i] = pile_a->index;
	lis_tab[1][i] = 1;
	return (lis_tab);
}
