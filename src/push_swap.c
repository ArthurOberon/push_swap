/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:59:39 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/25 11:50:26 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_to_ascending(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, int order)
{
	t_list	*tmp;
	int		lst_length;
	int		value_min;

	tmp = *lst_a;
	lst_length = ft_lstsize(lst_a);
	value_min = ft_found_value_min(lst_a, lst_length);
	printf("ORDER = [%d]\n", order);
	if (order == ASCENDING)
	{
		while (tmp->value != value_min)
		{
			ft_do_operation("ra", lst_a, lst_b);
			ft_print_piles("ra", lst_a, lst_b);
			tmp = *lst_a;
		}
	}
	else if (order == DESCENDING)
	{
		while (tmp->value != value_min)
		{
			ft_do_operation("ra", lst_a, lst_b);
			ft_print_piles("ra", lst_a, lst_b);
			tmp = *lst_a;
		}
		printf("Do function to invert the all stack\n");
	}
}

static void	ft_push_swap(t_list	**lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	int	order;

	ft_print_piles("START", lst_a, lst_b);
	// FIRST PART -> GET ASCENDING STACK A
	order = ft_is_in_order(lst_a);
	if (order != 0)
	{
		ft_rotate_to_ascending(lst_a, lst_b, lst_instruction, order);
	}
	else
	{
		ft_get_order(lst_a, lst_b, lst_instruction, 'A');
		printf("\n\n\nORDER FINISHED -> ROTATE IN ASCENDING\n\n\n");
		ft_rotate_to_ascending(lst_a, lst_b, lst_instruction,
			ft_is_in_order(lst_a));
	}
	printf("\n\n\nSTEP 2 !\n\n\n");
	// SECOND PART -> GET DESCENDING STACK B IN MULTIPLE PARTS
	order = ft_is_in_order(lst_b);
	if (order == DESCENDING)
	{
		printf("Do function to push all the b to a\n");
	}
	printf("\n\nSTEP 2 => B !\n\n");
	ft_get_order(lst_a, lst_b, lst_instruction, 'B');
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
	printf("ORDER = [%d]\n", ft_is_in_order(&lst_a));
	ft_push_swap(&lst_a, &lst_b, &lst_instruction);
	return (0);
}
