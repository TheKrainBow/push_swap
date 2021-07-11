/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 02:23:20 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/07/12 01:26:48 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ra(t_data *d)
{
	int			temp;
	int			i;

	temp = d->a->stack[d->a->size - 1];
	i = d->a->size;
	while (--i > 0)
		d->a->stack[i] = d->a->stack[i - 1];
	d->a->stack[i] = temp;
	if (d->print && d->flags->color)
		printf(BRED);
	if (d->print)
		printf("ra\n");
	print_stacks(d, 1);
	d->n_ope++;
}

void	rb(t_data *d)
{
	int			temp;
	int			i;

	temp = d->b->stack[d->b->size - 1];
	i = d->b->size;
	while (--i > 0)
		d->b->stack[i] = d->b->stack[i - 1];
	d->b->stack[i] = temp;
	if (d->print && d->flags->color)
		printf(BGREEN);
	if (d->print)
		printf("rb\n");
	print_stacks(d, 1);
	d->n_ope++;
}

void	rr(t_data *d)
{
	if (d->print && d->flags->color)
		printf(BBLUE);
	if (d->print)
	{
		printf("rr\n");
		d->print = 0;
		ra(d);
		rb(d);
		d->print = 1;
	}
	else
	{
		ra(d);
		rb(d);
	}
	print_stacks(d, 1);
	d->n_ope--;
}
