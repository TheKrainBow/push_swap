/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/03/28 18:16:16 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_stack(t_stack *a)
{
	int		i;

	i = a->size;
	while (--i >= 0)
		printf("%d ", a->stack[i]);
	printf("\n");
}

void		print_stacks(t_stack *a, t_stack *b)
{
	int		i;

	i = ft_max(a->size, b->size);
	printf("_____\n");
	while (--i >= 0)
	{
		if (i < a->size)
			printf("|%d ", a->stack[i]);
		else
			printf("|  ");
		if (i < b->size)
			printf("%d|\n", b->stack[i]);
		else
			printf(" |\n");
	}
	printf("|a b|\n");
}

void		load_stack_arg(t_stack *a, char **av)
{
	int		i;

	i = -1;
	while (a && ++i < a->size)
		a->stack[a->size - i - 1] = ft_atoi(av[i + 1]);
}

void		load_stack_int(t_stack *a, int x)
{
	int		i;

	i = -1;
	while (a && ++i < a->size)
		a->stack[a->size - i - 1] = x;
}

int	node(char *line)
{
	if (ft_strcmp("sa", line) == 0)
		return (0);
	if (ft_strcmp("sb", line) == 0)
		return (1);
	if (ft_strcmp("ss", line) == 0)
		return (2);
	if (ft_strcmp("pa", line) == 0)
		return (3);
	if (ft_strcmp("pb", line) == 0)
		return (4);
	if (ft_strcmp("ra", line) == 0)
		return (5);
	if (ft_strcmp("rb", line) == 0)
		return (6);
	if (ft_strcmp("rr", line) == 0)
		return (7);
	if (ft_strcmp("rra", line) == 0)
		return (8);
	if (ft_strcmp("rrb", line) == 0)
		return (9);
	if (ft_strcmp("rrr", line) == 0)
		return (10);
	return (-1);
}

int			*copy(t_stack *a)
{
	int		*dest;
	int		i;

	dest = malloc(sizeof(int) * (a->size));
	i = -1;
	while (++i < a->size)
		dest[i] = a->stack[i];
	return (dest);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
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
			if (a->stack[i] < a->stack[i + 1])
			{
				swap(&a->stack[i], &a->stack[i + 1]);
				swaped = 1;
			}
	}
}

t_chunk	*chunk_stack(t_stack *a, int n)
{
	int			i;
	t_chunk		*dest;

	dest = malloc(sizeof(t_chunk) * (n));
	i = -1;
	while (++i < n)
	{
		dest[n - i - 1].min = a->stack[((i + 1) * (a->size / n) - 1)];
		dest[n - i - 1].max = a->stack[i * (a->size / n)];
	}
	dest[0].min = a->stack[a->size];
	dest[n - 1].max = a->stack[0];
	i = -1;
	while (++i < n)
		printf("[%d;%d]", dest[i].min, dest[i].max);
	printf("\n");
	return (dest);
}

void	find_two_numbers(t_data *data, int n)
{
	int		i;

	data->first = -1;
	i = -1;
	while ((++i < data->a->size) && data->first == -1)
		if (data->a->stack[i] >= data->chunked_a[n].min && data->a->stack[i] <= data->chunked_a[n].max)
			data->first = i;
	data->last = -1;
	i = data->a->size;
	while (--i > 0 && data->last == -1)
		if (data->a->stack[i] >= data->chunked_a[n].min && data->a->stack[i] <= data->chunked_a[n].max)
			data->last = i;
	if (data->first == data->last)
		data->first = -1;
	else
		data->first = (data->a->size - data->first - 1);
	if (data->last == -1)
		return ;
	data->last = (data->a->size - data->last - 1);
	swap(&data->first, &data->last);
}

int			top_stack(t_stack *a)
{
	return (a->stack[a->size - 1]);
}

int			prepare_b(t_data *data, int number, int move)
{
	int		i;

	(void)data;
	(void)number;
	(void)move;
	(void)i;
	return (0);
}

int			push_i_tob(t_data *data, int index, int move)
{
	int			movement;
	int			count_moves;

	movement = -1;
	count_moves = 0;
	if (index >= (data->a->size / 2))
		movement = 1;
	//count_moves += prepare_b(data, data->a->stack[data->a->size - index - 1], move);
	while (!(index == 0 || index == data->a->size))
	{
		if (movement == 1 && move)
			rra(data);
		else if (move)
			ra(data);
		index += movement;
		count_moves++;
	}
	if (move)
		pb(data);
	return (count_moves);
}

void		sort_chunked_stack(t_data *data, int n)
{
	int			i;
	int			ope[2];

	data->b->stack = malloc(sizeof(int) * (data->a->size));
	data->b->size = 0;
	print_stack(data->a);
	i = -1;
	while (++i < n)
	{
		data->first = 1;
		while (data->first != -1)
		{
			find_two_numbers(data, i);
			if (data->first == -1)
				break ;
			ope[0] = push_i_tob(data, data->first, 0);
			if (data->last != -1)
				ope[1] = push_i_tob(data, data->last, 0);
			if (ope[0] < ope[1] || data->last == -1)
				push_i_tob(data, data->first, 1);
			else
				push_i_tob(data, data->last, 1);
		}
	}
	print_stack(data->b);
	free(data->b->stack);
}

int		*push_swap(t_data *data)
{
	int				i;

	data->sorted_a->size = data->a->size;
	data->sorted_a->stack = copy(data->a);
	sort_stack(data->sorted_a);
	i = 2;
	data->chunked_a = chunk_stack(data->sorted_a, i);
	sort_chunked_stack(data, i);
	free(data->chunked_a);
	free(data->sorted_a->stack);
	return (NULL);
}

int main(int ac, char **av)
{
	t_data			data;
	t_stack			a;
	t_stack			b;
	t_stack			sorted_a;
	static void		(*redirect[11])(t_data *) =
	{
		sa, sb, ss,
		pa, pb,
		ra, rb, rr, rra, rrb, rrr
	};

	(void)redirect;
	data.a = &a;
	data.b = &b;
	data.sorted_a = &sorted_a;
	data.a->stack = malloc(sizeof(int) * (ac - 1));
	data.a->size = ac - 1;
	data.print = 0;
	load_stack_arg(data.a, av);
	printf("\n");
	push_swap(&data);
	free(data.a->stack);
	return (1);
}