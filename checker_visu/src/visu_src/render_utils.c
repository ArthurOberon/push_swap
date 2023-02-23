/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:44:33 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/23 20:23:08 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

void	ft_memset_int(void *addr, int x, int color)
{
	int	i;

	i = 0;
	while (i < x)
	{
		*(unsigned int *)(addr + i) = color;
		++i;
	}
}

void	render_background(t_img *img, int color)
{
	ft_memset_int(img->addr, WINDOW_HEIGHT * WINDOW_WIDTH * 4, color);
}
	// i = 0;
	// while (i < WINDOW_HEIGHT)
	// {
	// 	j = 0;
	// 	while (j < WINDOW_WIDTH)
	// 		img_pix_put(img, j++, i, color);
	// 	++i;
	// }

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		i = rect.y;
		while (i < rect.y + rect.height)
		{
			j = rect.x;
			while (j < rect.x + rect.width)
				img_pix_put(img, j++, i, rect.color);
			++i;
		}
		++i;
	}
	return (0);
}

int	ft_size_width(int n, int max)
{
	int	result;

	result = (WINDOW_WIDTH / (max + 1)) * (n + 1);
	return (result / 2);
}
