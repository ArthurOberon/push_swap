/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:59:39 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/23 17:15:45 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_keep_ascending_stack_a(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	t_list	*tmp;
	int		i;
	int		lst_length;

	i = 1;
	lst_length = ft_lstsize(lst_a);
	tmp = *lst_a;
	while (i <= lst_length)
	{
		printf("[%d] => [%d]\n", i, lst_length);
		printf("??? [%d] > [%d] ???\n", tmp->value, tmp->next->value);
		if (tmp->value > tmp->next->value)
		{
			printf("	[%d] > [%d]\n", tmp->value, tmp->next->value);
			ft_do_operation("pb", lst_a, lst_b);
			ft_print_piles("pb", lst_a, lst_b);
			lst_length--;
		}
		else
		{
			ft_do_operation("ra", lst_a, lst_b);
			ft_print_piles("ra", lst_a, lst_b);
		}
		tmp = *lst_a;
		i++;
	}
}

static void	ft_keep_ascending_stack_b(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
}

static void	ft_keep_ascending_number(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, char lst_keeping)
{
	printf("A or B ?\n");
	if (lst_keeping == 'A')
	{
		printf("A !\n");
		ft_keep_ascending_stack_a(lst_a, lst_b, lst_instruction);
	}
	else if (lst_keeping == 'B')
	{
		printf("B !\n");
		ft_keep_ascending_stack_b(lst_a, lst_b, lst_instruction);
	}
}

static void	ft_push_swap(t_list	**lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	ft_keep_ascending_number(lst_a, lst_b, lst_instruction, 'A');
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
