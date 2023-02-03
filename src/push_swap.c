/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:46:18 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/03 12:29:27 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_ascending(t_list *lst)
{
	t_list	*last;

	last = lst->prev;
	while (lst != last)
	{
		if (lst->index > lst->next->index)
			return (0);
		lst = lst->next;
	}
	return (1);
}

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
	ft_get_order(list_pack);
	// while (!ft_is_ascending(*lst_a))
	// {
	ft_calcul_move(list_pack);
	// }
	ft_print_piles("1st", list_pack);
	if (!ft_is_ascending(*lst_a))
	{
		printf("Not ascending\n");
		ft_calcul_move(list_pack);
		ft_print_piles("2nd", list_pack);
	}
	if (!ft_is_ascending(*lst_a))
	{
		printf("Not ascending\n");
		ft_calcul_move(list_pack);
		ft_print_piles("3rd", list_pack);
	}
	if (!ft_is_ascending(*lst_a))
	{
		printf("Not ascending\n");
		ft_calcul_move(list_pack);
		ft_print_piles("4th", list_pack);
	}
}

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
