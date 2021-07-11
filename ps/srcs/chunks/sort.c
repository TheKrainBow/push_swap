/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:09:33 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/07/12 01:22:15 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunk(t_data *data, int n)
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
	highest_b(data);
	generate_moves(data);
	while (data->b->size)
		pa(data);
	free_stack(data->b);
}
