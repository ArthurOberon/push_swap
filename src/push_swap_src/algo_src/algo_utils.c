/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:51:59 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/16 19:30:22 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_add_move_size(t_best_move result)
{
	result.size = ft_abs(result.rota_dir_a) + ft_abs(result.rota_dir_b)
		+ result.sa + result.sb + 1;
	return (result.size);
}

t_best_move	ft_init_best_move(void)
{
	t_best_move	result;

	result.rota_dir_a = 0;
	result.rota_dir_b = 0;
	result.sa = 0;
	result.sb = 0;
	result.size = 0;
	return (result);
}

t_list	*ft_get_the_n_element_pile(t_list *start, int n)
{
	int		i;
	t_list	*last;

	i = 0;
	last = start->prev;
	while (i < n && start != last)
	{
		start = start->next;
		i++;
	}
	return (start);
}

t_best_move	ft_calcul_push_before_min(t_push_swap p, t_best_move *result)
{
	t_list		*min;

	min = ft_find_element_min(*p.pile_a);
	ft_optimize_rotation_pile_a_min_max(p, result, min);
	return (*result);
}

t_best_move	ft_calcul_push_after_max(t_push_swap p, t_best_move *result)
{
	t_list		*max;

	max = ft_find_element_max(*p.pile_a);
	ft_optimize_rotation_pile_a_min_max(p, result, max->next);
	return (*result);
}
