/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:45:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/04 10:30:08 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(char *operation, t_push_swap list_pack)
{
	ft_do_operation(operation, list_pack.pile_a, list_pack.pile_b);
	ft_add_instruction(operation, list_pack.instructions);
}

void	ft_move_temporary(char *operation, t_push_swap list_pack,
	t_instruction **lst_instruction)
{
	ft_do_operation(operation, list_pack.pile_a, list_pack.pile_b);
	ft_add_instruction(operation, lst_instruction);
}
