/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_ascending.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:28:06 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/17 18:41:45 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_find_smaller_index(t_list *lst, int current_index, int n)
{
	int		i;
	int		tmp_index;
	t_list	*lst_return;

	i = 0;
	tmp_index = 0;
	lst_return = NULL;
	while (i < n)
	{
		if (lst->index == 0)
		{
			return (lst_return);
		}
		if (lst->index > current_index
			&& (lst->index < tmp_index || tmp_index == 0))
		{
			tmp_index = lst->index;
			lst_return = lst;
		}
		lst = lst->next;
		i++;
	}
	return (lst_return);
}

static void	ft_push_all_between(t_push_swap p, t_list *lst)
{
	t_list	*tmp;

	tmp = *p.pile_a;
	if (lst == tmp->next && tmp->next->index != 0)
	{
		ft_move("sa", p);
		ft_move("ra", p);
	}
	else
	{
		while (tmp != lst && tmp->index != 0)
		{
			ft_move("pb", p);
			tmp = *p.pile_a;
		}
		if (tmp->index != 0)
			ft_move("ra", p);
	}
}

static int	ft_check_obvious(t_push_swap list_pack)
{
	t_list	*tmp;

	if (ft_lstsize(*list_pack.pile_a) == 3)
	{
		ft_3_elements(list_pack);
		return (1);
	}
	tmp = *(list_pack.pile_a);
	if (tmp->index > tmp->next->index)
		ft_move("sa", list_pack);
	return (0);
}

void	ft_get_pile_ascending(t_push_swap list_pack)
{
	int		n;
	int		current_index;
	t_list	*tmp;
	t_list	*tmp_zero;

	if (ft_check_obvious(list_pack) == 1)
		return ;
	n = ft_get_while_number(*list_pack.pile_a);
	current_index = 0;
	tmp = *list_pack.pile_a;
	while (tmp->index != 0)
		tmp = tmp->next;
	ft_move_to_top_pile_a(list_pack, tmp->next);
	tmp_zero = tmp;
	while (tmp->next->index != 0)
	{
		tmp = *list_pack.pile_a;
		tmp = ft_find_smaller_index(tmp, current_index, n);
		if (!tmp)
		{
			ft_push_all_between(list_pack, tmp_zero);
			break ;
		}
		current_index = tmp->index;
		ft_push_all_between(list_pack, tmp);
	}
	tmp = *list_pack.pile_a;
	if (tmp && tmp->index != 0)
	{
		if (tmp->index > 0 && tmp->index < tmp->next->next->index)
			ft_move("sa", list_pack);
		else if (tmp->index > tmp->prev->index)
			ft_move("ra", list_pack);
		else
			ft_move("pb", list_pack);
	}
}
