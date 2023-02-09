/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:33:23 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/09 08:49:45 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instruction	*ft_calcul_move_helper(t_push_swap p, t_instruction *fastest,
	t_instruction *tmp, int i)
{
	int				fastest_size;
	int				tmp_size;

	fastest_size = 0;
	ft_optimize_move(p, ft_get_the_n_element_pile(*p.pile_b, i), &tmp);
	tmp_size = ft_lstsize_instruction(tmp);
	if (tmp_size == 1)
	{
		ft_lstclear_instruction(&fastest);
		fastest = tmp;
		ft_go_back_to(p, tmp, tmp_size, i);
		return (fastest);
	}
	if (fastest_size > tmp_size || fastest_size == 0)
	{
		ft_lstclear_instruction(&fastest);
		fastest = tmp;
		ft_go_back_to(p, tmp, tmp_size, i);
	}
	else
	{
		ft_go_back_to(p, tmp, tmp_size, i);
		ft_lstclear_instruction(&tmp);
	}
	return (fastest);
}
