/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:11:34 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/11/04 23:52:33 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk	*chunk_stack(t_data *data, t_stack *a, int n, int print)
{
	int			i;
	t_chunk		*dest;

	if (n <= 0)
		n = 1;
	data->n_chunk = (int)(a->size / n);
	if ((a->size % n))
		(data->n_chunk)++;
	dest = malloc(sizeof(t_chunk) * (data->n_chunk));
	i = 0;
	while (++i < data->n_chunk)
	{
		dest[i - 1].max = a->stack[a->size - 1 - (i * n)];
	}
	dest[data->n_chunk - 1].max = a->stack[0];
	i = -1;
	while (print && ++i < data->n_chunk)
		printf("%d/", dest[i].max);
	if (print)
		printf("\n");
	return (dest);
}
