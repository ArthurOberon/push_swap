/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:55:15 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/24 15:24:45 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

int	ft_check_is_sort(t_list **lst)
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

	*lst_b = NULL;
	tmp_instruction = *lst_instruction;
	while (tmp_instruction)
	{
		ft_do_operation(tmp_instruction->operation, lst_a, lst_b);
		tmp_instruction = tmp_instruction->next;
	}
	ft_lstclear_instruction(lst_instruction);
	if (!ft_check_is_sort(lst_a) || *lst_b)
	{
		ft_lstclear(lst_a);
		ft_lstclear(lst_b);
		ft_putstr_fd("KO\n", 1);
		return (0);
	}
	ft_lstclear(lst_a);
	ft_putstr_fd("OK\n", 1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list			*lst_a;
	t_list			*lst_b;
	t_instruction	*lst_instruction;
	char			*str;
	int				visualize;

	lst_a = NULL;
	if (argc == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	str = ft_str_merge(argv + 1, 1, argc - 1);
	if (ft_parse(str, &lst_a, &visualize) == -1)
	{
		ft_lstclear(&lst_a);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	ft_init_index(&lst_a);
	lst_instruction = ft_create_list_instruction();
	if (!lst_instruction)
	{
		ft_lstclear(&lst_a);
		return (1);
	}
	if (visualize)
		return (visu(&lst_a, &lst_b, &lst_instruction));
	return (ft_checker(&lst_a, &lst_b, &lst_instruction));
}
