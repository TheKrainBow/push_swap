/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:18:14 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/04/04 16:18:36 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			exec_moves(t_data *data, t_move *ma, t_move *mb, int move)
{
	int		i;

	i = 0;
	while (ma->move == &ra && mb->move == &rb
	&& (ma->n > 0) && (mb->n > 0) && (data->a->size > 1 && data->b->size > 1))
	{
		if (move)
			rr(data);
		ma->n--;
		mb->n--;
		i++;
	}
	while (ma->move == &rra && mb->move == &rrb
	&& (ma->n > 0) && (mb->n > 0) && (data->a->size > 1 && data->b->size > 1))
	{
		if (move)
			rrr(data);
		ma->n--;
		mb->n--;
		i++;
	}
	while (ma->n > 0)
	{
		if (move && data->a->size > 1)
			ma->move(data);
		ma->n--;
		i++;
	}
	while (mb->n > 0)
	{
		if (move && data->b->size > 1)
			mb->move(data);
		mb->n--;
		i++;
	}
	return (i);
}