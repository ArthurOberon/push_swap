/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best_move_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:44:41 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/16 19:28:00 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_best_move_sr(t_push_swap p, t_best_move fastest)
{
	int	i;

	i = 0;
	if (fastest.sa == 1 && fastest.rota_dir_b != 0)
	{
		while (i++ < ft_abs(fastest.rota_dir_b))
		{
			if (fastest.rota_dir_b < 0)
				ft_move("rrb", p);
			else
				ft_move("rb", p);
		}
		ft_move("pa", p);
		ft_move("sa", p);
		return (2);
	}
	return (0);
}
