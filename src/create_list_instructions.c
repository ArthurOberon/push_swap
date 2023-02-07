/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_instructions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:47:12 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/07 16:45:23 by aoberon          ###   ########.fr       */
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

static int	ft_check_instruction(t_instruction *lst)
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
		ft_lstadd_back_instruction(&lst_instruction, tmp);
		if (!ft_check_instruction(tmp))
		{
			ft_putstr_fd("Error\n", 2);
			ft_lstclear_instruction(&lst_instruction);
			return (NULL);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (lst_instruction);
}
