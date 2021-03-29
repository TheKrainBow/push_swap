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

#include "../includes/push_swap.h"


void		print_stack(t_stack *a)
{
	int		i;

	i = -1;
	while (++i < a->size)
		printf("%d ", a->stack[i]);
	printf("\n");
}

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
	if (d->print)
		printf("sa\n");
}

void		sb(t_data *d)
{
	int		temp;

	if (d->b->size <= 1)
		return ;
	temp = d->b->stack[d->b->size - 1];
	d->b->stack[d->b->size - 1] = d->b->stack[d->b->size - 2];
	d->b->stack[d->b->size - 2] = temp;
	if (d->print)
		printf("sb\n");
}

void		ss(t_data *d)
{
	if (d->a->size > 1)
		sa(d);
	if (d->b->size > 1)
		sb(d);
	if (d->print)
		printf("ss\n");
}

void		pa(t_data *d)
{
	if (d->b->size == 0)
		return ;
	(d->b->size)--;
	d->a->stack[d->a->size] = d->b->stack[d->b->size];
	(d->a->size)++;
	if (d->print)
		printf("pa\n");
}

void		pb(t_data *d)
{
	if (d->a->size == 0)
		return ;
	(d->a->size)--;
	d->b->stack[d->b->size] = d->a->stack[d->a->size];
	(d->b->size)++;
	if (d->print)
		printf("pb\n");
	//print_stack(d->a);
	//print_stack(d->b);
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
	if (d->print)
		printf("ra\n");
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
	if (d->print)
		printf("rb\n");
	//print_stack(d->a);
	//print_stack(d->b);
}

void		rr(t_data *d)
{
	ra(d);
	rb(d);
	if (d->print)
		printf("rr\n");
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
	if (d->print)
		printf("rra\n");
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
	if (d->print)
		printf("rrb\n");
	//print_stack(d->a);
	//print_stack(d->b);
}

void		rrr(t_data *d)
{
	rra(d);
	rrb(d);
	if (d->print)
		printf("rrr\n");
}