/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:54:24 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/11/05 03:00:22 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	free_stack(t_stack *a)
{
	free(a->stack);
	free(a);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->a = malloc(sizeof(t_stack));
	data->a->stack = NULL;
	data->ma_f = malloc(sizeof(t_move));
	data->ma_l = malloc(sizeof(t_move));
	data->mb_f = malloc(sizeof(t_move));
	data->mb_l = malloc(sizeof(t_move));
	data->ma_f->n_left = 0;
	data->ma_f->n_right = 0;
	data->mb_f->n_left = 0;
	data->mb_f->n_right = 0;
	data->mb_l->n_left = 0;
	data->mb_l->n_right = 0;
	data->print = 0;
	data->flags = malloc(sizeof(t_flags));
	data->flags->random = 0;
	data->flags->visualize = 0;
	data->flags->color = 0;
	return (data);
}

void	free_data(t_data *data, int free_power)
{
	if (free_power >= 2)
		free(data->a->stack);
	if (free_power >= 1)
	{
		free(data->a);
		free(data->ma_f);
		free(data->ma_l);
		free(data->mb_f);
		free(data->mb_l);
		ft_free_tab(data->flags->args);
		free(data->flags);
	}
	if (free_power >= 3)
	{
		free(data->chunked_a);
		free_stack(data->sorted_a);
	}
	free(data);
}
