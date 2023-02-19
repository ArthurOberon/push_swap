/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles_ascending_simulation_error.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:28:06 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/19 13:29:19 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_find_smaller_index(t_list *lst, int current_index, int n)
{
	int		i;
	int		tmp_index;
	t_list	*lst_return;

	i = 0;
	tmp_index = 0;
	lst_return = NULL;
	while (i < n)
	{
		if (lst->index == 0)
		{
			return (lst_return);
		}
		if (lst->index > current_index
			&& (lst->index < tmp_index || tmp_index == 0))
		{
			tmp_index = lst->index;
			lst_return = lst;
		}
		lst = lst->next;
		i++;
	}
	return (lst_return);
}

t_list	*ft_lstdup(t_list *src)
{
	t_list	*result;
	t_list	*tmp;
	t_list	*new;

	result = NULL;
	tmp = src;
	while (tmp != src->prev)
	{
		new = malloc(sizeof(t_list));
		new->value = tmp->value;
		new->index = tmp->index;
		ft_lstadd_back(&result, new);
		tmp = tmp->next;
	}
	new = malloc(sizeof(t_list));
	new->value = tmp->value;
	new->index = tmp->index;
	ft_lstadd_back(&result, new);
	return (result);
}

static void	ft_operation_simulation(char c, t_list **simulation)
{
	int		swap;
	int		swap_index;

	if (c == 's')
	{
		swap = (*simulation)->value;
		(*simulation)->value = (*simulation)->next->value;
		(*simulation)->next->value = swap;
		swap_index = (*simulation)->index;
		(*simulation)->index = (*simulation)->next->index;
		(*simulation)->next->index = swap_index;
	}
	else if (c == 'r')
	{
		(*simulation) = (*simulation)->next;
	}
	else if (c == 'p')
	{
		ft_lstmoveout(simulation);
	}
}

	// if (lst == tmp->next && tmp->next->index != 0)

static void	ft_push_all_between(t_list **simulation, t_list *lst)
{
	if (lst == (*simulation)->next)
	{
		ft_operation_simulation('s', simulation);
		ft_operation_simulation('r', simulation);
	}
	else
	{
		while ((*simulation) != lst && (*simulation)->index != 0)
		{
			ft_operation_simulation('p', simulation);
		}
		if ((*simulation)->index != 0)
			ft_operation_simulation('r', simulation);
	}
}

static int	ft_check_obvious(t_push_swap list_pack)
{
	t_list	*tmp;

	if (ft_lstsize(*list_pack.pile_a) == 3)
	{
		ft_3_elements(list_pack);
		return (1);
	}
	tmp = *(list_pack.pile_a);
	// if (tmp->next == ft_find_element_max(tmp))
	// 	ft_move("sa", list_pack);
	// if (tmp->index > tmp->next->index && tmp != ft_find_element_max(tmp))
	// 	ft_move("sa", list_pack);
	if (tmp->index > tmp->next->index)
		ft_move("sa", list_pack);
	return (0);
}

t_list	*ft_get_pile_ascending_create_simulation(t_push_swap list_pack)
{
	int		n;
	int		current_index;
	t_list	*simulation_tmp;
	t_list	*tmp;
	t_list	*tmp_zero;

	n = ft_get_while_number(*list_pack.pile_a);
	simulation_tmp = ft_lstdup(*list_pack.pile_a);
	current_index = 0;
	while (simulation_tmp->prev->index != 0)
		ft_operation_simulation('r', &simulation_tmp);
	tmp = simulation_tmp;
	tmp_zero = tmp;
	while (tmp->next->index != 0)
	{
		tmp = simulation_tmp;
		tmp = ft_find_smaller_index(tmp, current_index, n);
		if (!tmp)
		{
			ft_push_all_between(&simulation_tmp, tmp_zero);
			break ;
		}
		current_index = tmp->index;
		ft_push_all_between(&simulation_tmp, tmp);
	}
	tmp = simulation_tmp;
	if (tmp && tmp->index != 0)
	{
		if (tmp->index > 0 && tmp->index < tmp->next->next->index)
			ft_operation_simulation('s', &simulation_tmp);
		else if (tmp->index > tmp->prev->index)
			ft_operation_simulation('r', &simulation_tmp);
		else
			ft_operation_simulation('p', &simulation_tmp);
	}
	return (simulation_tmp);
}

int	ft_lstchr(t_list *simulation, t_list *tmp)
{
	int		i;
	int		simulation_size;
	t_list	*tmp_simulation;

	i = 0;
	simulation_size = ft_lstsize(simulation);
	tmp_simulation = simulation;
	i = 0;
	while (i < simulation_size)
	{
		if (tmp->index == tmp_simulation->index)
		{
			return (1);
		}
		++i;
		tmp_simulation = tmp_simulation->next;
	}
	return (0);
}

void	ft_move_from_simulation(t_push_swap p, t_list *simulation)
{
	t_list	*tmp;
	t_list	*zero;
	int		n;

	n = 0;
	tmp = *p.pile_a;
	zero = tmp;
	while (zero->index != 0 && ++n != -1)
		zero = zero->next;
	if (n <= (ft_lstsize(*p.pile_a) / 2) || n == 0)
	{
		// printf("RA\n");
		while (tmp->index != 0)
		{
			if (tmp->index == 0)
				ft_move("ra", p);
			else if (ft_lstchr(simulation, tmp) == 1)
			{
				if (tmp->prev->index > tmp->index && tmp->next->index == 0)
					ft_move("sa", p);
				else if (tmp->prev->index > tmp->index
					&& tmp->next->index > tmp->index
					&& ft_lstchr(simulation, tmp->prev) == 1
					&& ft_lstchr(simulation, tmp->next) == 1)
					ft_move("sa", p);
				ft_move("ra", p);
			}
			else
				ft_move("pb", p);
			tmp = *p.pile_a;
		}
	}
	else
	{
		// printf("RRA\n");
		while (tmp->index != 0)
		{
			if (tmp->index == 0)
				ft_move("rra", p);
			else if (ft_lstchr(simulation, tmp) == 1)
			{
				if (tmp->prev->index > tmp->index && tmp->next->index == 0)
					ft_move("sa", p);
				else if (tmp->prev->index > tmp->index
					&& tmp->next->index > tmp->index
					&& ft_lstchr(simulation, tmp->prev) == 1
					&& ft_lstchr(simulation, tmp->next) == 1)
					ft_move("sa", p);
				ft_move("rra", p);
			}
			else
				ft_move("pb", p);
			tmp = *p.pile_a;
		}
	}
	// ft_print_piles("TEST", p);
	if (tmp->next == ft_find_element_max(*p.pile_a))
		ft_move("sa", p);
	ft_move("ra", p);
}

void	ft_get_pile_ascending_simulation(t_push_swap list_pack)
{
	t_list		*simulation_tmp;

	if (ft_check_obvious(list_pack) == 1)
		return ;
	simulation_tmp = ft_get_pile_ascending_create_simulation(list_pack);
	ft_move_from_simulation(list_pack, simulation_tmp);
	// ft_print_piles("", list_pack);
	ft_check_obvious(list_pack);
	if (ft_is_ascending(*list_pack.pile_a) && !(*list_pack.pile_b))
		return ;
	// printf("PATATE\n");
	// ft_print_piles("", list_pack);
	ft_get_pile_ascending(list_pack);
}
