/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:59:39 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/11 19:52:05 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	ft_push_swap(t_list	lst_a, t_list lst_b)
// {
// }

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	(void)lst_b;
	if (argc == 1)
	{
		ft_putstr("Too few arguments.\n");
		ft_putstr("Please use push_swap with this format :\n");
		ft_putstr("./push_swap \"0 1 2\" or ./push_swap 0 1 2\n");
		return (EXIT_FAILURE);
	}
	printf("ARGC = %d AND ARGV = \n", argc);
	ft_print_tab(argv);
	printf("=====create lst_a=====\n");
	ft_create_list(&lst_a, argc, argv);
	printf("=====print lst_a=====\n");
	ft_print_list(&lst_a);
	return (EXIT_SUCCESS);
}
