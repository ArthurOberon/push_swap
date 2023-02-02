/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:59:39 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/02 15:57:21 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_transfert_b_to_a(t_list	**lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		max_value;
	int		min_value;

	max_value = ft_found_value_max(lst_a, ft_lstsize(*lst_a));
	min_value = ft_found_value_min(lst_b, ft_lstsize(*lst_b));
	tmp_a = *lst_a;
	tmp_b = *lst_b;
	while ("not ascending")
	{
		printf("GET A GOOD WITH B ?\n");
		while (!(tmp_a->value > tmp_b->value)
			&& tmp_b->value != min_value)
		{
			printf("NOT GOOD -> A[%d] > B[%d]\n", tmp_a->value, tmp_b->value);
			ft_do_operation("ra", lst_a, lst_b);
			ft_print_piles("ra", lst_a, lst_b);
			tmp_a = *lst_a;
		}
		// printf("max_value = [%d] && A = [%d]\n", max_value, tmp_a->value);
		// printf("min_value = [%d] && B = [%d]\n", min_value, tmp_b->value);
		printf("A = [%d] B = [%d]\n",tmp_a->value, tmp_b->value);
		if (tmp_b->value == min_value)
		{
			printf("B = MIN DO WHAT I HAVE TO DO\n");
			while (tmp_a->value != max_value)
			{
				ft_do_operation("ra", lst_a, lst_b);
				ft_print_piles("ra", lst_a, lst_b);
				tmp_a = *lst_a;
			}
			ft_do_operation("pa", lst_a, lst_b);
			ft_print_piles("pa", lst_a, lst_b);
			tmp_b = *lst_b;
			tmp_a = *lst_a;
		}
		else if (tmp_a->prev->value < tmp_b->value && tmp_a->value > tmp_b->value)
		{
			printf("PrevA[%d] < B[%d] < A[%d]\n", tmp_a->prev->value, tmp_b->value, tmp_a->value);
			ft_do_operation("pa", lst_a, lst_b);
			ft_print_piles("pa", lst_a, lst_b);
			tmp_b = *lst_b;
			tmp_a = *lst_a;
		}
		else
		{
			ft_do_operation("ra", lst_a, lst_b);
			ft_print_piles("ra", lst_a, lst_b);
			tmp_a = *lst_a;
		}
	}
}

static void	ft_push_swap(t_list	**lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	int	order;

	ft_print_piles("START", lst_a, lst_b);
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
	order = ft_is_in_order(lst_b);
	if (order == 3)
	{
		printf("Do function to push all the b to a\n");
	}
	printf("\n\nSTEP 2 => B !\n\n");
	ft_get_order(lst_a, lst_b, lst_instruction, 'B');
	ft_transfert_b_to_a(lst_a, lst_b, lst_instruction);
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
