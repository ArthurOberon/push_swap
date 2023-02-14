/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:40:36 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/14 14:45:31 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lst_add(t_list **lst, int value)
{
	t_list	*new;
	t_list	*tmp;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->value = value;
	new->index = 0;
	if (!*lst)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		tmp = (*lst)->prev;
		(*lst)->prev = new;
		new->next = (*lst);
		new->prev = tmp;
		tmp->next = new;
	}
	return (1);
}

static int	ft_protect_atoi(char *str, int *nbr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[0] == '-')
		sign *= -1;
	i += (str[0] == '-' || str[0] == '+');
	while (ft_isdigit(str[i]))
		result = result * 10 + sign * (str[i++] - '0');
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	*nbr = (int)result;
	return (1);
}

static int	ft_split_atoi(char *str, t_list **lst, int security)
{
	int		i;
	int		nbr;
	t_list	*tmp;

	i = 0;
	while (security && str[i])
	{
		if ((ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+') && str[i + 1] != 'v')
		{
			security = security & ft_protect_atoi(str + i, &nbr);
			security = security & ft_lst_add(lst, nbr);
			tmp = *lst;
			while (security && tmp != (*lst)->prev)
			{
				security = security & !(tmp->value == (*lst)->prev->value);
				tmp = tmp->next;
			}
			i += (str[i] == '-' || str[i] == '+');
			while (security && ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (security);
}

int	ft_parse(char *str, t_list **lst, int *visualize)
{
	int	i;

	*visualize = -1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	*visualize = (str[i] == '-' && str[i + 1] == 'v'
			&& !ft_isdigit(str[i + 2]));
	i += *visualize * 2;
	if (str[0] == '\0')
		return (-1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i])
			&& !((str[i] != '+' || str[i] != '-') && ft_isdigit(str[i + 1])
				&& !ft_isdigit(str[i - 1])))
			return (-1);
		i++;
	}
	if (!ft_split_atoi(str, lst, 1))
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}
