/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_ascending.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:28:06 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/10 15:18:29 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_find_smaller_index(t_list *lst, int current_index)
{
	int		i;
	int		tmp_index;
	t_list	*lst_return;

	i = 0;
	tmp_index = current_index;
	lst_return = NULL;
	while (i < 3)
	{
		printf("? %d == 0 ?\n", lst->index);
		if (lst->index == 0)
		{
			printf("YES\n");
			return (lst_return);
		}
		printf("? %d > %d ?\n", lst->index, current_index);
		if (lst->index > current_index && lst->index > tmp_index)
		{
			printf("YES\n");
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
	if (lst == tmp->next)
	{
		ft_move("sa", p);
	}
	else
	{
		while (tmp != lst)
		{
			ft_move("pb", p);
			tmp = *p.pile_a;
		}
	}
}

void	ft_get_pile_ascending(t_push_swap list_pack)
{
	int		current_index;
	t_list	*tmp;

	current_index = 0;
	tmp = *list_pack.pile_a;
	while (tmp->index != 0)
		tmp = tmp->next;
	ft_move_to_top_pile_a(list_pack, tmp->next);
	while (tmp->next->index != 0)
	{
		tmp = *list_pack.pile_a;
		tmp = ft_find_smaller_index(tmp, current_index);
		if (!tmp)
		{
			printf("break\n");
			break ;
		}
		current_index = tmp->index;
		printf("tmp = %d\n", tmp->index);
		ft_push_all_between(list_pack, tmp);
	}
}
