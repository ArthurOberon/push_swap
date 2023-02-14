/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autoplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:33:02 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/14 17:34:26 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

int	ft_autoplay(t_data *data)
{
	t_instruction	*tmp;
	int				*delay_tab;

	delay_tab = (int [9]){1, 5, 15, 30, 50, 75, 100, 200, 500};
	tmp = (*data->p.instructions);
	printf("%d\n", data->autoplay);
	if (data->autoplay == 1)
	{
		printf("TEST\n");
		if (!tmp->prev)
			data->direction = 1;
		if (data->direction == 1 && tmp->next)
		{
			printf("next auto\n");
			ft_do_operation(tmp->operation, data->p.pile_a,
				data->p.pile_b);
			tmp = tmp->next;
		}
		else if (data->direction == -1 && tmp->prev)
		{
			printf("prev auto\n");
			tmp = tmp->prev;
			ft_do_operation(ft_invert_operation(tmp->operation), data->p.pile_a,
				data->p.pile_b);
		}
		else
			data->autoplay = 0;
		printf("GONNA SLEEP\n");
		sleep(2);
		// delay_tab[data->delay];
		printf("GOOD MORNING\n");
		(*data->p.instructions) = tmp;
	}
	return (0);
}
