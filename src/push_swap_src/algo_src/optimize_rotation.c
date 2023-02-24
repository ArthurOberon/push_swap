/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:58:51 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/17 17:59:35 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_optimize_rotation_pile_a_min_max(t_push_swap p, t_best_move *result,
	t_list *dest)
{
	t_list	*tmp;
	int		n;
	int		lst_size;

	tmp = (*p.pile_a);
	n = 0;
	while (tmp != dest)
	{
		tmp = tmp->next;
		n++;
	}
	lst_size = ft_lstsize((*p.pile_a));
	if (n <= (lst_size / 2) || n == 0)
	{
		result->rota_dir_a = n;
	}
	else
	{
		result->rota_dir_a = -(lst_size - n);
	}
	result->size = ft_add_move_size(*result);
}

void	ft_optimize_rotation_pile_a(t_push_swap p, t_best_move *result,
	t_list *tmp_b)
{
	t_list	*tmp;
	int		n;
	int		lst_size;

	tmp = (*p.pile_a);
	n = 0;
	while (!(tmp->prev->index < tmp_b->index && tmp_b->index < tmp->index))
	{
		tmp = tmp->next;
		n++;
	}
	lst_size = ft_lstsize((*p.pile_a));
	if (n <= (lst_size / 2) || n == 0)
	{
		result->rota_dir_a = n;
	}
	else
	{
		result->rota_dir_a = -(lst_size - n);
	}
	result->size = ft_add_move_size(*result);
}

void	ft_optimize_rotation_pile_b(t_push_swap p, t_best_move *result,
	int i)
{
	int		lst_size;

	lst_size = ft_lstsize((*p.pile_b));
	if (i <= (lst_size / 2) || i == 0)
		result->rota_dir_b = i;
	else
	{
		result->rota_dir_b = -(lst_size - i);
	}
	result->size = ft_add_move_size(*result);
}

void	ft_optimize_rotation(t_push_swap p, t_best_move *result,
	t_list *tmp_b, int i)
{
	ft_optimize_rotation_pile_a(p, result, tmp_b);
	ft_optimize_rotation_pile_b(p, result, i);
}
