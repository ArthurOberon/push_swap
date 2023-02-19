/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:45:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/19 13:22:28 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(char *operation, t_push_swap list_pack)
{
	ft_do_operation(operation, list_pack.pile_a, list_pack.pile_b);
	if (ft_add_instruction(operation, list_pack.instructions) == -1)
	{
		ft_lstclear(list_pack.pile_a);
		ft_lstclear(list_pack.pile_b);
		ft_lstclear_instruction(list_pack.instructions);
		ft_putstr_fd("Error with a malloc\n", 2);
		exit (EXIT_FAILURE);
	}
}
