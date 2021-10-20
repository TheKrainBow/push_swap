/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 02:23:30 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/10/05 18:17:02 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	sa(t_data *d)
{
	int		temp;

	if (d->a->size <= 1)
		return ;
	temp = d->a->stack[d->a->size - 1];
	d->a->stack[d->a->size - 1] = d->a->stack[d->a->size - 2];
	d->a->stack[d->a->size - 2] = temp;
	if (d->print && d->flags->color)
		printf(BRED);
	if (d->print)
		printf("sa\n");
	print_stacks(d, 1);
	d->n_ope++;
}

void	sb(t_data *d)
{
	int		temp;

	if (d->b->size <= 1)
		return ;
	temp = d->b->stack[d->b->size - 1];
	d->b->stack[d->b->size - 1] = d->b->stack[d->b->size - 2];
	d->b->stack[d->b->size - 2] = temp;
	if (d->print && d->flags->color)
		printf(BGREEN);
	if (d->print)
		printf("sb\n");
	print_stacks(d, 1);
	d->n_ope++;
}

void	ss(t_data *d)
{
	if (d->print && d->flags->color)
		printf(BBLUE);
	if (d->print)
	{
		printf("ss\n");
		d->print = 0;
		if (d->a->size > 1)
			sa(d);
		if (d->b->size > 1)
			sb(d);
		d->print = 1;
	}
	else
	{
		sa(d);
		sb(d);
	}
	print_stacks(d, 1);
	d->n_ope--;
}
