/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:39:35 by krain             #+#    #+#             */
/*   Updated: 2021/11/03 00:40:02 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_best_move_a(t_data *data, int i)
{
	void	(*move)(t_data *);

	if (i > data->a->size / 2)
	{
		move = &ra;
		i = data->a->size - i;
	}
	else
		move = &rra;
	while (i > 0)
	{
		move(data);
		i--;
	}
}

int	check_a_insert(t_data *data, int index)
{
	int		prev;

	prev = index + 1;
	if (index == data->a->size - 1)
		prev = 0;
	if (data->a->stack[index] > data->b->stack[data->b->size - 1]
		&& data->a->stack[prev] < data->b->stack[data->b->size - 1])
		return (1);
	return (0);
}

int	find_max_index(int *stack, int len)
{
	int		i;
	int		ret;
	int		max;

	i = -1;
	max = 0;
	while (++i < len)
	{
		if (i == 0 || max < stack[i])
		{
			ret = i;
			max = stack[i];
		}
	}
	return (ret);
}

void	five_setup_a(t_data *data)
{
	int		i;

	if (data->a->size < 2)
		return ;
	i = -1;
	while (++i < data->a->size)
		if (check_a_insert(data, i))
			break ;
	if (i == data->a->size)
		i = find_max_index(data->a->stack, data->a->size);
	else
		i++;
	apply_best_move_a(data, i);
}
