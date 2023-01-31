/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:43:31 by aoberon           #+#    #+#             */
/*   Updated: 2023/01/31 11:30:22 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*\*/

#include "push_swap.h"

void	ft_print_tab_int(int *tab, int size)
{
	int	i;

	i = -1;
	printf("=====PRINT TAB INT=====\n");
	while (++i < size)
		printf("tab[%d] = [%d]\n", i, tab[i]);
	printf("=====PRINT TAB INT FINISHED=====\n");
}

void	ft_print_tab(char **tab)
{
	int	i;

	i = -1;
	printf("=====PRINT TAB=====\n");
	while (tab[++i])
		printf("tab[%d] = \"%s\"\n", i, tab[i]);
	printf("=====PRINT TAB FINISHED=====\n");
}

void	ft_print_list_one_line(t_list **lst)
{
	t_list	*first;
	t_list	*tmp;
		
	if ((*lst) == NULL)
		return ;
	first = (*lst);
	ft_putstr("=====PRINT_LIST ON ONE LINE=====\n");
	printf("first : [%d]-->", first->value);
	tmp = first->next;
	while (tmp != first)
	{
		// printf("------ FIRST = [%d]\n ------", first->value);
		printf("[%d]-->", tmp->value);
		tmp = tmp->next;
	}
	printf(": last\n");
	ft_putstr("======= END =======\n");
}

void	ft_print_list_instruction_one_line(t_instruction **lst)
{
	t_instruction	*tmp;
		
	if ((*lst) == NULL)
		return ;
	ft_putstr("=====PRINT_LIST_INSTRUCTION ON ONE LINE=====\n");
	tmp = *lst;
	printf("first :");
	while (tmp)
	{
		// printf("------ FIRST = [%d]\n ------", first->operation);
		printf("[%s]-->", tmp->operation);
		tmp = tmp->next;
	}
	printf(": last\n");
	ft_putstr("======= END =======\n");
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
		// printf("------ FIRST = [%d]\n ------", first->value);
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
	printf("	operation's new = \"%s\"\n	", tmp->operation);
	printf("	address' new = [%p]\n	", tmp);
	printf("	next's new = [%p]\n	", tmp->next);
	printf("	===New element END===\n\n");
}



void	ft_print_piles(char *str, t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp_a;
	int		size_a;
	t_list	*tmp_b;
	int		size_b;
	int		i;
	int		width;

	i = 0;
	width = 22;
	size_a = ft_lstsize(lst_a);
	size_b = ft_lstsize(lst_b);
	tmp_a = *lst_a;
	tmp_b = *lst_b;
	printf("OPERATION : \"%s\"\n", str);
	if (size_a >= size_b)
	{
		while (size_a != size_b)
		{
			printf("%*d [%d]\n", (width / 2), tmp_a->value,tmp_a->index);
			tmp_a = tmp_a->next;
			size_a--;
		}
		while (size_a && size_b)
		{
			printf("%*d [%d]%*d [%d]\n", (width / 2), tmp_a->value,
				tmp_a->index, width - (width / 6), tmp_b->value, tmp_b->index);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
			size_a--;
			size_b--;
		}
	}
	else
	{
		while (size_b != size_a)
		{
			printf("%*d [%d]\n", (width / 2), tmp_b->value,tmp_b->index);
			tmp_b = tmp_b->next;
			size_b--;
		}
		while (size_a && size_b)
		{
			printf("%*d [%d]%*d [%d]\n", (width / 2), tmp_a->value,
				tmp_a->index, width - (width / 6), tmp_b->value, tmp_b->index);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
			size_a--;
			size_b--;
		}
	}
	while (i++ < width * 2)
		printf("_");
	printf("\n");
	printf("%*s%*s", (width / 2) + (width / 6), "STACK A", width + 1, "STACK B");
	printf("\n\n");
}

/**/
