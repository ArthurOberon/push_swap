/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:12:24 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/05 12:03:01 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_min_value(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

static void	ft_combinate_move(t_instruction *tmp, int n, char *combinated_move)
{
	t_instruction	*new_tmp;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (combinated_move[2] == 'r')
	{
		// printf("\n\nRR with [%p] :\n", tmp);
		while ((i < n || j < n) && tmp->next)
		{
			// printf("	tmp = [%s]\n", tmp->operation);
			new_tmp = tmp->next;
			if (tmp->operation[1] == 'r' && tmp->operation[2] == 'a' && i < n)
			{
				// printf("tmp [%s] = 'rr'\n", tmp->operation);
				tmp->operation = "rrr";
				tmp->invert_operation = ft_invert_operation(combinated_move);
				i++;
			}
			else if (tmp->operation[1] == 'r' && tmp->operation[2] == 'b' && j < n)
			{
				// printf("BEFORE\n[%s]<-[%s]->[%s]\n", tmp->prev->operation, tmp->operation, tmp->next->operation);
				// printf("BEFORE\n[%p]<-[%p]->[%p]\n", tmp->prev, tmp, tmp->next);
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				free(tmp);
				tmp = new_tmp;
				// printf("AFTER\n[%s]<-[%s]->[%s]\n", tmp->prev->operation, tmp->operation, tmp->next->operation);
				// printf("AFTER\n[%p]<-[%p]->[%p]\n", tmp->prev, tmp, tmp->next);
				j++;
			}
			tmp = new_tmp;
		}
		// printf("I = %d J = %d\n\n\n", i, j);
	}
	else
	{
		// printf("\n\nRR with [%p] :\n", tmp);
		while ((i < n || j < n) && tmp->next)
		{
			// printf("	tmp = [%s]\n", tmp->operation);
			new_tmp = tmp->next;
			if (tmp->operation[0] == 'r' && tmp->operation[1] == 'a' && i < n)
			{
				// printf("tmp [%s] = 'rr'\n", tmp->operation);
				tmp->operation = "rr";
				tmp->invert_operation = ft_invert_operation(combinated_move);
				i++;
			}
			else if (tmp->operation[0] == 'r' && tmp->operation[1] == 'b' && j < n)
			{
				// printf("BEFORE\n[%s]<-[%s]->[%s]\n", tmp->prev->operation, tmp->operation, tmp->next->operation);
				// printf("BEFORE\n[%p]<-[%p]->[%p]\n", tmp->prev, tmp, tmp->next);
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
				free(tmp);
				tmp = new_tmp;
				// printf("AFTER\n[%s]<-[%s]->[%s]\n", tmp->prev->operation, tmp->operation, tmp->next->operation);
				// printf("AFTER\n[%p]<-[%p]->[%p]\n", tmp->prev, tmp, tmp->next);
				j++;
			}
			tmp = new_tmp;
		}
		// printf("I = %d J = %d\n\n\n", i, j);
	}
}

// static void	ft_combinate_move(t_instruction *tmp, char *combinated_move)
// {
// 	t_instruction	*new_next;
// 	t_instruction	*next;

// 	next = tmp->next;
// 	new_next = next->next;
// 	free(next);
// 	tmp->next = new_next;
// 	new_next->prev = tmp;
// 	tmp->operation = combinated_move;
// 	tmp->invert_operation = ft_invert_operation(combinated_move);
// }

void	ft_find_combination_move(t_instruction **lst)
{
	t_instruction	*tmp;
	t_instruction	*tmp_p;
	int				ra_number;
	int				rb_number;
	int				rra_number;
	int				rrb_number;

	tmp = *lst;
	while (tmp->next)
	{
		// printf("TMP = [%s] => [%s]\n", tmp->operation, tmp->next->operation);
		if (tmp->operation[0] == 'p')
		{
			ra_number = 0;
			rb_number = 0;
			rra_number = 0;
			rrb_number = 0;
			tmp_p = tmp;
			// printf("		tmp_p = [%p]\n", tmp_p);
			tmp = tmp->next;
			while ((tmp->operation[0] != 'p' || tmp->operation[0] == 's') && tmp->next)
			{
				if (tmp->operation[1] == 'a')
					ra_number++;
				else if (tmp->operation[1] == 'b')
					rb_number++;
				else if (tmp->operation[1] == 'r' && tmp->operation[2] == 'a')
					rra_number++;
				else if (tmp->operation[1] == 'r' && tmp->operation[2] == 'b')
					rrb_number++;
				// printf("		TMP = [%s] => [%s]\n", tmp->operation, tmp->next->operation);
				// printf("		tmp_p = [%p]\n", tmp_p);
				// printf("		RA = [%d]\n		RB = [%d]\n", ra_number, rb_number);
				// printf("		RRA = [%d]\n		RRB = [%d]\n", rra_number, rrb_number);
				tmp = tmp->next;
			}
			// printf("		TMP = [%s]\n", tmp->operation);
			// printf("	Met 'p' or 's' (%s); number of rr = [%d] | rrr = [%d]\n",tmp->operation, ft_find_min_value(ra_number, rb_number), 0);
			ft_combinate_move(tmp_p, ft_find_min_value(ra_number, rb_number),
				"rr");
			ft_combinate_move(tmp_p, ft_find_min_value(rra_number, rrb_number),
				"rrr");
		}
		else
			tmp = tmp->next;
	}
}

		// if (tmp->operation[0] == 'r' && next->operation[0] == 'r')
		// {
		// 	if ((tmp->operation[1] == 'a' && next->operation[1] == 'b')
		// 		|| (tmp->operation[1] == 'b' && next->operation[1] == 'a'))
		// 	{
		// 		ft_combinate_move(tmp, "rr");
		// 		next = tmp->next;
		// 	}
		// 	else if (tmp->operation[1] == 'r' && next->operation[1] == 'r')
		// 	{
		// 		if ((tmp->operation[2] == 'a' && next->operation[2] == 'b')
		// 			|| (tmp->operation[2] == 'b' && next->operation[2] == 'a'))
		// 		{
		// 			ft_combinate_move(tmp, "rrr");
		// 			next = tmp->next;
		// 		}
		// 	}
		// }
