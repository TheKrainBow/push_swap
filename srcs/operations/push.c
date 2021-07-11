/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 02:22:50 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/07/12 01:27:13 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	pa(t_data *d)
{
	if (d->b->size == 0)
		return ;
	(d->b->size)--;
	d->a->stack[d->a->size] = d->b->stack[d->b->size];
	(d->a->size)++;
	if (d->a->size == 1)
	{
		d->a->max = d->b->stack[d->b->size];
		d->a->min = d->b->stack[d->b->size];
	}
	if (d->b->stack[d->b->size] > d->a->max)
		d->a->max = d->b->stack[d->b->size];
	if (d->b->stack[d->b->size] < d->a->min)
		d->a->min = d->b->stack[d->b->size];
	if (d->print && d->flags->color)
		printf(BRED);
	if (d->print)
		printf("pa\n");
	print_stacks(d, 1);
	d->n_ope++;
}

void	pb(t_data *d)
{
	if (d->a->size == 0)
		return ;
	(d->a->size)--;
	d->b->stack[d->b->size] = d->a->stack[d->a->size];
	(d->b->size)++;
	if (d->b->size == 1)
	{
		d->b->max = d->a->stack[d->a->size];
		d->b->min = d->a->stack[d->a->size];
	}
	if (d->a->stack[d->a->size] > d->b->max)
		d->b->max = d->b->stack[d->b->size - 1];
	if (d->a->stack[d->a->size] < d->b->min)
		d->b->min = d->b->stack[d->b->size - 1];
	if (d->print && d->flags->color)
		printf(BGREEN);
	if (d->print)
		printf("pb\n");
	print_stacks(d, 1);
	d->n_ope++;
}
