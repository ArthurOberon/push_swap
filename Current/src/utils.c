/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:37:41 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/19 15:45:58 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		length;
	char	*result;

	length = ft_strlen(s);
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	length = 0;
	while (s[length])
	{
		result[length] = s[length];
		length++;
	}
	result[length] = '\0';
	return (result);
}

int	ft_check_obvious(t_push_swap list_pack)
{
	t_list	*tmp;

	if (ft_lstsize(*list_pack.pile_a) == 3)
	{
		ft_3_elements(list_pack);
		return (1);
	}
	tmp = *(list_pack.pile_a);
	if (tmp->index > tmp->next->index)
		ft_move("sa", list_pack);
	return (0);
}
