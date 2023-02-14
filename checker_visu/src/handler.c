/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:08:50 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/14 17:36:17 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
	{
		data->autoplay = 0;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == XK_Left && (*data->p.instructions)->prev)
	{
		printf("prev\n");
		data->autoplay = 0;
		data->direction = -1;
		(*data->p.instructions) = (*data->p.instructions)->prev;
		ft_do_operation(ft_invert_operation((*data->p.instructions)->operation),
			data->p.pile_a, data->p.pile_b);
	}
	if (keysym == XK_Right && (*data->p.instructions)->next)
	{
		printf("next\n");
		data->autoplay = 0;
		data->direction = 1;
		ft_do_operation((*data->p.instructions)->operation, data->p.pile_a,
			data->p.pile_b);
		(*data->p.instructions) = (*data->p.instructions)->next;
	}
	if (keysym >= XK_1 && keysym <= XK_9)
	{
		data->event = 1;
		data->autoplay = 1;
		data->delay = keysym - XK_1;
	}
	if (keysym == XK_space)
	{
		if (data->autoplay == 1)
			data->autoplay = 0;
		else
			data->autoplay = 1;
		if (data->event == 1)
			data->event = 0;
		else
			data->event = 1;
		if (!data->direction)
			data->direction = 1;
		printf("%d\n", data->autoplay);
		ft_autoplay(data);
	}
	render(data);
	printf("Keypress: %d\n", keysym);
	return (0);
}

// int	handle_keypress(int keysym, t_data *data)
// {
// 	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
// 	{
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		data->win_ptr = NULL;
// 	}
// 	if (keysym == XK_Left)
// 	{
// 		data->event = 1;
// 		data->autoplay = 0;
// 		data->direction = -1;
// 	}
// 	if (keysym == XK_Right)
// 	{
// 		data->event = 1;
// 		data->autoplay = 0;
// 		data->direction = 1;
// 	}
// 	if (keysym >= XK_1 && keysym <= XK_9)
// 	{
// 		data->event = 1;
// 		data->autoplay = 1;
// 		data->delay = keysym - XK_1;
// 	}
// 	if (keysym == XK_space)
// 	{
// 		if (data->autoplay == 1)
// 			data->autoplay = 0;
// 		else
// 			data->autoplay = 1;
// 		if (data->event == 1)
// 			data->event = 0;
// 		else
// 			data->event = 1;
// 		if (!data->direction)
// 			data->direction = 1;
// 	}
// 	render(data);
// 	printf("Keypress: %d\n", keysym);
// 	return (0);
// }
