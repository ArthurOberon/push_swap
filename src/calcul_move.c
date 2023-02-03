/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:12:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/03 17:49:46 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_optimize_rotation(t_list **lst, t_list *lst_destination)
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
	if (r_number <= rr_number)
		return (OPTIMIZE_R);
	return (OPTIMIZE_RR);
}

static t_instruction	*ft_optimize_rotation(t_push_swap list_pack,
	t_instruction **tmp_instruction)
{
	t_list			**tmp_a;
	t_list			*tmp;
	int				index_tmp;

	tmp_a = list_pack.pile_a;
	tmp = (*tmp_a);
	index_tmp = (*list_pack.pile_b)->index;
	while (!(tmp->prev->index < index_tmp && index_tmp < tmp->index))
	{
		tmp = tmp->next;
	}
	if (ft_find_optimize_rotation(list_pack.pile_a, tmp) == OPTIMIZE_R)
	{
		while ((*tmp_a) != tmp)
			ft_move_temporary("ra", list_pack, tmp_instruction);
		ft_move_temporary("pa", list_pack, tmp_instruction);
		return (*tmp_instruction);
	}
	while ((*tmp_a) != tmp)
		ft_move_temporary("rra", list_pack, tmp_instruction);
	ft_move_temporary("pa", list_pack, tmp_instruction);
	return (*tmp_instruction);
}

static t_instruction	*ft_optimize_move(t_push_swap list_pack,
	t_list *element_to_go)
{
	t_list			*pile_a;
	t_list			*pile_b;
	t_instruction	*tmp_instruction;

	pile_a = *list_pack.pile_a;
	pile_b = *list_pack.pile_b;
	tmp_instruction = malloc(sizeof(t_instruction));
	if (!tmp_instruction)
		printf("Panic ! Do a function to exit and free\n");
	tmp_instruction = NULL;
	ft_move_to_top_pile_b(list_pack, element_to_go, &tmp_instruction);
	pile_b = *list_pack.pile_b;
	if (pile_b->index == 0)
		ft_push_after_max(list_pack, &tmp_instruction);
	if (pile_b->is_max == 1)
		ft_push_after_min(list_pack, &tmp_instruction);
	if (pile_a->index < pile_b->index && pile_b->index < pile_a->next->index)
	{
		ft_move_temporary("pa", list_pack, &tmp_instruction);
		ft_move_temporary("sa", list_pack, &tmp_instruction);
		return (tmp_instruction);
	}
	else if (pile_b->index > pile_a->prev->index
		&& pile_a->index > pile_b->index)
	{
		ft_move_temporary("pa", list_pack, &tmp_instruction);
		// ft_move_temporary("ra", list_pack, &tmp_instruction);
		return (tmp_instruction);
	}
	return (ft_optimize_rotation(list_pack, &tmp_instruction));
}

static void	ft_go_back_to(t_push_swap list_pack, t_instruction *lst_instruction,
	int move_number, int n)
{
	int				i;
	int				j;
	char			*move;
	t_instruction	*tmp_instruction;

	j = 0;
	while (move_number > 0)
	{
		tmp_instruction = lst_instruction;
		i = 1;
		while (i < move_number)
		{
			tmp_instruction = tmp_instruction->next;
			i++;
		}
		move = tmp_instruction->invert_operation;
		ft_do_operation(move, list_pack.pile_a, list_pack.pile_b);
		move_number--;
	}
}

void	ft_calcul_move(t_push_swap list_pack)
{
	int				fastest_size;
	int				tmp_size;
	int				i;
	t_instruction	*fastest_instruction;
	t_instruction	*tmp_instruction;

	i = 0;
	fastest_size = 0;
	fastest_instruction = NULL;
	while (i < 5)
	{
		printf("I = [%d]\n", i);
		tmp_instruction = ft_optimize_move(list_pack,
				ft_get_the_n_element_pile(*list_pack.pile_b, i));
		tmp_size = ft_lstsize_instruction(tmp_instruction);
		if (tmp_size > fastest_size)
		{
			ft_lstclear_instruction(&fastest_instruction);
			fastest_instruction = tmp_instruction;
			fastest_size = tmp_size;
			ft_go_back_to(list_pack, tmp_instruction, tmp_size, i);
		}
		else
		{
			ft_go_back_to(list_pack, tmp_instruction, tmp_size, i);
			ft_lstclear_instruction(&tmp_instruction);
		}
		tmp_instruction = NULL;
		i++;
	}
	ft_lstadd_back_instruction(list_pack.instructions, fastest_instruction);
	while (fastest_instruction != NULL)
	{
		ft_do_operation(fastest_instruction->operation, list_pack.pile_a,
			list_pack.pile_b);
		fastest_instruction = fastest_instruction->next;
	}
}
