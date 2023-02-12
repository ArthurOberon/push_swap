/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:08:50 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/12 15:24:37 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape || keysym == XK_Q || keysym == XK_q)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}
