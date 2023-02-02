/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:02:32 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/02 17:46:13 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_go_to_element_pile(t_list **start, t_list *dst)
{
	while (*start != dst)
	{
		*start = (*start)->next;
	}
}

t_list	*ft_get_the_n_element_pile(t_list *start, int n)
{
	int		i;
	t_list	*last;

	i = 0;
	last = start->prev;
	while (i < n && start != last)
	{
		start = start->next;
		i++;
	}
	return (start);
}

void	ft_move_to_top_pile_a(t_push_swap list_pack, t_list *element)
{
	t_list	**tmp;

	tmp = list_pack.pile_a;
	while (*tmp != element)
		ft_move("ra", list_pack);
}

void	ft_move_to_top_pile_b(t_push_swap list_pack, t_list *element,
	t_instruction **lst_instruction)
{
	t_list	**tmp;

	tmp = list_pack.pile_b;
	while (*tmp != element)
	{
		ft_move_temporary("rb", list_pack, lst_instruction);
	}
}

int	ft_calcul_gap(t_list *start_a, t_list *end_a,
	t_list *start_b, t_list *end_b)
{
	int		a;
	int		b;
	t_list	*tmp_a;
	t_list	*tmp_b;

	a = 0;
	b = 0;
	tmp_a = start_a;
	tmp_b = start_b;
	while (tmp_a != end_a)
	{
		tmp_a = tmp_a->next;
		a++;
	}
	while (tmp_b != end_b)
	{
		tmp_b = tmp_b->next;
		b++;
	}
	return (a > b);
}
