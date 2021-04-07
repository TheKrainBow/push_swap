/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:16:57 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/04/07 01:38:41 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	highest_b(t_data *data)
{
	int		i;

	i = 0;
	while (data->b->stack[i] != data->b->max)
		i++;
	if (i != data->b->size - 1)
	{
		data->mb[0]->move = rrb;
		data->mb[0]->n = i + 1;
	}
	else
		data->mb[0]->n = 0;
}

void	best_move_for_b(t_data *data)
{
	int		i;
	int		maxed;

	maxed = 0;
	if (data->b->size <= 1)
		return ;
	i = data->b->size;
	while (--i >= 0)
		if (check_b_insert(data, i))
			break ;
	if (i != -1)
	{
		data->mb[0]->move = rrb;
		data->mb[0]->n = i;
		return ;
	}
	else
		highest_b(data);
}

int		check_b_insert(t_data *data, int index)
{
	int		prev;

	prev = index - 1;
	if (index == 0)
		prev = data->b->size - 1;
	if (data->b->stack[index] > data->ma[0]->value
	&& data->b->stack[prev] < data->ma[0]->value)
		return (1);
	return (0);
}
