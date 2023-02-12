/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:10:33 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/12 19:04:13 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	render(t_data *data)
{
	t_rect	rect;

	if (!data->win_ptr)
		return (1);
	render_background(&data->img, 0xFFFFFFF);
	rect.height = 1;
	rect.width = 1000;
	rect.y = data->pop;
	rect.x = WINDOW_WIDTH / 4;
	render_list(&data->img, &rect, data->lst, data->value_max);
	rect.x += WINDOW_WIDTH / 2;
	render_list(&data->img, &rect, data->lst, data->value_max);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	return (0);
}

// int	render(t_data *data)
// {
// 	if (data->win_ptr == NULL)
// 		return (1);
// 	render_background(&data->img, 0xFFFFFFF);
// 	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
// 		100, 100, 0xFF00});
// 	render_rect(&data->img, (t_rect){0, 0, 100, 100, 0xFF0000});
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
// 		0, 0);
// 	return (0);
// }
