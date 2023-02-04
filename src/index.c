/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:45:36 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/04 11:55:42 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_tab_from_list(t_list **lst, int size)
{
	int		i;
	int		*tab;
	t_list	*tmp;
	t_list	*last;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	last = (*lst)->prev;
	tmp = last->next;
	while (tmp != last)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	tab[i] = tmp->value;
	return (tab);
}

static void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	ft_index_from_tab(t_list *lst, int	*tab, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (i < size)
	{
		while (tmp->value != tab[i])
			tmp = tmp->next;
		tmp->index = i;
		tmp = lst;
		i++;
	}
}

static void	ft_get_index_max(t_list *lst)
{
	t_list	*last;
	t_list	*max;

	last = lst->prev;
	max = last;
	while (lst != last)
	{
		if (lst->index > max->index)
			max = lst;
		lst = lst->next;
	}
}

void	ft_init_index(t_list **lst)
{
	int	*tab;
	int	size;

	size = ft_lstsize(*lst);
	tab = ft_tab_from_list(lst, size);
	if (!tab)
	{
		ft_lstclear(lst);
		exit(EXIT_FAILURE);
	}
	ft_sort_int_tab(tab, size);
	ft_index_from_tab(*lst, tab, size);
	free(tab);
}
