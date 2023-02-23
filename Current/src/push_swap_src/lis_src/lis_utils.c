/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:20:44 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/23 15:29:21 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**ft_init_lis_tab(t_list *pile_a, int pile_size)
{
	t_list	*last;
	int		i;
	int		**lis_tab;

	i = 0;
	lis_tab = malloc(sizeof(int *) * 2);
	lis_tab[0] = malloc(sizeof(int) * pile_size);
	lis_tab[1] = malloc(sizeof(int) * pile_size);
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

int	find_median(t_list *pile)
{
	int		size;
	int		*tab;

	size = ft_lstsize(pile);
	tab = ft_tab_from_list(&pile, size);
	if (!tab)
		printf("PANIC : PROTECT MALLOC !\n");
	ft_sort_int_tab(tab, size);
	return (tab[size / 2]);
}
