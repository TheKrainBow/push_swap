/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/03/29 14:37:53 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void		load_stack_arg(t_stack *a, char **av, int ac)
{
	int		i;
	int		j;
	int		k;
	char	**temp;

	i = -1;
	a->size = 0;
	while (++i < ac)
	{
		temp = ft_split(av[i + 1], ' ');
		j = -1;
		while (temp && temp[++j])
			a->size++;
		ft_free_tab(temp);
	}
	a->stack = malloc(sizeof(int) * a->size);
	i = -1;
	k = -1;
	while (++i < ac)
	{
		temp = ft_split(av[i + 1], ' ');
		j = -1;
		while (temp && temp[++j] && ++k > -1)
			a->stack[a->size - k - 1] = ft_atoi(temp[j]);
		ft_free_tab(temp);
	}
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

t_chunk	*chunk_stack(t_stack *a, int n, int print)
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
	dest[0].min = a->stack[a->size - 1];
	dest[n - 1].max = a->stack[0];
	i = -1;
	while (print && ++i < n)
		printf("[%d;%d]", dest[i].min, dest[i].max);
	if (print)
		printf("\n");
	return (dest);
}

int			top_stack(t_stack *a)
{
	return (a->stack[a->size - 1]);
}

int		is_between(int c, int a, int b)
{
	return ((c >= a && c <= b) /*|| (c >= b && c <= a)*/);
}

int		check_b_insert(t_data *data, int index)
{
	int		prev;

	prev = index - 1;
	if (index == 0)
		prev = data->b->size - 1;
	return (is_between(data->ma->value, data->b->stack[index], data->b->stack[prev]));
}

void		exec_moves(t_data *data)
{
	t_move	*ma;
	t_move	*mb;

	ma = data->ma;
	mb = data->mb;
	//printf("%d %s\n", ma->n, ma->move == &ra ? "ra" : "rra");
	//printf("%d %s\n", mb->n, mb->move == &rb ? "rb" : "rrb");
	while (ma->n > 0)
	{
		if (data->a->size > 1)
			ma->move(data);
		ma->n--;
	}
	/*while (mb->n > 0)
	{
		if (data->b->size > 1)
			mb->move(data);
		mb->n--;
	}*/
}
int		find_b_max(t_data *data)
{
	int		i;
	int		max;
	int		i_max;

	i = -1;
	i_max = -1;
	max = data->b->stack[0];
	while (++i < data->b->size)
		if (data->b->stack[i] >= max)
		{
			i_max = i;
			max = data->b->stack[i];
		}
	return (i_max);
}

void	push_back_to_a(t_data *data)
{
	int	i;
	
	i = find_b_max(data);
	if (i != -1)
	{
		if (i >= data->b->size / 2)
		{
			data->mb->move = &rb;
			data->mb->n = data->b->size - i;
		}
		else
		{
			data->mb->move = &rrb;
			data->mb->n = i;
		}
		exec_moves(data);
	}
	while (data->b->size)
	{
		rrb(data);
		pa(data);
	}
}

void	best_move_for_b(t_data *data)
{
	int		i;
	int		maxed;

	maxed = 0;
	if (data->b->size <= 1)
		return ;
	i = data->b->size;
	while (--i >= 0)
		if (check_b_insert(data, i))
			break ;
	if (i == -1)
	{
		i = find_b_max(data);
		maxed++;
	}
	if (i != -1)
	{
		if (i >= data->b->size / 2)
		{
			data->mb->move = &rb;
			data->mb->n = data->b->size - i;
		}
		else
		{
			data->mb->move = &rrb;
			data->mb->n = i;
		}
	}
	//if (maxed)
	//	rrb(data);
}

