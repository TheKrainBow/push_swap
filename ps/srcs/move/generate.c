/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:17:32 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/11/05 02:23:18 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_ope(int *ope)
{
	int		i;
	int		i_min;
	int		min;

	i = -1;
	i_min = 0;
	min = 90000;
	while (++i < 8)
	{
		if (i == 0 || (ope[i] < min))
		{
			min = ope[i];
			i_min = i;
		}
	}
	return (i_min);
}

void	best_operations(t_data *data, int i)
{
	if (i < 4)
	{
		data->ma = data->ma_f;
		data->mb = data->mb_f;
	}
	else
	{
		data->ma = data->ma_l;
		data->mb = data->mb_l;
		i -= 4;
	}
	if (i == 0)
	{
		data->ma->n_left = 0;
		data->mb->n_left = 0;
	}
	else if (i == 1)
	{
		data->ma->n_right = 0;
		data->mb->n_right = 0;
	}
	else if (i == 2)
	{
		data->ma->n_left = 0;
		data->mb->n_right = 0;
	}
	else if (i == 3)
	{
		data->ma->n_right = 0;
		data->mb->n_left = 0;
	}
}

void	apply_right(t_data *data)
{
	while (data->ma->n_left > 0 || data->mb->n_left > 0)
	{
		if (data->ma->n_left > 0 && data->mb->n_left > 0)
			rr(data);
		else
		{
			if (data->ma->n_left > 0)
				ra(data);
			if (data->mb->n_left > 0)
				rb(data);
		}
		data->ma->n_left--;
		data->mb->n_left--;
	}
}

void	apply_left(t_data *data)
{
	while (data->ma->n_right > 0 || data->mb->n_right > 0)
	{
		if (data->ma->n_right > 0 && data->mb->n_right > 0)
			rrr(data);
		else
		{
			if (data->ma->n_right > 0)
				rra(data);
			if (data->mb->n_right > 0)
				rrb(data);
		}
		data->ma->n_right--;
		data->mb->n_right--;
	}
}

void	calculate_operations(int *operations, t_move *ma, t_move *mb)
{
	*(operations + 0) = ft_max(ma->n_right, mb->n_right);
	*(operations + 1) = ft_max(ma->n_left, mb->n_left);
	*(operations + 2) = ma->n_right + mb->n_left;
	*(operations + 3) = ma->n_left + mb->n_right;
}

void	generate_moves(t_data *data)
{
	int		*operations;

	operations = malloc(sizeof(int) * 8);
	data->ma_f->n_right = data->a->size - data->ma_f->n_left;
	data->ma_l->n_right = data->a->size - data->ma_l->n_left;
	data->mb_f->n_left = data->b->size - data->mb_f->n_right;
	data->mb_l->n_left = data->b->size - data->mb_l->n_right;
	calculate_operations(operations, data->ma_f, data->mb_f);
	calculate_operations(operations + 4, data->ma_l, data->mb_l);
	best_operations(data, min_ope(operations));
	apply_right(data);
	apply_left(data);
	free(operations);
}
