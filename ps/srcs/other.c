/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 01:31:02 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/11/05 02:45:23 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_i(int size)
{
	if (size < 100)
		return (0);
	else if (size < 500)
		return (14);
	return (31);
}

int	find_best_chunk_size(t_data *data, t_stack *temp)
{
	int				i;
	int				min;
	int				i_min;

	i = init_i(temp->size);
	i_min = i;
	min = 1;
	while (++i < temp->size && i < 60 && (i - i_min <= 7))
	{
		data->a = copy(temp);
		data->n_ope = 0;
		data->chunked_a = chunk_stack(data, data->sorted_a, i, 0);
		sort_chunk(data, data->n_chunk);
		if (min == 1 || data->n_ope < min)
		{
			min = data->n_ope;
			i_min = i;
		}
		free(data->chunked_a);
		free_stack(data->a);
	}
	data->a = copy(temp);
	data->n_ope = 0;
	return (i_min);
}

void	sort_three(t_data *data)
{
	int		a;
	int		b;
	int		c;

	a = data->a->stack[2];
	b = data->a->stack[1];
	c = data->a->stack[0];
	if (a > b && b > c)
	{
		sa(data);
		rra(data);
	}
	else if (a < b && b > c && c > a)
	{
		rra(data);
		sa(data);
	}
	else if (a < b && b > c && c < a)
		rra(data);
	else if (a > b && b < c && a < c)
		sa(data);
	else if (a > b && b < c && a > c)
		ra(data);
}
