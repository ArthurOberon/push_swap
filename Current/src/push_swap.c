/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:10:29 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/20 17:07:56 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_list **lst_a)

{
	t_list			*lst_b;
	t_instruction	*lst_instruction;
	t_push_swap		list_pack;
	t_list			*tmp_a;

	lst_b = NULL;
	lst_instruction = NULL;
	list_pack.pile_a = lst_a;
	list_pack.pile_b = &lst_b;
	list_pack.instructions = &lst_instruction;
	ft_init_index(lst_a);
	// ft_check_obvious(list_pack);
	// while ((*lst_a)->next != *lst_a)
		// ft_move("pb", list_pack);
	// if (ft_check_obvious(list_pack) != 1)
		ft_piles_ascending(list_pack);
	// return ;
		// ft_get_pile_ascending(list_pack);
	ft_print_instruction((*list_pack.instructions));
	printf("number of operations to separate : [%d]\n",
		ft_lstsize_instruction(lst_instruction));
	ft_print_piles("", list_pack);
	// return ;
	while (lst_b || !ft_is_ascending(*lst_a))
		ft_find_best_move(list_pack);
	tmp_a = *lst_a;
	while (tmp_a->index != 0)
		tmp_a = tmp_a->next;
	ft_move_to_top_pile_a(list_pack, tmp_a);
	ft_print_instruction((*list_pack.instructions));
	printf("number of operations : [%d]\n",
		ft_lstsize_instruction(lst_instruction));
	ft_lstclear(lst_a);
	ft_lstclear_instruction(&lst_instruction);
}

int	main(int argc, char **argv)
{
	t_list			*lst_a;
	char			*str;

	lst_a = NULL;
	if (argc == 1)
	{
		ft_putstr_fd("Too few arguments.\n", 1);
		ft_putstr_fd("Please use push_swap with this format :\n", 1);
		ft_putstr_fd("./push_swap \"0 1 2\" or ./push_swap 0 1 2\n", 1);
		return (1);
	}
	str = ft_str_merge(argv + 1, 1, argc - 1);
	if (ft_parse(str, &lst_a) == -1)
	{
		ft_lstclear(&lst_a);
		ft_putstr_fd("Error with the parsing\n", 2);
		return (1);
	}
	ft_push_swap(&lst_a);
	return (0);
}
