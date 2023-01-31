/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:48:12 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/31 16:14:48 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_get_ascendent_sequence(t_list **lst)
{
	t_list	*coordonate[2];
	t_list	*coordonate_tmp[2];
	int		i;
	int		size;

	i = -1;
	size = ft_lstsize(lst);
	coordonate[0] = *lst;
	coordonate[1] = *lst;
	coordonate_tmp[0] = *lst;
	coordonate_tmp[1] = *lst;
	while (++i < size)
	{
		if (coordonate[1]->value > coordonate[1]->next->value)
		{
			if (ft_calcul_gap(coordonate[0], coordonate[1],
					coordonate_tmp[0], coordonate_tmp[1]))
			{
				coordonate_tmp[0] = coordonate[0];
				coordonate_tmp[1] = coordonate[1];
			}
			ft_go_to_element(&coordonate[0], coordonate[1]->next);
		}
		coordonate[1] = coordonate[1]->next;
	}
	printf("RESULT = value : [%d] | index : [%d]\n", coordonate_tmp[0]->value, coordonate_tmp[0]->index);
	printf("RESULT = value : [%d] | index : [%d]\n", coordonate_tmp[1]->value, coordonate_tmp[1]->index);
	return (coordonate);
}

static void	ft_push_top(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, t_list *coordonate)
{
	t_list	*tmp;

	tmp = *lst_a;
	while (tmp != coordonate)
	{
		if ((*lst_a)->index < coordonate->index)
			ft_move("ra", lst_a, lst_b, lst_instruction);
		else
			ft_move("pa", lst_a, lst_b, lst_instruction);
		tmp = tmp->next;
	}
}

static void	ft_push_bottom(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, t_list *coordonate)
{
	t_list	*tmp;

	tmp = *lst_a;
	while (tmp != coordonate)
	{
		if ((*lst_a)->index > coordonate->index)
			ft_move("ra", lst_a, lst_b, lst_instruction);
		else
			ft_move("pa", lst_a, lst_b, lst_instruction);
		tmp = tmp->next;
	}
}

void	ft_get_order(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	t_list	*coordonate[2];

	ft_print_piles("BEFORE PUSH", lst_a, lst_b);
	*coordonate = ft_get_ascendent_sequence(lst_a);
	printf("COORDONATE = [%d] | [%d]\n", coordonate[0]->value, coordonate[1]->value);
	// ft_push_top(lst_a, lst_b, lst_instruction, coordonate[0]);
	// ft_print_piles("PUSH TOP", lst_a, lst_b);
	// ft_push_bottom(lst_a, lst_b, lst_instruction, coordonate[1]);
	// ft_print_piles("PUSH BOTTOM", lst_a, lst_b);
}