void	best_move_for_a(t_data *data, int n)
{
	int		i;

	if (data->a->size == 1)
	{
		data->ma->n = 0;
		data->ma->value = data->a->stack[0];
		data->first = 0;
		return ;
	}
	data->first = -1;
	i = data->a->size;
	while (--i > 0 && data->first == -1)
		if (data->a->stack[i] >= data->chunked_a[n].min && data->a->stack[i] <= data->chunked_a[n].max)
		{
			data->first = i;
			data->first_v = data->a->stack[i];
		}
	data->last = -1;
	i = -1;
	while ((++i < data->a->size) && data->last == -1)
		if (data->a->stack[i] >= data->chunked_a[n].min && data->a->stack[i] <= data->chunked_a[n].max)
		{
			data->last = i;
			data->last_v = data->a->stack[i];
		}
	if (data->last == data->first)
		data->last = -1;
	else
		data->last++;
	if (data->first == -1)
		return ;
	data->first = (data->a->size - data->first - 1);
	if (data->first < data->last || data->last == -1)
	{
		data->ma->move = ra;
		data->ma->n = data->first;
		data->ma->value = data->first_v;
	}
	else
	{
		data->ma->move = rra;
		data->ma->n = data->last;
		data->ma->value = data->last_v;
	}
}

void		sort_chunked_stack(t_data *data, int n)
{
	int			i;

	data->b->stack = malloc(sizeof(int) * (data->a->size));
	data->b->size = 0;
	i = -1;
	while (++i < n)
	{
		printf("{%d} ", i);
		data->first = 1;
		while (data->first != -1)
		{
			best_move_for_a(data, i);
			if (data->first == -1)
			{
				printf("\n");
				break ;
			}
			printf("%d ", data->ma->value);
			best_move_for_b(data);
			exec_moves(data);
			pb(data);
			//if (top_stack(data->b) < data->b->stack[data->b->size - 2] && data->b->size >= 2)
			//	rb(data);
		}
	}
	print_stack(data->b);
	push_back_to_a(data);
	free(data->b->stack);
}

int		*push_swap(t_data *data)
{
	int				i;

	data->sorted_a->size = data->a->size;
	data->sorted_a->stack = copy(data->a);
	sort_stack(data->sorted_a);
	i = 2;
	data->chunked_a = chunk_stack(data->sorted_a, i, 1);
	print_stack(data->a);
	sort_chunked_stack(data, i);
	free(data->chunked_a);
	free(data->sorted_a->stack);
	return (NULL);
}


int		checker(t_stack *a, int correct_size, int print)
{
	int			i;

	if (a->size == correct_size)
	{
		i = -1;
		while (++i < a->size - 1)
			if (a->stack[i] < a->stack[i + 1])
			{
				if (print)
					printf("KO\n");
				return (0);
			}
		if (print)
			printf("OK\n");
		return (1);
	}
	if (print)
		printf("KO\n");
	return (0);
}

void	generate_random_stack(t_stack *a, int n)
{
	int		i;

	srand(10);
	a->stack = malloc(sizeof(int) * n);
	a->size = n;
	i = -1;
	while (++i < n)
		a->stack[i] = i;
	i = -1;
	while (++i < n)
		swap(&a->stack[rand() % n], &a->stack[rand() % n]);
}

int main(int ac, char **av)
{
	t_data			data;
	t_stack			a;
	t_stack			b;
	t_move			ma;
	t_move			mb;
	t_stack			sorted_a;
	static void		(*redirect[11])(t_data *) =
	{
		sa, sb, ss,
		pa, pb,
		ra, rb, rr, rra, rrb, rrr
	};

	(void)ac;
	(void)av;
	(void)redirect;
	data.a = &a;
	data.b = &b;
	mb.n = 0;
	ma.n = 0;
	data.ma = &ma;
	data.mb = &mb;
	data.sorted_a = &sorted_a;
	data.print = 0;
	generate_random_stack(data.a, 8);
	//load_stack_arg(data.a, av, ac);
	if (!checker(&a, a.size, 0))
		push_swap(&data);
	//print_stacks(&a, &b);
	free(data.a->stack);
	return (1);
}