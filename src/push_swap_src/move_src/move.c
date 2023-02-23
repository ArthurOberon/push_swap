/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:45:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/22 20:59:28 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(char *operation, t_push_swap p)
{
	ft_do_operation(operation, p.pile_a, p.pile_b);
	if (ft_add_instruction(operation, p.instructions) == -1)
	{
		ft_lstclear(p.pile_a);
		ft_lstclear(p.pile_b);
		ft_lstclear_instruction(p.instructions);
		ft_putstr_fd("Error with a malloc\n", 2);
		exit (EXIT_FAILURE);
	}
}

int	ft_check_obvious(t_push_swap p)
{
	t_list	*tmp;

	if (ft_is_ascending(*p.pile_a) == 1)
	{
		ft_lstclear(p.pile_a);
		ft_lstclear_instruction(p.instructions);
		exit (EXIT_SUCCESS);
	}
	if (ft_lstsize(*p.pile_a) == 3)
	{
		ft_3_elements(p);
		return (1);
	}
	tmp = *(p.pile_a);
	if (tmp->index == tmp->next->index)
		ft_move("sa", p);
	return (0);
}
