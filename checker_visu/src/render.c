/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:32:05 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/16 20:34:13 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

static int	create_gradient_color(int current_color, t_list *lst, int lst_size)
{
	int	new_color;
	int	color_default;

	return (new_color);
}

static void	create_rect_from_list(t_rect *rect, t_list *lst,
	int max_value, int size_lst)
{
	rect->width = ft_size_width(lst->value, max_value) - 10;
	rect->height = (WINDOW_HEIGHT / size_lst) - (size_lst * 2);
	rect->y -= rect->height;
	rect->color = 0xFF0000;
}
	// rect->color = 255 * 65536 + 0 * 256 + 0; // RED
	// rect->color = 0 * 65536 + 0 * 256 + 255; // BLUE
	// rect->color = 0 * 65536 + 255 * 256 + 0; // GREEN

void	display_pile(t_data *data, t_list *lst, t_rect *rect)
{
	t_list	*tmp;
	int		i;
	int		lst_size;

	if (!lst)
		return ;
	lst_size = ft_lstsize(lst);
	tmp = lst->prev;
	while (tmp != lst)
	{
		rect->color = create_gradient_color(0xFF0000, tmp, lst_size);
		create_rect_from_list(rect, tmp, data->value_max, data->size_lst);
		render_rect(&data->img, *rect);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
			0, 0);
		tmp = tmp->prev;
	}
	create_rect_from_list(rect, tmp, data->value_max, data->size_lst);
	render_rect(&data->img, *rect);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
}

int	render(t_data *data)
{
	t_rect	rect;

	if (!data->win_ptr)
		return (1);
	render_background(&data->img, 0xFFFFFFF);
	rect.x = 0;
	rect.y = WINDOW_HEIGHT;
	display_pile(data, *(data->p.pile_a), &rect);
	rect.x += WINDOW_WIDTH / 2;
	rect.y = WINDOW_HEIGHT;
	display_pile(data, *(data->p.pile_b), &rect);
	return (0);
}

	// printf("x = %d | y = %d | w = %d | h = %d\n", rect.x,
		// rect.y, rect.width, rect.height);
