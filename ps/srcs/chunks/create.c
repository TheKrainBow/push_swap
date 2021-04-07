/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:11:34 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/04/07 01:43:37 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk		*chunk_stack(t_data *data, t_stack *a, int n, int print)
{
	int			i;
	t_chunk		*dest;

	data->n_chunk = (int)(a->size / n);
	if ((a->size % n))
		(data->n_chunk)++;
	dest = malloc(sizeof(t_chunk) * (data->n_chunk));
	i = -1;
	while (++i < data->n_chunk)
	{
		dest[i].min = a->stack[a->size - 1 - (i * n)];
		dest[i].max = a->stack[a->size - 1 - ((i * n) + n - 1)];
	}
	dest[0].min = a->stack[a->size - 1];
	dest[data->n_chunk - 1].max = a->stack[0];
	i = -1;
	while (print && ++i < data->n_chunk)
		printf("[%d;%d]", dest[i].min, dest[i].max);
	if (print)
		printf("\n");
	return (dest);
}
