/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:16:57 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/11/05 02:40:37 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	highest_b(t_data *data, t_move *mb)
{
	int		i;

	i = 0;
	while (data->b->stack[i] != data->b->max)
		i++;
	if (i != data->b->size - 1)
		mb->n_right = i + 1;
	else
		mb->n_right = 0;
}

void	best_move_for_b(t_data *data, t_move *mb, int value)
{
	int		i;
	int		maxed;

	maxed = 0;
	if (data->b->size <= 1)
		return ;
	i = data->b->size;
	while (--i >= 0)
		if (check_b_insert(data, i, value))
			break ;
	if (i != -1)
		mb->n_right = i;
	else
		highest_b(data, mb);
}

int	check_b_insert(t_data *data, int index, int value)
{
	int		prev;

	prev = index - 1;
	if (index == 0)
		prev = data->b->size - 1;
	if (data->b->stack[index] > value
		&& data->b->stack[prev] < value)
		return (1);
	return (0);
}
