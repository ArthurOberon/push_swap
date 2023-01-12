/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:43:31 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/12 12:04:35 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = -1;
	printf("=====PRINT TAB=====\n");
	while (tab[++i])
		printf("tab[%d] = \"%s\"\n", i, tab[i]);
	printf("=====PRINT TAB FINISHED=====\n");
}

void	ft_print_list(t_list **lst)
{
	t_list	*first;
	t_list	*tmp;

	first = (*lst);
	ft_putstr("START : \n");
	printf("[prev]<-[tmp]->[next]\n");
	printf("[%d]<---[%d]--->[%d]\n", first->prev->value, first->value, first->next->value);
	ft_putstr("\n====================\n");
	tmp = first->next;
	while (tmp != first)
	{
		ft_putstr("########\nNext : \n");
		printf("[prev]<-[tmp]->[next]\n");
		printf("[%d]<---[%d]--->[%d]\n", tmp->prev->value, tmp->value, tmp->next->value);
		ft_putstr("\n====================\n");
		tmp = tmp->next;
	}
	ft_putstr("END\n");
}

void	ft_print_new_element(t_list *tmp)
{
	printf("\n	===New element===\n	");
	printf("	value's tmp = [%d]\n	", tmp->value);
	printf("	address' tmp = [%p]\n	", tmp);
	printf("	next's tmp = [%p]\n	", tmp->next);
	printf("	prev's tmp = [%p]\n	", tmp->prev);
	printf("resume :\n		[prev]<-[tmp]->[next]\n	");
	printf("	  [%d]<---[%d]--->[%d]\n", tmp->prev->value, tmp->value, tmp->next->value);
	printf("	===New element END===\n\n");
}
