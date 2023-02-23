/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:53:38 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/19 15:48:30 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// printf("ra = %d\nrb = %d\nsa = %d\nsb = %d\nsize = %d\n", result.rota_dir_a,
	// result.rota_dir_b, result.sa, result.sb, result.size);

t_best_move	ft_calcul_move_simple(t_push_swap p, t_list *tmp_b, int i)
{
	t_best_move	result;
	t_list		*tmp;

	result = ft_init_best_move();
	tmp = (*p.pile_a);
	ft_optimize_rotation_pile_b(p, &result, i);
	if (tmp_b->index < ft_find_element_min(tmp)->index)
		return (ft_calcul_push_after_max(p, &result));
	else if (tmp_b->index > ft_find_element_max(tmp)->index)
		return (ft_calcul_push_before_min(p, &result));
	else if (tmp->index < tmp_b->index && tmp_b->index < tmp->next->index)
	{
		result.sa = 1;
		result.size = ft_add_move_size(result);
	}
	else if (tmp_b->index > tmp->prev->index && tmp->index > tmp_b->index)
		result.size = ft_add_move_size(result);
	else
		ft_optimize_rotation_pile_a(p, &result, tmp_b);
	return (result);
}

t_best_move	ft_calcul_move(t_push_swap p, int i)
{
	t_best_move	result;
	t_list		*tmp_b;

	tmp_b = ft_get_the_n_element_pile((*p.pile_b), i);
	result = ft_calcul_move_simple(p, tmp_b, i);
	return (result);
}

void	ft_do_best_move(t_push_swap p, t_best_move fastest)
{
	int	check;

	check = 0;
	check = ft_do_best_move_s(p, fastest);
	if (check == 2)
		return ;
	if (check == 0)
		check = ft_do_best_move_sr(p, fastest);
	if (check == 2)
		return ;
	if (check == 0)
		check = ft_do_best_move_rr(p, fastest);
	if (check == 0)
		check = ft_do_best_move_rrr(p, fastest);
	if (check == 0)
	{
		ft_do_best_move_ra(p, fastest);
		ft_do_best_move_rb(p, fastest);
	}
	ft_move("pa", p);
}

void	ft_find_best_move(t_push_swap p)
{
	t_best_move	fastest;
	t_best_move	tmp;
	int			i;

	i = 0;
	fastest.size = 0;
	while (i < ft_lstsize((*p.pile_b)))
	{
		tmp = ft_calcul_move(p, i);
		if (fastest.size > tmp.size || fastest.size == 0 || tmp.size == 1)
		{
			fastest = tmp;
			if (tmp.size == 1)
				break ;
		}
		i++;
	}
	ft_do_best_move(p, fastest);
}
