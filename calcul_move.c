/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:12:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/01 19:39:40 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_optimize_rotation(t_list **lst, t_list *lst_destination)
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

void	ft_calcul_move(t_push_swap list_pack)
{

}
