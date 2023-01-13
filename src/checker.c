/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:55:15 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/13 22:09:12 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_checker(t_list lst_a, t_list lst_b)
// {
// }

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	*str;

	(void)argv;
	lst_a = NULL;
	lst_b = NULL;
	if (argc == 1)
	{
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
	str = ft_str_merge(argv + 1, 1, argc - 1);
	ft_parse(str, &lst_a);
	return (0);
}
