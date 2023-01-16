/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:43:31 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/16 16:50:06 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*\*/

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

	if ((*lst) == NULL)
		return ;
	first = (*lst);
	ft_putstr("=====PRINT_LIST=====\n");
	ft_putstr("==START==\n");
	printf("[prev]<-[tmp]->[next]\n");
	printf("[%d]<---[%d]--->[%d]\n", first->prev->value, first->value,
		first->next->value);

	ft_putstr("\n====================\n");
	tmp = first->next;
	while (tmp != first)
	{
		ft_putstr("\nNext : \n");
		printf("[prev]<-[tmp]->[next]\n");
		printf("[%d]<---[%d]--->[%d]\n", tmp->prev->value, tmp->value, 
			tmp->next->value);
		ft_putstr("\n====================\n");
		tmp = tmp->next;
	}
	ft_putstr("==END==\n");
}

void	ft_print_list_instruction(t_instruction **lst)
{
	t_instruction	*tmp;
	int				i;

	i = 0;
	if ((*lst) == NULL)
		return ;
	tmp = (*lst);
	ft_putstr("=====PRINT_LIST_INSTRUCTION=====\n");
	ft_putstr("==START==\n");
	ft_putstr("\n====================\n");
	while (tmp != NULL)
	{
		ft_putstr("\nNext : \n");
		printf("operation = [%s] (%d)eme element\n", tmp->operation, i);
		ft_putstr("\n====================\n");
		tmp = tmp->next;
		i++;
	}
	ft_putstr("==END==\n");
}

void	ft_print_new_element(t_list *tmp)
{
	printf("\n	===New element===\n	");
	printf("	value's tmp = [%d]\n	", tmp->value);
	printf("	address' tmp = [%p]\n	", tmp);
	printf("	next's tmp = [%p]\n	", tmp->next);
	printf("	prev's tmp = [%p]\n	", tmp->prev);
	printf("resume :\n		[prev]<-[tmp]->[next]\n	");
	printf("	  [%d]<---[%d]--->[%d]\n", tmp->prev->value,
		tmp->value, tmp->next->value);
	printf("	===New element END===\n\n");
}

void	ft_print_new_element_instruction(t_instruction *tmp)
{
	printf("\n	===New element===\n	");
	printf("	operation's tmp = \"%s\"\n	", tmp->operation);
	printf("	address' tmp = [%p]\n	", tmp);
	printf("	next's tmp = [%p]\n	", tmp->next);
	printf("	===New element END===\n\n");
}
/**/
