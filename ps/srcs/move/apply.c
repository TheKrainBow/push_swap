/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:18:14 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/07/12 01:21:49 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_both(t_data *data, t_move *ma, t_move *mb, int move)
{
	int		i;

	i = 0;
	while (ma->move == &ra && mb->move == &rb
		&& (ma->n > 0) && (mb->n > 0)
		&& (data->a->size > 1 && data->b->size > 1))
	{
		if (move)
			rr(data);
		ma->n--;
		mb->n--;
		i++;
	}
	while (ma->move == &rra && mb->move == &rrb
		&& (ma->n > 0)
		&& (mb->n > 0) && (data->a->size > 1 && data->b->size > 1))
	{
		if (move)
			rrr(data);
		ma->n--;
		mb->n--;
		i++;
	}
	return (i);
}

int	exec_one(t_data *data, t_move *mv, int size, int move)
{
	int		i;

	i = 0;
	while (mv->n > 0)
	{
		if (move && size > 1)
			mv->move(data);
		mv->n--;
		i++;
	}
	return (i);
}

int	exec_moves(t_data *data, t_move *ma, t_move *mb, int move)
{
	int		i;

	i = exec_both(data, ma, mb, move);
	i += exec_one(data, ma, data->a->size, move);
	i += exec_one(data, mb, data->b->size, move);
	return (i);
}
