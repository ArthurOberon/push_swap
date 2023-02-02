/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:12:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/02 14:43:20 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_optimize_rotation(t_list **lst, t_list *lst_destination)
{
	int		r_number;
	int		rr_number;
	t_list	*tmp;

	tmp = *lst;
	r_number = 0;
	rr_number = 0;
	while (tmp != lst_destination)
	{
		r_number++;
		tmp = tmp->next;
	}
	tmp = *lst;
	while (tmp != lst_destination)
	{
		rr_number++;
		tmp = tmp->prev;
	}
	if (r_number >= rr_number)
		return (OPTIMIZE_R);
	return (OPTIMIZE_RR);
}

static t_instruction	**ft_optimize_rotation(t_push_swap list_pack)
{
	t_list			**tmp_a;
	t_list			*tmp;
	t_instruction	*instruction_tmp;

	instruction_tmp = NULL;
	tmp_a = list_pack.pile_a;
	tmp = *list_pack.pile_a;
	while ((*tmp_a)->index < tmp->index && tmp->index < (*tmp_a)->index)
		tmp = tmp->next;
	ft_move("pa", list_pack);
	if (ft_find_optimize_rotation(list_pack.pile_a, tmp) == OPTIMIZE_R)
	{
		while ((*tmp_a) != tmp)
		{
			ft_move("ra", list_pack);
			ft_add_instruction("ra", &instruction_tmp);
		}
		return (&instruction_tmp);
	}
	while ((*tmp_a) != tmp)
	{
		ft_move("rra", list_pack);
		ft_add_instruction("rra", &instruction_tmp);
	}
	return (&instruction_tmp);
}

static t_instruction	**ft_optimize_move(t_push_swap list_pack)
{
	t_list			*pile_a;
	t_list			*pile_b;
	t_instruction	*instruction_tmp;

	pile_a = *list_pack.pile_a;
	pile_b = *list_pack.pile_b;
	inl
	if (pile_a->index < pile_b->index && pile_b->index < pile_a->next->index)
	{
		ft_move("pa", list_pack);
		ft_move("sa", list_pack);
		return (2);
	}
	else if (pile_b->index > pile_a->prev->index)
	{
		ft_move("pa", list_pack);
		ft_move("ra", list_pack);
		return (2);
	}
	else
		return (ft_optimize_rotation(list_pack));
}

// Where is the t_instruction to save the faster move sequence ?
void	ft_calcul_move(t_push_swap list_pack)
{
	int	quickest_move;
	int	tmp_move;
	int	i;

	i = 0;
	tmp_move = 0;
	quickest_move = 0;
	while (i < 5)
	{
		tmp_move = ft_optimize_move(list_pack);
		if (tmp_move > quickest_move)
			quickest_move = tmp_move;
	}
}
