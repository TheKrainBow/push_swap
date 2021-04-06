/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   d->by: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:48:20 d->by magostin          #+#    #+#             */
/*   Updated: 2021/03/28 16:28:43 d->by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void		sa(t_data *d)
{
	int		temp;

	(void)d->b;
	(void)d->b->size;
	if (d->a->size <= 1)
		return ;
	temp = d->a->stack[d->a->size - 1];
	d->a->stack[d->a->size - 1] = d->a->stack[d->a->size - 2];
	d->a->stack[d->a->size - 2] = temp;
	if (d->flags->color)
		printf(BRED);
	if (d->print)
		printf("sa\n");
	print_stacks(d, 1);
	if (d->flags->color)
		printf(BWHITE);
	d->n_ope++;
}

void		sb(t_data *d)
{
	int		temp;

	if (d->b->size <= 1)
		return ;
	temp = d->b->stack[d->b->size - 1];
	d->b->stack[d->b->size - 1] = d->b->stack[d->b->size - 2];
	d->b->stack[d->b->size - 2] = temp;
	if (d->flags->color)
		printf(BGREEN);
	if (d->print)
		printf("sb\n");
	print_stacks(d, 1);
	if (d->flags->color)
		printf(BWHITE);
	d->n_ope++;
}

void		ss(t_data *d)
{
	if (d->flags->color)
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
	if (d->flags->color)
		printf(BWHITE);
	d->n_ope--;
}

void		pa(t_data *d)
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
	if (d->flags->color)
		printf(BRED);
	if (d->print)
		printf("pa\n");
	print_stacks(d, 1);
	if (d->flags->color)
		printf(BWHITE);
	d->n_ope++;
}

void		pb(t_data *d)
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
	if (d->flags->color)
		printf(BGREEN);
	if (d->print)
		printf("pb\n");
	print_stacks(d, 1);
	if (d->flags->color)
		printf(BWHITE);
	d->n_ope++;
}

//first become last
void		ra(t_data *d)
{
	int			temp;
	int			i;

	temp = d->a->stack[d->a->size - 1];
	i = d->a->size;
	while (--i > 0)
		d->a->stack[i] = d->a->stack[i - 1];
	d->a->stack[i] = temp;
	if (d->flags->color)
		printf(BRED);
	if (d->print)
		printf("ra\n");
	print_stacks(d, 1);
	if (d->flags->color)
		printf(BWHITE);
	d->n_ope++;
}

//first become last
void		rb(t_data *d)
{
	int			temp;
	int			i;

	temp = d->b->stack[d->b->size - 1];
	i = d->b->size;
	while (--i > 0)
		d->b->stack[i] = d->b->stack[i - 1];
	d->b->stack[i] = temp;
	if (d->flags->color)
		printf(BGREEN);
	if (d->print)
		printf("rb\n");
	print_stacks(d, 1);
	if (d->flags->color)
		printf(BWHITE);
	d->n_ope++;
}

void		rr(t_data *d)
{
	if (d->flags->color)
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
	if (d->flags->color)
		printf(BWHITE);
	d->n_ope--;
}

//last become first
void		rra(t_data *d)
{
	int			temp;
	int			i;

	temp = d->a->stack[0];
	i = -1;
	while (++i < d->a->size - 1)
		d->a->stack[i] = d->a->stack[i + 1];
	d->a->stack[i] = temp;
	if (d->flags->color)
		printf(BRED);
	if (d->print)
		printf("rra\n");
	print_stacks(d, 1);
	if (d->flags->color)
		printf(BWHITE);
	d->n_ope++;
}

//last become first
void		rrb(t_data *d)
{
	int			temp;
	int			i;

	temp = d->b->stack[0];
	i = -1;
	while (++i < d->b->size - 1)
		d->b->stack[i] = d->b->stack[i + 1];
	d->b->stack[i] = temp;
	if (d->flags->color)
		printf(BGREEN);
	if (d->print)
		printf("rrb\n");
	print_stacks(d, 1);
	if (d->flags->color)
		printf(BWHITE);
	d->n_ope++;
}

void		rrr(t_data *d)
{
	if (d->flags->color)
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
	if (d->flags->color)
		printf(BWHITE);
	d->n_ope--;
}