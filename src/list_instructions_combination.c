/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions_combination.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:12:24 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/09 10:32:21 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_combinate_move_helper(t_instruction *tmp, int n,
	char *combinated_move, int k)
{
	t_instruction	*new_tmp;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while ((i < n || j < n) && tmp->next)
	{
		new_tmp = tmp->next;
		if (tmp->operation[k] == 'r' && tmp->operation[k + 1] == 'a'
			&& i < n)
		{
			free(tmp->operation);
			tmp->operation = ft_strdup(combinated_move);
			if (!tmp->operation)
				return (-1);
			tmp->invert_operation = ft_invert_operation(combinated_move);
			i++;
		}
		else if (tmp->operation[k] == 'r' && tmp->operation[k + 1] == 'b'
			&& j++ < n)
			ft_delete_one_element(&tmp, new_tmp);
		tmp = new_tmp;
	}
}

int	ft_combinate_move(t_instruction *tmp, int n, char *combinated_move)
{
	if (combinated_move[2] == 'r')
	{
		if (ft_combinate_move_helper(tmp, n, combinated_move, 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_combinate_move_helper(tmp, n, combinated_move, 0) == -1)
			return (-1);
	}
	return (0);
}

int	ft_find_combination_move(t_instruction **lst)
{
	t_instruction	*tmp;
	t_instruction	*tmp_p;
	int				combinate_number[4];

	if (!lst || !*lst)
		return (-1);
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->operation[0] == 'p')
		{
			ft_init_int_tab(combinate_number, 4);
			tmp_p = tmp;
			tmp = tmp->next;
			if (ft_find_combination_move_helper(&tmp, combinate_number) == -1)
			{
				ft_putstr_fd("Error with a malloc\n", 2);
				return (-1);
			}
		}
		else
			tmp = tmp->next;
	}
	return (1);
}
