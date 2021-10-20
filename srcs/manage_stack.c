/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:00:49 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/10/05 18:17:30 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stack	*copy(t_stack *a)
{
	t_stack		*dest;
	int			i;

	dest = malloc(sizeof(t_stack));
	dest->stack = malloc(sizeof(int) * (a->size));
	i = -1;
	while (++i < a->size)
		dest->stack[i] = a->stack[i];
	dest->max = a->max;
	dest->min = a->min;
	dest->size = a->size;
	return (dest);
}

void	sort_stack(t_stack *a)
{
	int			swaped;
	int			i;

	swaped = 1;
	while (swaped)
	{
		swaped = 0;
		i = -1;
		while (++i < a->size - 1)
		{
			if (a->stack[i] < a->stack[i + 1])
			{
				ft_swap(&a->stack[i], &a->stack[i + 1]);
				swaped = 1;
			}
		}
	}
}

int	top_stack(t_stack *a)
{
	return (a->stack[a->size - 1]);
}

int	checker(t_stack *a, int correct_size, int print, int color)
{
	int			i;

	if (print && color)
		printf(BRED);
	if (a->size == correct_size)
	{
		i = -1;
		while (++i < a->size - 1)
		{
			if (a->stack[i] < a->stack[i + 1])
			{
				if (print)
					printf("KO\n");
				return (0);
			}
		}
		if (print && color)
			printf(BGREEN);
		if (print)
			printf("OK\n");
		return (1);
	}
	if (print)
		printf("KO\n");
	return (0);
}
