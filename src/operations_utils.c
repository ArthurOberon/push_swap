/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:45:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/01 19:13:40 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(char *operation, t_push_swap list_pack)
{
	ft_do_operation(operation, list_pack.pile_a, list_pack.pile_b);
	ft_print_piles(operation, list_pack);
	// printf("%s\n", operation);
	ft_add_instruction(operation, list_pack.instructions);
}
