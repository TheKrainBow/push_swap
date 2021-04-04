/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:09:33 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/04/04 16:13:09 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_chunk(t_data *data, int n)
{
	int			i;

	data->b = malloc(sizeof(t_stack));
	data->b->stack = malloc(sizeof(int) * (data->a->size));
	data->b->size = 0;
	i = -1;
	while (++i < n)
	{
		data->first = 1;
		while (data->first != -1)
		{
			best_move_for_a(data, i);
			if (data->first == -1)
				break ;
			best_move_for_b(data);
			generate_moves(data);
			pb(data);
			clear_move(data);
		}
	}
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
	data->ma[0]->n = 0;
	generate_moves(data);
	while (data->b->size)
		pa(data);
	free(data->b->stack);
	free(data->b);
}