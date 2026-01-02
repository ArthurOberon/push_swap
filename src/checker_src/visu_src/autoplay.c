/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autoplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:33:02 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/17 17:09:27 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

int	ft_autoplay(t_data *data)
{
	t_instruction	*tmp;
	int				*delay_tab_u;

	delay_tab_u = (int [9]){3000000, 2000000, 1000000, 500000, 250000,
		125000, 62500, 31250, 15625};
	tmp = (*data->p.instructions);
	if (data->autoplay == 1)
	{
		if (!tmp->prev && data->stop_autoplay == 0)
		{
			data->direction = 1;
			data->stop_autoplay = 1;
		}
		else if (!tmp->prev && data->stop_autoplay == 1)
		{
			data->autoplay = 0;
			data->stop_autoplay = 0;
			return (1);
		}
		if (tmp->operation[0] == 'N' && data->stop_autoplay == 0)
		{
			data->direction = -1;
			data->stop_autoplay = 1;
		}
		else if (tmp->operation[0] == 'N' && data->stop_autoplay == 1)
		{
			data->autoplay = 0;
			data->stop_autoplay = 0;
			return (1);
		}
		if (data->direction == 1 && tmp->next)
		{
			ft_do_operation(tmp->operation, data->p.pile_a, data->p.pile_b);
			tmp = tmp->next;
		}
		else if (data->direction == -1 && tmp->prev)
		{
			tmp = tmp->prev;
			ft_do_operation(ft_invert_operation(tmp->operation), data->p.pile_a,
				data->p.pile_b);
		}
		usleep(delay_tab_u[data->delay]);
		(*data->p.instructions) = tmp;
		render(data);
	}
	return (0);
}
