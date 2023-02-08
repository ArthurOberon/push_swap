/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions_combination.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:12:24 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/08 18:44:55 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_min_value(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

static int	ft_combinate_move(t_instruction *tmp, int n, char *combinated_move)
{
	t_instruction	*new_tmp;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (combinated_move[2] == 'r')
	{
		while ((i < n || j < n) && tmp->next)
		{
			new_tmp = tmp->next;
			if (tmp->operation[1] == 'r' && tmp->operation[2] == 'a' && i < n)
			{
				free(tmp->operation);
				tmp->operation = ft_strdup("rrr");
				if (!tmp->operation)
					return (-1);
				tmp->invert_operation = ft_invert_operation(combinated_move);
				i++;
			}
			else if (tmp->operation[1] == 'r' && tmp->operation[2] == 'b'
				&& j < n)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				free(tmp->operation);
				free(tmp);
				tmp = new_tmp;
				j++;
			}
			tmp = new_tmp;
		}
	}
	else
	{
		while ((i < n || j < n) && tmp->next)
		{
			new_tmp = tmp->next;
			if (tmp->operation[0] == 'r' && tmp->operation[1] == 'a' && i < n)
			{
				free(tmp->operation);
				tmp->operation = ft_strdup("rr");
				if (!tmp->operation)
					return (-1);
				tmp->invert_operation = ft_invert_operation(combinated_move);
				i++;
			}
			else if (tmp->operation[0] == 'r' && tmp->operation[1] == 'b'
				&& j < n)
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				free(tmp->operation);
				free(tmp);
				tmp = new_tmp;
				j++;
			}
			tmp = new_tmp;
		}
	}
	return (0);
}

int	ft_find_combination_move(t_instruction **lst)
{
	t_instruction	*tmp;
	t_instruction	*tmp_p;
	int				ra_number;
	int				rb_number;
	int				rra_number;
	int				rrb_number;

	if (!lst || !*lst)
		return (-1);
	tmp = *lst;
	while (tmp->next)
	{
		if (tmp->operation[0] == 'p')
		{
			ra_number = 0;
			rb_number = 0;
			rra_number = 0;
			rrb_number = 0;
			tmp_p = tmp;
			tmp = tmp->next;
			while ((tmp->operation[0] != 'p' && tmp->operation[0] != 's')
				&& tmp->next)
			{
				if (tmp->operation[1] == 'a')
					ra_number++;
				else if (tmp->operation[1] == 'b')
					rb_number++;
				else if (tmp->operation[1] == 'r' && tmp->operation[2] == 'a')
					rra_number++;
				else if (tmp->operation[1] == 'r' && tmp->operation[2] == 'b')
					rrb_number++;
				tmp = tmp->next;
			}
			if ((ft_combinate_move(tmp_p,
						ft_find_min_value(ra_number, rb_number), "rr") == -1)
				|| (ft_combinate_move(tmp_p,
						ft_find_min_value(rra_number, rrb_number),
						"rrr") == -1))
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
