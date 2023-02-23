/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:46:13 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/23 16:45:25 by aoberon          ###   ########.fr       */
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

static int	*ft_create_lis(int**lis_tab, int pile_size, int lis_size,
	int lis_pos)
{
	int	j;
	int	k;
	int	*lis_tab_index;

	j = lis_pos + 1;
	k = -1;
	lis_tab_index = malloc(sizeof(int) * lis_size);
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

static int	*ft_get_lis(int	**lis_tab, int pile_size, int *lis_size)
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

static void	ft_apply_lis(t_push_swap p, int	*lis_tab_index, int lis_size)
{
	t_list	*pile_a;
	t_list	*last;
	int		median;

	pile_a = *p.pile_a;
	last = pile_a->prev;
	median = find_median(*p.pile_a);
	while (pile_a != last)
	{
		if (ft_int_tabchr(lis_tab_index, lis_size, pile_a) == 1)
			ft_move("ra", p);
		else
		{
			ft_move("pb", p);
			if ((*p.pile_b)->index <= median && (*p.pile_b) != (*p.pile_b)->next)
				ft_move("rb", p);
		}
		pile_a = *p.pile_a;
	}
	if (ft_int_tabchr(lis_tab_index, lis_size, pile_a) == 0)
	{
		if ((pile_a->index > pile_a->prev->index && pile_a->index < pile_a->next->index) || pile_a->index == 0)
			return ;
		if (pile_a->index < pile_a->next->index && pile_a->prev == ft_find_element_max(pile_a))
			return ;
		else if (pile_a->index > pile_a->next->index
			&& pile_a->index < pile_a->next->next->index)
			ft_move("sa", p);
		else
		{
			ft_move("pb", p);
			if ((*p.pile_b)->index <= median)
				ft_move("rb", p);
		}
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
	lis_tab = ft_set_lis(lis_tab, pile_size);
	lis_tab_index = ft_get_lis(lis_tab, pile_size, &lis_size);
	ft_apply_lis(p, lis_tab_index, lis_size);
}
