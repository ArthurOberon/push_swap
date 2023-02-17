/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best_move_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoberon <aoberon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:24:45 by aoberon           #+#    #+#             */
/*   Updated: 2023/02/17 17:59:40 by aoberon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_best_move_s(t_push_swap p, t_best_move fastest)
{
	if (fastest.sb == 1 && fastest.sa == 1)
	{
		ft_move("ss", p);
		return (1);
	}
	else if (fastest.sa == 1 && fastest.size == 2)
	{
		ft_move("pa", p);
		ft_move("sa", p);
		return (2);
	}
	else if (fastest.sb == 1)
	{
		ft_move("sb", p);
		return (1);
	}
	return (0);
}

int	ft_do_best_move_rr(t_push_swap p, t_best_move fastest)
{
	int	i;

	i = 0;
	if (fastest.rota_dir_a >= 2 && fastest.rota_dir_b >= 2)
	{
		if (fastest.rota_dir_a >= fastest.rota_dir_b)
		{
			while (i++ < fastest.rota_dir_b)
				ft_move("rr", p);
			i = 0;
			while (i++ < fastest.rota_dir_a - fastest.rota_dir_b)
				ft_move("ra", p);
		}
		else
		{
			while (i++ < fastest.rota_dir_a)
				ft_move("rr", p);
			i = 0;
			while (i++ < fastest.rota_dir_b - fastest.rota_dir_a)
				ft_move("rb", p);
		}
		return (1);
	}
	return (0);
}

int	ft_do_best_move_rrr(t_push_swap p, t_best_move fastest)
{
	int	i;

	i = 0;
	if (fastest.rota_dir_a <= -1 && fastest.rota_dir_b <= -1)
	{
		if (-fastest.rota_dir_a >= -fastest.rota_dir_b)
		{
			while (i++ < -fastest.rota_dir_b)
				ft_move("rrr", p);
			i = 0;
			while (i++ < -fastest.rota_dir_a - -fastest.rota_dir_b)
				ft_move("rra", p);
		}
		else
		{
			while (i++ < -fastest.rota_dir_a)
				ft_move("rrr", p);
			i = 0;
			while (i++ < -fastest.rota_dir_b - -fastest.rota_dir_a)
				ft_move("rrb", p);
		}
		return (1);
	}
	return (0);
}

int	ft_do_best_move_ra(t_push_swap p, t_best_move fastest)
{
	int	i;

	i = 0;
	if (fastest.rota_dir_a != 0)
	{
		while (i++ < ft_abs(fastest.rota_dir_a))
		{
			if (fastest.rota_dir_a < 0)
				ft_move("rra", p);
			else
				ft_move("ra", p);
		}
		return (1);
	}
	return (0);
}

int	ft_do_best_move_rb(t_push_swap p, t_best_move fastest)
{
	int	i;

	i = 0;
	if (fastest.rota_dir_b != 0)
	{
		while (i++ < ft_abs(fastest.rota_dir_b))
		{
			if (fastest.rota_dir_b < 0)
				ft_move("rrb", p);
			else
				ft_move("rb", p);
		}
		return (1);
	}
	return (0);
}
