/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:55:15 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/17 16:06:24 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_checker(t_list lst_a, t_list lst_b)
// {
// }

int	ft_is_equal(char *str_checking, char *str_checker)
{
	int	i;

	i = 0;
	while (str_checking[i] && str_checker[i])
	{
		if (str_checking[i] != str_checker[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_instruction(t_instruction *lst)
{
	if (ft_is_equal(lst->operation, "sa"))
		return (1);
	else if (ft_is_equal(lst->operation, "sb"))
		return (1);
	else if (ft_is_equal(lst->operation, "ss"))
		return (1);
	else if (ft_is_equal(lst->operation, "pa"))
		return (1);
	else if (ft_is_equal(lst->operation, "pb"))
		return (1);
	else if (ft_is_equal(lst->operation, "ra"))
		return (1);
	else if (ft_is_equal(lst->operation, "rb"))
		return (1);
	else if (ft_is_equal(lst->operation, "rr"))
		return (1);
	else if (ft_is_equal(lst->operation, "rra"))
		return (1);
	else if (ft_is_equal(lst->operation, "rrb"))
		return (1);
	else if (ft_is_equal(lst->operation, "rrr"))
		return (1);
	return (0);
}

t_instruction	*ft_create_list_instruction(void)
{
	t_instruction	*lst_instruction;
	t_instruction	*tmp;
	char			*line;

	lst_instruction = NULL;
	line = get_next_line(0);
	while (line)
	{
		tmp = ft_lstnew_instruction(line);
		ft_print_new_element_instruction(tmp);
		ft_lstadd_back_instruction(&lst_instruction, tmp);
		if (!ft_check_instruction(tmp))
		{
			printf("ERROR\n");
			ft_lstclear_instruction(&lst_instruction);
			return (NULL);
		}
		line = get_next_line(0);
	}
	free(line);
	return (lst_instruction);
}

int	main(int argc, char **argv)
{
	t_list			*lst_a;
	t_list			*lst_b;
	t_instruction	*lst_instruction;
	char			*str;

	(void)argv;
	lst_a = NULL;
	lst_b = NULL;
	if (argc == 1)
	{
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
	str = ft_str_merge(argv + 1, 1, argc - 1);
	printf("str merged = \"%s\"\n", str);
	ft_parse(str, &lst_a);
	ft_print_list(&lst_a);
	lst_instruction = ft_create_list_instruction();
	if (!lst_instruction)
	{
		ft_lstclear(&lst_a);
		return (1);
	}
	ft_print_list_instruction(&lst_instruction);
	return (0);
}
