/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:08:50 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/17 17:22:45 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

int	handle_keypress(int keysym, t_data *data)
{
	int	freeze;

	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
	{
		data->autoplay = 0;
		data->stop_autoplay = 0;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		return (1);
	}
	if (keysym == XK_Left && (*data->p.instructions)->prev)
	{
		data->autoplay = 0;
		data->stop_autoplay = 0;
		data->direction = -1;
		(*data->p.instructions) = (*data->p.instructions)->prev;
		ft_do_operation(ft_invert_operation((*data->p.instructions)->operation),
			data->p.pile_a, data->p.pile_b);
		render(data);
	}
	if (keysym == XK_Right && (*data->p.instructions)->next)
	{
		data->autoplay = 0;
		data->stop_autoplay = 0;
		data->direction = 1;
		ft_do_operation((*data->p.instructions)->operation, data->p.pile_a,
			data->p.pile_b);
		(*data->p.instructions) = (*data->p.instructions)->next;
		render(data);
	}
	if (keysym >= XK_1 && keysym <= XK_9)
	{
		data->autoplay = 1;
		data->delay = keysym - XK_1;
		return (1);
	}
	if (keysym == XK_space || keysym == XK_0)
	{
		if (data->autoplay == 1)
			data->autoplay = 0;
		else
			data->autoplay = 1;
		if (!data->direction)
			data->direction = 1;
		return (1);
	}
	return (0);
}
