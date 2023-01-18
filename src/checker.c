/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:55:15 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/18 16:54:29 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_is_sort(t_list **lst)
{
	t_list	*first;
	t_list	*tmp;

	first = *lst;
	tmp = first->next;
	if (first->value > tmp->value)
		return (0);
	while (tmp->next != first)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	ft_checker(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	t_instruction	*tmp_instruction;

	tmp_instruction = *lst_instruction;
	ft_print_piles("START", lst_a, lst_b);
	while (tmp_instruction)
	{
		ft_do_operation(tmp_instruction->operation, lst_a, lst_b);
		ft_print_piles(tmp_instruction->operation, lst_a, lst_b);
		tmp_instruction = tmp_instruction->next;
	}
	ft_lstclear_instruction(lst_instruction);
	if (!ft_check_is_sort(lst_a))
	{
		ft_lstclear(lst_a);
		ft_putstr("KO\n");
		return (0);
	}
	ft_lstclear(lst_a);
	ft_putstr("OK\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_list			*lst_a;
	t_list			*lst_b;
	t_instruction	*lst_instruction;
	char			*str;

	if (argc == 1)
	{
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
	str = ft_str_merge(argv + 1, 1, argc - 1);
	if (ft_parse(str, &lst_a) == -1)
	{
		ft_lstclear(&lst_a);
		ft_putstr("Error\n");
		return (1);
	}
	lst_instruction = ft_create_list_instruction();
	if (!lst_instruction)
		return (ft_lstclear(&lst_a), 1);
	return (ft_checker(&lst_a, &lst_b, &lst_instruction));
}
