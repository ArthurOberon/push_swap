/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:45:36 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/12 19:07:10 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

// int	render_list(t_data **data, t_rect rect)
// {
// 	t_list	*tmp;
// 	int		origin_x;

// 	origin_x = rect.x;
// 	tmp = (*data)->lst->prev;
// 	while (tmp && tmp != (*data)->lst)
// 	{
// 		rect.y -= rect.height;
// 		rect.width = WINDOW_WIDTH / 2 * (ft_abs(tmp->value) + 1) / (*data)->value_max;
// 		rect.x = origin_x - (rect.width / 2);
// 		if (tmp->value > 0)
// 			rect.color = 0xFF00;
// 		else
// 			rect.color = 0xFF0000;
// 		img_pix_put(&(*data)->img, rect.x, rect.y, rect.color);
// 		// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
// 		// 	0, 0);
// 		tmp = tmp->prev;
// 	}
// 	rect.y -= rect.height;
// 	rect.width = WINDOW_WIDTH / 2 * (ft_abs(tmp->value) + 1) / (*data)->value_max;
// 	rect.x = origin_x - (rect.width / 2);
// 	if (tmp->value > 0)
// 		rect.color = 0xFF00;
// 	else
// 		rect.color = 0xFF0000;
// 	img_pix_put(&(*data)->img, rect.x, rect.y, rect.color);
// 	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
// 	// 	0, 0);
// 	return (0);
// }

// int	render_list(t_img *img, t_rect *rect, t_list *lst, int value_max)
// {
// 	t_list	*tmp;
// 	int		origin_x;

// 	origin_x = rect->x;
// 	tmp = lst->prev;
// 	while (tmp && tmp != lst)
// 	{
// 		rect->y -= rect->height;
// 		rect->width = WINDOW_WIDTH / 2 * (ft_abs(tmp->value) + 1) / value_max;
// 		rect->x = origin_x - (rect->width / 2);
// 		if (tmp->value > 0)
// 			rect->color = 0xFF00;
// 		else
// 			rect->color = 0xFF0000;
// 		img_pix_put(img, rect->x, rect->y, rect->color);
// 		tmp = tmp->prev;
// 	}
// 	rect->y -= rect->height;
// 	rect->width = WINDOW_WIDTH / 2 * (ft_abs(tmp->value) + 1) / value_max;
// 	rect->x = origin_x - (rect->width / 2);
// 	if (tmp->value > 0)
// 		rect->color = 0xFF00;
// 	else
// 		rect->color = 0xFF0000;
// 	img_pix_put(img, rect->x, rect->y, rect->color);
// 	return (0);
// }

int	render_list(t_img *img, t_rect *rect, t_list *lst, int value_max)
{
	int	x;
	int	y;

	x = rect->x;
	y = rect->y;
	while (rect->y < y + rect->height)
	{
		while (rect->x < x + rect->width)
		{
			img_pix_put(img, rect->x, rect->y, rect->color);
			rect->x++;
		}
		++rect->y;
	}
	return (0);
}
