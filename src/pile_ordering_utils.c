/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_ordering_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:01:48 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/09 08:31:06 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_obvious(t_push_swap list_pack)
{
	t_list	*tmp;

	if (ft_lstsize(*list_pack.pile_a) == 3)
		ft_3_elements(list_pack);
	tmp = *(list_pack.pile_a);
	if (tmp->index > tmp->next->index)
		ft_move("sa", list_pack);
}

t_list	**ft_listdup(t_list *src, int malloc_size)
{
	t_list	**dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(t_list *) * malloc_size);
	if (!dst)
		return (NULL);
	dst[0] = src;
	dst[1] = src;
	while (i < malloc_size)
	{
		dst[i]->next = src->next;
		dst[i]->prev = src->prev;
		dst[i]->value = src->value;
		dst[i]->index = src->index;
		i++;
	}
	return (dst);
}

void	ft_listcpy(t_list **dst, t_list **src)
{
	dst[0] = src[0];
	dst[1] = src[1];
}
