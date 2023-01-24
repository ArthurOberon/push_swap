/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:59:39 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/24 14:21:56 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_swap(t_list	**lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	int	ordering;

	ft_print_piles("START", lst_a, lst_b);
	ordering = ft_is_ordering(lst_a);
	if (ordering != 0)
		ft_rotate_to_ascending(ordering);
	else
	{
		ft_keep_ascending_number(lst_a, lst_b, lst_instruction, 'A'); //add avoid => move when min->max | max->min
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_list			*lst_a;
	t_list			*lst_b;
	t_instruction	*lst_instruction;
	char			*str;

	lst_a = NULL;
	lst_b = NULL;
	lst_instruction = NULL;
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
	printf("Let's go !\n");
	ft_push_swap(&lst_a, &lst_b, &lst_instruction);
	return (0);
}
