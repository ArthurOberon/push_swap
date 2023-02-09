/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:33:23 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/09 14:14:15 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_fastest_instruction(t_push_swap p, t_instruction *fastest,
			t_instruction **tmp)
{
	*tmp = NULL;
	ft_lstadd_back_instruction(p.instructions, fastest);
	while (fastest != NULL)
	{
		ft_do_operation(fastest->operation, p.pile_a,
			p.pile_b);
		fastest = fastest->next;
	}
}

int	ft_calcul_move_helper_1(t_push_swap p, t_instruction **tmp, int i)
{
	int	tmp_size;

	*tmp = NULL;
	ft_optimize_move(p, ft_get_the_n_element_pile(*p.pile_b, i), tmp);
	tmp_size = ft_lstsize_instruction(*tmp);
	return (tmp_size);
}

void	ft_calcul_move_helper_2(t_push_swap p, t_instruction *tmp, int tmp_size,
	int i)
{
	ft_go_back_to(p, tmp, tmp_size, i);
	ft_lstclear_instruction(&tmp);
}
