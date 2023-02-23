/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_instructions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:47:12 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/23 22:42:37 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_equal(char *str_checking, char *str_checker)
{
	int	i;

	i = 0;
	if (!str_checking[i])
		return (0);
	while (str_checking[i] && str_checker[i])
	{
		if (str_checking[i] != str_checker[i])
			return (0);
		i++;
	}
	if (str_checking[i] || str_checker[i])
		return (0);
	return (1);
}

static int	ft_check_instruction(char *operation)
{
	if (ft_is_equal(operation, "sa"))
		return (1);
	else if (ft_is_equal(operation, "sb"))
		return (1);
	else if (ft_is_equal(operation, "ss"))
		return (1);
	else if (ft_is_equal(operation, "pa"))
		return (1);
	else if (ft_is_equal(operation, "pb"))
		return (1);
	else if (ft_is_equal(operation, "ra"))
		return (1);
	else if (ft_is_equal(operation, "rb"))
		return (1);
	else if (ft_is_equal(operation, "rr"))
		return (1);
	else if (ft_is_equal(operation, "rra"))
		return (1);
	else if (ft_is_equal(operation, "rrb"))
		return (1);
	else if (ft_is_equal(operation, "rrr"))
		return (1);
	return (0);
}

static void	ft_exit_lst_instruction(t_instruction *lst,
	char *line)
{
	free(line);
	ft_lstclear_instruction(&lst);
	ft_putstr_fd("Error with a malloc\n", 2);
}

t_instruction	*ft_create_list_instruction(void)
{
	t_instruction	*lst_instruction;
	char			*line;

	lst_instruction = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (ft_add_instruction(line, &lst_instruction) == -1)
			return (ft_exit_lst_instruction(lst_instruction, line), NULL);
		if (!ft_check_instruction(line))
		{
			free(line);
			ft_putstr_fd("Error\n", 2);
			ft_lstclear_instruction(&lst_instruction);
			return (NULL);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (ft_add_instruction("NULL", &lst_instruction) == -1)
		return (ft_exit_lst_instruction(lst_instruction, line), NULL);
	return (lst_instruction);
}
