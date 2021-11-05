/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:16:13 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/11/05 02:47:20 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_first(t_data *data, int n)
{
	int i;

	data->first = -1;
	i = data->a->size;
	while (--i >= 0 && data->first == -1)
		if (data->a->stack[i] <= data->chunked_a[n].max)
			data->first = i;
	if (data->first == -1)
		return ;
	data->ma_f->value = data->a->stack[data->first];
	data->first = (data->a->size - data->first - 1);
	data->ma_f->n_left = data->first;
}


void	find_last(t_data *data, int n)
{
	int i;

	data->last = -1;
	i = -1;
	while (++i < data->a->size && data->last == -1)
		if (data->a->stack[i] <= data->chunked_a[n].max)
			data->last = i;
	if (data->last == -1)
		return ;
	data->ma_l->value = data->a->stack[data->last];
	data->last = (data->a->size - data->last - 1);
	data->ma_l->n_left = data->last;
}

void	best_move_for_a(t_data *data, int n)
{
	if (data->a->size == 1)
	{
		data->ma_f->n_left = 0;
		data->ma_f->value = data->a->stack[0];
		data->first = 0;
		data->ma_l->n_left = 0;
		data->ma_l->value = data->a->stack[0];
		data->last = 0;
		return ;
	}
	find_first(data, n);
	find_last(data, n);
}

//6442 500 2