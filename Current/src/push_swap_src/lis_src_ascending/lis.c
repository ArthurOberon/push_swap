/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:46:13 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/22 18:36:48 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_tab_int_lis_finale(int *lis_tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		printf("[%d]	", lis_tab[i]);
	printf("\n\n");
}

static void	ft_print_tab_int_lis(int **lis_tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		printf("[%d]	", lis_tab[0][i]);
	printf("\n");
	i = -1;
	while (++i < size)
		printf("[%d]	", lis_tab[1][i]);
	printf("\n\n");
}

static int	**ft_init_lis_tab(t_list *pile_a, int size)
{
	t_list	*last;
	int		i;
	int		**lis_tab;

	i = 0;
	lis_tab = malloc(sizeof(int *) * 2);
	lis_tab[0] = malloc(sizeof(int) * size);
	lis_tab[1] = malloc(sizeof(int) * size);
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

static int	**ft_set_lis(int **lis_tab, int size)
{
	int	j;
	int	i;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (lis_tab[0][i] > lis_tab[0][j])
			{
				if (lis_tab[1][i] < lis_tab[1][j] + 1)
					lis_tab[1][i] = lis_tab[1][j] + 1;
			}
			j++;
		}
		printf("i = %d\n", i);
		ft_print_tab_int_lis(lis_tab, size);
		i++;
	}	
	return (lis_tab);
}

static int	*ft_create_lis(int**lis_tab, int lis_size, int lis_pos)
{
	int	i;
	int	j;
	int	k;
	int	*lis_tab_index;

	lis_tab[1][lis_pos] = 1;
	i = -1;
	j = 0;
	k = -1;
	lis_tab_index = malloc(sizeof(int) * lis_size);
	while (++i < lis_pos)
	{
		if (lis_tab[0][i] < lis_tab[0][lis_pos])
		{
			if (lis_tab[1][i] + 1 > lis_tab[1][lis_pos])
			{
				lis_tab[1][lis_pos]++;
				lis_tab_index[++k] = lis_tab[0][j];
			}
		}
		j++;
	}
	lis_tab_index[++k] = lis_tab[0][j];
	ft_print_tab_int_lis_finale(lis_tab_index, lis_size);
	return (lis_tab_index);
}

static int	*ft_get_lis(int	**lis_tab, int size, int *lis_size)
{
	int	i;
	int	lis_pos;

	i = -1;
	*lis_size = 0;
	while (++i < size)
	{
		if (lis_tab[1][i] > *lis_size)
		{
			*lis_size = lis_tab[1][i];
			lis_pos = i;
		}
	}
	i = -1;
	printf("LIS = %d & LIS_POS = %d\n", *lis_size, lis_pos);
	return (ft_create_lis(lis_tab, *lis_size, lis_pos));
}

static int	ft_int_tabchr(int *tab, int size, t_list *tmp)
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

static void	ft_apply_lis(t_push_swap p, int	*lis_tab_index, int size)
{
	t_list	*pile_a;
	t_list	*last;

	pile_a = *p.pile_a;
	last = pile_a->prev;
	while (pile_a != last)
	{
		if (ft_int_tabchr(lis_tab_index, size, pile_a) == 1)
			ft_move("ra", p);
		else
			ft_move("pb", p);
		pile_a = *p.pile_a;
	}
	if (ft_int_tabchr(lis_tab_index, size, pile_a) == 0)
		ft_move("pb", p);
}


void	ft_lis(t_push_swap p)
{
	int	pile_size;
	int	lis_size;
	int	**lis_tab;
	int	*lis_tab_index;

	ft_print_piles("START", p);
	pile_size = ft_lstsize(*p.pile_a);
	printf("		CREATE LIS\n\n");
	lis_tab = ft_init_lis_tab(*p.pile_a, pile_size);
	ft_print_tab_int_lis(lis_tab, pile_size);
	printf("		FIND LIS\n\n");
	lis_tab = ft_set_lis(lis_tab, pile_size);
	lis_tab_index = ft_get_lis(lis_tab, pile_size, &lis_size);
	ft_apply_lis(p, lis_tab_index, lis_size);
	ft_print_piles("END", p);
}
