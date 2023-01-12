/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:40:36 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/12 17:19:01 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_args(char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (!ft_isdigit(tab[i][j]))
			{
				ft_free_double_tab(tab);
				ft_putstr("ERROR\n");
				exit(EXIT_FAILURE);
			}
		}
		if (ft_atoi(tab[i]) > INT_MAX
			|| ft_atoi(tab[i]) < INT_MIN)
		{
			ft_free_double_tab(tab);
			ft_putstr("ERROR\n");
			exit(EXIT_FAILURE);
		}
	}
}

// void	ft_create_list(t_list **list, int argc, char **argv)
// {
// 	t_list	*tmp;
// 	char	**tab;
// 	int		i;
// 	int		j;

// 	i = 1;
// 	j = 0;
// 	if (argc == 2)
// 		tab = ft_split(argv[1], ' ');
// 	else
// 	{
// 		tab = malloc(sizeof(char *) * (argc));
// 		while (i < argc)
// 			tab[j++] = argv[i++];
// 	}
// 	ft_check_args(tab);
// 	if (argc != 2)
// 		argc -= 2;
// 	i = 0;
// 	j = 0;
// 	while (i++ <= argc)
// 	{
// 		tmp = ft_lstnew((int)ft_atoi(tab[j++]));
// 		ft_lstadd_back(list, tmp);
// 		ft_print_new_element(tmp);
// 	}
// }

char	*ft_malloc_zero(size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * size);
	if (!ptr)
		return (0);
	while (i < size)
		ptr[i++] = 0;
	return (ptr);
}

char	*ft_strcat(char *dst, char *src)
{
	size_t	i;
	size_t	dst_length;

	i = -1;
	dst_length = ft_strlen(dst);
	while (src[++i])
		dst[dst_length + i] = src[i];
	dst[dst_length + 1] = '\0';
	return (dst);
}

char	*ft_str_merge(char **str, int space, int size)
{
	char	*result;
	size_t	length;
	int		i;
	int		j;

	i = 0;
	j = 0;
	length = 0;
	while (i < size)
		length += ft_strlen(str[i++]) + space;
	length -= space;
	result = ft_malloc_zero(length + 1);
	i = 0;
	while (i < size)
	{
		ft_strcat(result, str[i++]);
		while (str[j])
			j++;
		if (i < size && space)
			result[j] = ' ';
	}
	return (result);
}

int	ft_lst_add(t_list **lst, int value)
{
	t_list	*new;
	t_list	*tmp;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->value = value;
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

int	ft_protect_atoi(char *str, int *nbr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 0;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + sign * (str[i++] - '0');
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	*nbr = (int)result;
	return (1);
}

int	ft_split_atoi(char *str, t_list **lst)
{
	int		i;
	int		error;
	int		nbr;
	t_list	*tmp;

	i = 0;
	nbr = 0;
	error = 0;
	while (error && str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| str[i] == '-' || str[i] == '+')
		{
			error = ft_protect_atoi(str + i, &nbr);
			error = ft_lst_add(lst, nbr);
			tmp = *lst;
			while (error && tmp != (*lst)->prev)
			{
				error = !(tmp->value == (*lst)->prev->value);
				tmp = tmp->next;
			}
			i += (str[i] == '-' || str[i] == '+');
			while (error && ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (error);
}

int	ft_parse(char *str, t_list **lst)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i])
			&& str[i] != '+' && str[i] != '-')
			return (-1);
		i++;
	}
	if (!ft_split_atoi(str, lst))
		return (-1);
	return (0);
}
