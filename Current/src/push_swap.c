/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:10:29 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/13 11:15:50 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list			*lst_a;
	char			*str;

	lst_a = NULL;
	if (argc == 1)
	{
		ft_putstr_fd("Too few arguments.\n", 1);
		ft_putstr_fd("Please use push_swap with this format :\n", 1);
		ft_putstr_fd("./push_swap \"0 1 2\" or ./push_swap 0 1 2\n", 1);
		return (1);
	}
	str = ft_str_merge(argv + 1, 1, argc - 1);
	if (ft_parse(str, &lst_a) == -1)
	{
		ft_lstclear(&lst_a);
		ft_putstr_fd("Error with the parsing\n", 2);
		return (1);
	}
	return (0);
}
