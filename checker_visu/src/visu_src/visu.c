/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:28:57 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/17 16:51:08 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * 4);
	*(unsigned int *)pixel = color;
}

static t_data	data_init(t_list **pile_a, t_list **pile_b,
	t_instruction **lst_instruction)
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
	data.p.pile_a = pile_a;
	*pile_b = NULL;
	data.p.pile_b = pile_b;
	data.p.instructions = lst_instruction;
	data.direction = 1;
	data.autoplay = 0;
	data.stop_autoplay = 0;
	data.delay = 1;
	data.value_max = ft_find_value_max(*pile_a, &data.size_lst);
	return (data);
}

int	visu(t_list **pile_a, t_list **pile_b, t_instruction **lst_instruction)
{
	t_data		data;

	data = data_init(pile_a, pile_b, lst_instruction);
	render(&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop_hook(data.mlx_ptr, &ft_autoplay, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	ft_lstclear_instruction(lst_instruction);
	if (!ft_check_is_sort(pile_a) || pile_b)
	{
		ft_lstclear(pile_a);
		ft_lstclear(pile_b);
		ft_putstr_fd("KO\n", 1);
		return (0);
	}
	ft_lstclear(pile_a);
	ft_putstr_fd("OK\n", 1);
	return (1);
}
