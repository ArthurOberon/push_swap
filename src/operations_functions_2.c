/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_functions_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:45:19 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/30 10:55:59 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(char *operation, t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	ft_do_operation(operation, lst_a, lst_b);
	ft_print_piles(operation, lst_a, lst_b);
	// ft_add_instruction(operation, lst_instruction);
}
