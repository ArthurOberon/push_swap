/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions_combination_utils.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:45:52 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/09 10:30:15 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min_value(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	ft_init_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
}

void	ft_delete_one_element(t_instruction **tmp, t_instruction *new_tmp)
{
	(*tmp)->prev->next = (*tmp)->next;
	(*tmp)->next->prev = (*tmp)->prev;
	free((*tmp)->operation);
	free(*tmp);
}

int	ft_find_combination_move_helper(t_instruction **tmp, int *combinate_number)
{
	t_instruction	*tmp_p;

	tmp_p = (*tmp)->prev;
	while (((*tmp)->operation[0] != 'p' && (*tmp)->operation[0] != 's')
		&& (*tmp)->next)
	{
		if ((*tmp)->operation[1] == 'a')
			combinate_number[0]++;
		else if ((*tmp)->operation[1] == 'b')
			combinate_number[1]++;
		else if ((*tmp)->operation[1] == 'r' && (*tmp)->operation[2] == 'a')
			combinate_number[2]++;
		else if ((*tmp)->operation[1] == 'r' && (*tmp)->operation[2] == 'b')
			combinate_number[3]++;
		(*tmp) = (*tmp)->next;
	}
	if ((ft_combinate_move(tmp_p,
				ft_find_min_value(combinate_number[0], combinate_number[1]),
				"rr") == -1) || (ft_combinate_move(tmp_p,
				ft_find_min_value(combinate_number[2], combinate_number[3]),
				"rrr") == -1))
		return (-1);
	return (1);
}
