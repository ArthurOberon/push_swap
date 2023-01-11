/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:40:36 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/11 19:52:12 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	ft_create_list(t_list **list, int argc, char **argv)
{
	t_list	*tmp;
	char	**tab;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
	{
		tab = malloc(sizeof(char *) * (argc));
		while (i < argc)
			tab[j++] = argv[i++];
	}
	ft_check_args(tab);
	if (argc != 2)
		argc -= 2;
	i = 0;
	j = 0;
	while (i++ <= argc)
	{
		tmp = ft_lstnew((int)ft_atoi(tab[j++]));
		ft_lstadd_back(list, tmp);
		ft_print_new_element(tmp);
	}
}
