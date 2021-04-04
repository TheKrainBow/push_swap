/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:16:13 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/04/04 16:16:36 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_move_for_a(t_data *data, int n)
{
	int		i;

	if (data->a->size == 1)
	{
		data->ma[0]->n = 0;
		data->ma[0]->value = data->a->stack[0];
		data->first = 0;
		return ;
	}
	data->first = -1;
	i = data->a->size;
	while (--i >= 0 && data->first == -1)
		if (data->a->stack[i] >= data->chunked_a[n].min && data->a->stack[i] <= data->chunked_a[n].max)
			data->first = i;
	if (data->first == -1)
		return ;
	data->first = (data->a->size - data->first - 1);
	data->ma[0]->move = ra;
	data->ma[0]->n = data->first;
	data->ma[0]->value = data->a->stack[i + 1];
}