/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:59:39 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/13 22:07:59 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_push_swap(t_list	lst_a, t_list lst_b)
// {
// }

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	*str;

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
	printf("ARGC = %d AND ARGV => \n", argc);
	ft_print_tab(argv);
	printf("=====CREATE STR WITH ARGV=====\n");
	str = ft_str_merge(argv, 1, argc - 1);
	printf("=====PRINT STR=====\n");
	printf("\"%s\"\n", str);
	ft_parse(str, &lst_a);
	ft_print_list(&lst_a);
	return (EXIT_SUCCESS);
}
