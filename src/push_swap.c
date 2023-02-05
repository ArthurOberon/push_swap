/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:46:18 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/05 12:46:17 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_list **lst_a)
{
	t_list			*tmp_a;
	t_list			*lst_b;
	t_instruction	*lst_instruction;
	t_push_swap		list_pack;

	lst_b = NULL;
	lst_instruction = NULL;
	list_pack.pile_a = lst_a;
	list_pack.pile_b = &lst_b;
	list_pack.instructions = &lst_instruction;
	ft_init_index(lst_a);
	ft_get_order(list_pack);
	while (!ft_is_ascending(*lst_a) || lst_b)
		ft_calcul_move(list_pack);
	tmp_a = *lst_a;
	while (tmp_a->index != 0)
		tmp_a = tmp_a->next;
	ft_move_to_top_pile_a(list_pack, tmp_a);
	// ft_print_instruction(lst_instruction);
	// printf("Check if instructions can be reduce\n");
	ft_find_combination_move(&lst_instruction);
	// printf("Print instructions\n");
	ft_print_instruction(lst_instruction);
	ft_lstclear(lst_a);
	ft_lstclear_instruction(&lst_instruction);
}
	// ft_print_piles("END", list_pack);

int	main(int argc, char **argv)
{
	t_list			*lst_a;
	char			*str;

	lst_a = NULL;
	if (argc == 1)
	{
		ft_putstr("Too few arguments.\n");
		ft_putstr("Please use push_swap with this format :\n");
		ft_putstr("./push_swap \"0 1 2\" or ./push_swap 0 1 2\n");
		return (1);
	}
	str = ft_str_merge(argv + 1, 1, argc - 1);
	if (ft_parse(str, &lst_a) == -1)
	{
		ft_lstclear(&lst_a);
		ft_putstr("Error\n");
		return (1);
	}
	ft_push_swap(&lst_a);
	return (0);
}
