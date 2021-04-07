/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:17:32 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/04/07 01:39:17 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		revers_moves(t_data *data)
{
	if (data->ma[0]->move == &ra)
		data->ma[1]->move = &rra;
	else
		data->ma[1]->move = &ra;
	if (data->mb[0]->move == &rb)
		data->mb[1]->move = &rrb;
	else
		data->mb[1]->move = &rb;
	data->ma[1]->n = data->a->size - data->ma[0]->n;
	data->mb[1]->n = data->b->size - data->mb[0]->n;
}

void		generate_moves(t_data *data)
{
	int		moves;
	int		n[2];
	int		i;
	int		i_temp;
	int		min;

	revers_moves(data);
	n[0] = data->ma[0]->n;
	n[1] = data->mb[0]->n;
	i = -1;
	while (++i < 4)
	{
		n[0] = data->ma[ind(i, 'a')]->n;
		n[1] = data->mb[ind(i, 'b')]->n;
		moves = exec_moves(data, data->ma[ind(i, 'a')],
		data->mb[ind(i, 'b')], 0);
		if (moves < min || i == 0)
		{
			i_temp = i;
			min = moves;
		}
		data->ma[ind(i, 'a')]->n = n[0];
		data->mb[ind(i, 'b')]->n = n[1];
	}
	exec_moves(data, data->ma[ind(i_temp, 'a')], data->mb[ind(i_temp, 'b')], 1);
}
