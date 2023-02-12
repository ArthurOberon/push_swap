/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:17:35 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/12 18:53:17 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

// void	img_pix_put(t_img *img, int x, int y, int color)
// {
// 	char	*pixel;
// 	int		i;

// 	i = img->bpp - 8;
// 	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	while (i >= 0)
// 	{
// 		if (img->endian != 0)
// 			*pixel++ = (color >> i) & 0xFF;
// 		else
// 			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
// 		i -= 8;
// 	}
// }

static t_data	data_init(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		exit(EXIT_FAILURE);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"PATATE");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		exit(EXIT_FAILURE);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	return (data);
}

static void	list_init(t_list **lst)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp_print;

	i = 0;
	*lst = NULL;
	while (i < 5)
	{
		tmp = ft_lstnew(i);
		printf("%d\n", tmp->value);
		ft_lstadd_back(lst, tmp);
		i++;
	}
	tmp_print = *lst;
	printf("I finished\n");
	while (tmp_print != (*lst)->prev)
	{
		printf("%d\n", tmp_print->value);
		tmp_print = tmp_print->next;
	}
	printf("%d\n", tmp_print->value);
}

int	main(void)
{
	t_data	data;
	t_list	*lst;

	data = data_init();
	printf("%s\n", data.img.addr);
	list_init(&lst);
	data.lst = lst;
	data.value_max = maxvalue(lst, &(data.pop));
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	ft_lstclear(&lst);
	return (0);
}
