/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversed_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 02:22:53 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/07/12 01:27:23 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rra(t_data *d)
{
	int			temp;
	int			i;

	temp = d->a->stack[0];
	i = -1;
	while (++i < d->a->size - 1)
		d->a->stack[i] = d->a->stack[i + 1];
	d->a->stack[i] = temp;
	if (d->print && d->flags->color)
		printf(BRED);
	if (d->print)
		printf("rra\n");
	print_stacks(d, 1);
	d->n_ope++;
}

void	rrb(t_data *d)
{
	int			temp;
	int			i;

	temp = d->b->stack[0];
	i = -1;
	while (++i < d->b->size - 1)
		d->b->stack[i] = d->b->stack[i + 1];
	d->b->stack[i] = temp;
	if (d->print && d->flags->color)
		printf(BGREEN);
	if (d->print)
		printf("rrb\n");
	print_stacks(d, 1);
	d->n_ope++;
}

void	rrr(t_data *d)
{
	if (d->print && d->flags->color)
		printf(BBLUE);
	if (d->print)
	{
		printf("rrr\n");
		d->print = 0;
		rra(d);
		rrb(d);
		d->print = 1;
	}
	else
	{
		rra(d);
		rrb(d);
	}
	print_stacks(d, 1);
	d->n_ope--;
}
