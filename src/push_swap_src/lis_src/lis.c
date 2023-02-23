/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:46:13 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/23 20:14:24 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	**ft_set_lis(int **lis_tab, int size)
{
	int	j;
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		j = i + 1;
		while (j < size)
		{
			if (lis_tab[0][i] < lis_tab[0][j])
			{
				if (lis_tab[1][i] < lis_tab[1][j] + 1)
					lis_tab[1][i] = lis_tab[1][j] + 1;
			}
			j++;
		}
		i--;
	}	
	return (lis_tab);
}

static void	ft_apply_lis_helper(t_push_swap p, t_list *pile_a, int median)
{
	if ((pile_a->index > pile_a->prev->index
			&& pile_a->index < pile_a->next->index) || pile_a->index == 0)
	{
		return ;
	}
	if (pile_a->index < pile_a->next->index
		&& pile_a->prev == ft_find_element_max(pile_a))
	{
		return ;
	}
	else if (pile_a->index > pile_a->next->index
		&& pile_a->index < pile_a->next->next->index)
	{
		ft_move("sa", p);
	}
	else
	{
		ft_move("pb", p);
		if ((*p.pile_b)->index <= median)
			ft_move("rb", p);
	}
}

static void	ft_apply_lis(t_push_swap p, int	*lis_tab_index, int lis_size)
{
	t_list	*pile_a;
	t_list	*last;
	int		median;

	pile_a = *p.pile_a;
	last = pile_a->prev;
	median = find_median(p, lis_tab_index);
	while (pile_a != last)
	{
		if (ft_int_tabchr(lis_tab_index, lis_size, pile_a) == 1)
			ft_move("ra", p);
		else
		{
			ft_move("pb", p);
			if ((*p.pile_b)->index <= median
				&& (*p.pile_b) != (*p.pile_b)->next)
				ft_move("rb", p);
		}
		pile_a = *p.pile_a;
	}
	if (ft_int_tabchr(lis_tab_index, lis_size, pile_a) == 0)
	{
		ft_apply_lis_helper(p, pile_a, median);
	}
}

void	ft_lis(t_push_swap p)
{
	int	pile_size;
	int	lis_size;
	int	**lis_tab;
	int	*lis_tab_index;

	pile_size = ft_lstsize(*p.pile_a);
	lis_tab = ft_init_lis_tab(*p.pile_a, pile_size);
	if (!lis_tab)
	{
		ft_exit_t_push_swap(p);
	}
	lis_tab = ft_set_lis(lis_tab, pile_size);
	lis_tab_index = ft_get_biggest_lis(lis_tab, pile_size, &lis_size);
	free(lis_tab[0]);
	free(lis_tab[1]);
	free(lis_tab);
	if (!lis_tab_index)
	{
		ft_exit_t_push_swap(p);
	}
	ft_apply_lis(p, lis_tab_index, lis_size);
	free(lis_tab_index);
}
