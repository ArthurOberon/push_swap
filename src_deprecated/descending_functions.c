/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descending_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:26:25 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/02 15:57:12 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_to_descending(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, int order)
{
	t_list	*tmp;
	int		lst_length;
	int		value_max;

	tmp = *lst_b;
	lst_length = ft_lstsize(*lst_b);
	value_max = ft_found_value_max(lst_b, lst_length);
	if (order == 2)
	{
		while (tmp->value != value_max)
		{
			ft_do_operation("rb", lst_a, lst_b);
			ft_print_piles("rb", lst_a, lst_b);
			tmp = *lst_b;
		}
	}
	else if (order == 3)
	{
		while (tmp->value != value_max)
		{
			ft_do_operation("rb", lst_a, lst_b);
			ft_print_piles("rb", lst_a, lst_b);
			tmp = *lst_b;
		}
	}
}

static int	ft_get_descending_one_part(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, int stop_check)
{
	t_list	*tmp;
	int		i;
	int		max_value;
	int		min_value;
	int		pushed_number;

	pushed_number = 0;
	i = 1;
	max_value = ft_found_value_max(lst_b, ft_lstsize(*lst_b));
	min_value = ft_found_value_min(lst_b, ft_lstsize(*lst_b));
	tmp = *lst_b;
	if (stop_check == 2 || stop_check == 3)
	{
		while (pushed_number != 1)
		{
			if (tmp->value < tmp->next->value)
			{
				ft_do_operation("pa", lst_a, lst_b);
				ft_print_piles("pa", lst_a, lst_b);
				pushed_number++;
			}
			else
			{
				ft_do_operation("rb", lst_a, lst_b);
				ft_print_piles("rb", lst_a, lst_b);
			}
			tmp = *lst_b;
		}
		return (pushed_number);
	}
	while (i < stop_check)
	{
		if (tmp->value == max_value)
		{
			printf("1\n");
			ft_do_operation("pa", lst_a, lst_b);
			ft_print_piles("pa", lst_a, lst_b);
			pushed_number++;
		}
		else if (tmp->prev->value == min_value)
		{
			printf("2\n");
			if (tmp->value < tmp->next->value)
			{
				ft_do_operation("pa", lst_a, lst_b);
				ft_print_piles("pa", lst_a, lst_b);
				pushed_number++;
			}
			else
			{
				ft_do_operation("rb", lst_a, lst_b);
				ft_print_piles("rb", lst_a, lst_b);
			}
		}
		else if (tmp->value == min_value)
		{
			printf("3\n");
			ft_do_operation("rb", lst_a, lst_b);
			ft_print_piles("rb", lst_a, lst_b);
		}
		else if (tmp->next->value == min_value)
		{
			printf("4\n");
			if (tmp->prev->value < tmp->value)
			{
				ft_do_operation("pa", lst_a, lst_b);
				ft_print_piles("pa", lst_a, lst_b);
				pushed_number++;
			}
			else
			{
				ft_do_operation("rb", lst_a, lst_b);
				ft_print_piles("rb", lst_a, lst_b);
			}
		}
		else if (tmp->prev->value < tmp->value || tmp->value < tmp->next->value)
		{
			printf("5\n");
			ft_do_operation("pa", lst_a, lst_b);
			ft_print_piles("pa", lst_a, lst_b);
			pushed_number++;
		}
		else
		{
			printf("6\n");
			ft_do_operation("ra", lst_a, lst_b);
			ft_print_piles("ra", lst_a, lst_b);
		}
		tmp = *lst_b;
		i++;
		printf("I = [%d] && STOP = [%d] && PUSHED_NUMBER = [%d]\n", i, stop_check, pushed_number);
	}
	printf("\n\nLAST UPDATE :\nI = [%d] && STOP = [%d] && PUSHED_NUMBER = [%d]\n", i, stop_check, pushed_number);
	return (pushed_number);
}

static void	ft_get_back_to_stack_b(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction, int pushed_number)
{
	int	i;

	i = 1;
	while (i <= pushed_number)
	{
		ft_do_operation("pb", lst_a, lst_b);
		ft_print_piles("pb", lst_a, lst_b);
		i++;
	}
}

static int	ft_is_descending_by_parts(t_list **lst, int number_of_block)
{
	int		i;
	int		stop_check;
	t_list	*first;
	t_list	*tmp;

	i = 0;
	stop_check = ft_lstsize(*lst);
	first = *lst;
	tmp = first->prev;
	while (tmp != first)
	{
		printf("STAT => ## STOP CHECK = [%d] && TMP = [%d]\n", stop_check, tmp->value);
		if (tmp->value > tmp->prev->value && i == number_of_block)
			return (--stop_check);
		i++;
		stop_check--;
		tmp = tmp->prev;
	}
	return (0);
}

void	ft_get_descending_stack_b(t_list **lst_a, t_list **lst_b,
	t_instruction **lst_instruction)
{
	int	stop_check;
	int	i;

	i = 0;
	stop_check = ft_lstsize(*lst_b) - 2;
	printf("FIRST STOP CHECK = [%d] = LST_SIZE\n", stop_check);
	while (stop_check != 0 && stop_check != 1)
	{
		printf("\n\n####### GET DESCENDING FOR ONE PART ######\n\n");
		stop_check = ft_get_descending_one_part(lst_a, lst_b, lst_instruction, stop_check + 1);
		printf("\n\n####### END | GET DESCENDING FOR ONE PART | END ######\n\n");
		printf("\n\n####### ROTATE TO GET DESCENDING ORDER ######\n\n");
		ft_rotate_to_descending(lst_a, lst_b, lst_instruction, ft_is_in_order(lst_b));
		printf("\n\n####### END | ROTATE TO GET DESCENDING ORDER | END ######\n\n");
		i++;
		printf("PUSHED NUMBER = [%d]\n", stop_check);
		printf("\n\n####### GET BACK TO STACK_B ######\n\n");
		ft_get_back_to_stack_b(lst_a, lst_b, lst_instruction, stop_check);
		printf("\n\n####### END | GET BACK TO STACK_B | END ######\n\n");
		stop_check = ft_is_descending_by_parts(lst_b, i);
		printf("STOP CHECK = [%d]\n", stop_check);
		// if (i++ == 1)
		// 	stop_check = 0;
	}
}
