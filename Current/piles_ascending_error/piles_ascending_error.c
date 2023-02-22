/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_ascending_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:28:06 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/22 16:02:29 by aoberon          ###   ########.fr       */
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

static int	ft_check_obvious(t_push_swap p)
{
	t_list	*tmp;

	if (ft_lstsize(*p.pile_a) == 3)
	{
		ft_3_elements(p);
		return (1);
	}
	tmp = *(p.pile_a);
	if (tmp->index > tmp->next->index)
		ft_move("sa", p);
	return (0);
}

// void	ft_get_pile_ascending(t_push_swap p, t_list *tmp_stop)
// {
// 	int		n;
// 	int		current_index;
// 	t_list	*tmp;
// 	t_list	*tmp_zero;

// 	if (ft_check_obvious(p) == 1)
// 		return ;
// 	n = ft_get_while_number(*p.pile_a);
// 	current_index = 0;
// 	tmp = *p.pile_a;
// 	tmp_zero = tmp;
// 	while (tmp_zero->index != 0)
// 		tmp_zero = tmp_zero->next;
// 	while (tmp->next != tmp_stop)
// 	{
// 		ft_print_piles("OSKOUR", p);
// 		tmp = *p.pile_a;
// 		tmp = ft_find_smaller_index(tmp, current_index, n);
// 		if (!tmp)
// 		{
// 			ft_push_all_between(p, tmp_zero);
// 			printf("break\n");
// 			break ;
// 		}
// 		current_index = tmp->index;
// 		ft_push_all_between(p, tmp);
// 	}
// 	tmp = *p.pile_a;
// 	ft_print_piles("OSKOUR LAST - 1", p);
// 	// if (tmp && tmp != tmp_stop)
// 	// {
// 	// 	if (tmp->index > 0 && tmp->index < tmp->next->next->index)
// 	// 		ft_move("sa", p);
// 	// 	else if (tmp->index > tmp->prev->index)
// 	// 		ft_move("ra", p);
// 	// 	else
// 	// 		ft_move("pb", p);
// 	// }
// 	ft_print_piles("OSKOUR LAST", p);
// }

void	ft_get_pile_ascending_e(t_push_swap p)
{
	int		n;
	int		current_index;
	t_list	*tmp;
	t_list	*tmp_zero;

	if (ft_check_obvious(p) == 1)
		return ;
	n = ft_get_while_number(*p.pile_a);
	current_index = 0;
	tmp = *p.pile_a;
	while (tmp->index != 0)
		tmp = tmp->next;
	ft_move_to_top_pile_a(p, tmp->next);
	tmp_zero = tmp;
	while (tmp->next->index != 0)
	{
		tmp = *p.pile_a;
		tmp = ft_find_smaller_index(tmp, current_index, n);
		if (!tmp)
		{
			ft_push_all_between(p, tmp_zero);
			break ;
		}
		current_index = tmp->index;
		ft_push_all_between(p, tmp);
	}
	tmp = *p.pile_a;
	if (tmp && tmp->index != 0)
	{
		if (tmp->index > 0 && tmp->index < tmp->next->next->index)
			ft_move("sa", p);
		else if (tmp->index > tmp->prev->index)
			ft_move("ra", p);
		else
			ft_move("pb", p);
	}
}
