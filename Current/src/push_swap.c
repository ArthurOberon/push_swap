/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:10:29 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/16 19:23:56 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_list **lst_a)

{
	t_list			*lst_b;
	t_instruction	*lst_instruction;
	t_push_swap		list_pack;

	lst_b = NULL;
	lst_instruction = NULL;
	list_pack.pile_a = lst_a;
	list_pack.pile_b = &lst_b;
	list_pack.instructions = &lst_instruction;
	ft_init_index(lst_a);
	ft_get_pile_ascending(list_pack);
	// ft_print_piles("FIRST", list_pack);
	// printf("number of operations : [%d]\n",
		// ft_lstsize_instruction(lst_instruction));
	while (lst_b || !ft_is_ascending(*lst_a))
	{
		// ft_print_piles("", list_pack);
		ft_find_best_move(list_pack);
	}
	// ft_print_piles("END", list_pack);
	ft_print_instruction(lst_instruction);
	// printf("number of operations : [%d]\n",
		// ft_lstsize_instruction(lst_instruction));
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
