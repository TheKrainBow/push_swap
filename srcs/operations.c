/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:48:20 by magostin          #+#    #+#             */
/*   Updated: 2021/03/05 01:10:52 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sa(int *a, int *b, int *s_a, int *s_b)
{
	int		temp;

	(void)b;
	(void)s_b;
	if (*s_a <= 1)
		return ;
	temp = a[*s_a - 1];
	a[*s_a - 1] = a[*s_a - 2];
	a[*s_a - 2] = temp;
}

void		sb(int *a, int *b, int *s_a, int *s_b)
{
	int		temp;

	(void)a;
	(void)s_a;
	if (*s_b <= 1)
		return ;
	temp = b[*s_b - 1];
	b[*s_b - 1] = b[*s_b - 2];
	b[*s_b - 2] = temp;
}

void		ss(int *a, int *b, int *s_a, int *s_b)
{
	if (*s_a > 1)
		sa(a, b, s_a, s_b);
	if (*s_b > 1)
		sb(a, b, s_a, s_b);
}

void		pa(int *a, int *b, int *s_a, int *s_b)
{
	if (*s_b == 0)
		return ;
	(*s_b)--;
	a[*s_a] = b[*s_b];
	(*s_a)++;
}

void		pb(int *a, int *b, int *s_a, int *s_b)
{
	if (*s_a == 0)
		return ;
	(*s_a)--;
	b[*s_b] = a[*s_a];
	(*s_b)++;
}

void		ra(int *a, int *b, int *s_a, int *s_b)
{
	int			temp;
	int			i;

	(void)b;
	(void)s_b;
	temp = a[*s_a - 1];
	i = *s_a;
	while (--i > 0)
		a[i] = a[i - 1];
	a[i] = temp;
}

void		rb(int *a, int *b, int *s_a, int *s_b)
{
	int			temp;
	int			i;

	(void)a;
	(void)s_a;
	temp = b[*s_b - 1];
	i = *s_b;
	while (--i > 0)
		b[i] = b[i - 1];
	b[i] = temp;
}

void		rr(int *a, int *b, int *s_a, int *s_b)
{
	ra(a, b, s_a, s_b);
	rb(a, b, s_a, s_b);
}

void		rra(int *a, int *b, int *s_a, int *s_b)
{
	int			temp;
	int			i;

	(void)b;
	(void)s_b;
	temp = a[0];
	i = -1;
	while (++i < *s_a - 1)
		a[i] = a[i + 1];
	a[i] = temp;
}

void		rrb(int *a, int *b, int *s_a, int *s_b)
{
	int			temp;
	int			i;

	(void)a;
	(void)s_a;
	temp = b[0];
	i = -1;
	while (++i < *s_b - 1)
		b[i] = b[i + 1];
	b[i] = temp;
}

void		rrr(int *a, int *b, int *s_a, int *s_b)
{
	rra(a, b, s_a, s_b);
	rrb(a, b, s_a, s_b);
}