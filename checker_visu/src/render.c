/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:32:05 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/17 13:00:54 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

	// printf("	Ratio = %f\n	Normalized = %d\n	Region = %d\n	X = %d\n",
		// ratio, normalized, region, x);

static int	create_gradient_color(float ratio)
{
	int	color;
	int	r;
	int	g;
	int	b;
	int	normalized;
	int	region;
	int	x;

	normalized = (int)(ratio * 256 * 4);
	region = normalized / 256;
	x = normalized % 256;
	if (region == 0)
	{
		r = 0;
		g = x;
		b = 255;
	}
	else if (region == 1)
	{
		r = 0;
		g = 255;
		b = 255 - x;
	}
	else if (region == 2)
	{
		r = x;
		g = 255;
		b = 0;
	}
	else if (region == 3)
	{
		r = 255;
		g = 255 - x;
		b = 0;
	}
	color = r << 16 | g << 8 | b;
	return (color);
}

static void	create_rect_from_list(t_rect *rect, t_list *lst,
	int max_value, int size_lst)
{
	rect->width = ft_size_width(lst->index, max_value) - 10;
	rect->height = (WINDOW_HEIGHT / size_lst);
	rect->y -= rect->height;
	rect->color = create_gradient_color((float)lst->index / (float)size_lst);
}

void	display_pile(t_data *data, t_list *lst, t_rect *rect)
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = lst->prev;
	while (tmp != lst)
	{
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
