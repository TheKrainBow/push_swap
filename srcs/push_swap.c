/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/04/02 13:00:30 by mdelwaul         ###   ########.fr       */
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

t_stack			*copy(t_stack *a)
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

t_chunk		*chunk_stack_temp(t_data *data, t_stack *a, int n, int print)
{
	int			i;
	t_chunk		*dest;

	data->n_chunk = (int)(a->size / n);
	if ((a->size % n))
		(data->n_chunk)++;
	dest = malloc(sizeof(t_chunk) * (data->n_chunk));
	i = -1;
	while (++i < data->n_chunk)
	{
		dest[i].min = a->stack[a->size - 1 -(i * n)];
		dest[i].max = a->stack[a->size - 1 - ((i * n) + n - 1)];
	}
	dest[0].min = a->stack[a->size - 1];
	dest[data->n_chunk - 1].max = a->stack[0];
	i = -1;
	while (print && ++i < data->n_chunk)
		printf("[%d;%d]", dest[i].min, dest[i].max);
	if (print)
		printf("\n");
	return (dest);
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
	return (c >= b && c <= a);
}

int		check_b_insert(t_data *data, int index)
{
	int		prev;

	prev = index - 1;
	if (index == 0)
		prev = data->b->size - 1;
	if (data->b->stack[index] > data->ma[0]->value && data->b->stack[prev] < data->ma[0]->value)
		return (1);
	return (0);
}

void		revers_moves(t_data *data)
{
	if (data->ma[0]->move == &ra)
		data->ma[1]->move = &rra;
	else
		data->ma[1]->move = &ra;
	if (data->mb[0]->move == &rb)
		data->mb[1]->move = &rrb;
	else
		data->mb[1]->move = &rb;
	data->ma[1]->n = data->a->size - data->ma[0]->n;
	data->mb[1]->n = data->b->size - data->mb[0]->n;

}

int			exec_moves(t_data *data, t_move *ma, t_move *mb, int move)
{
	int		i;

	i = 0;
	while (ma->move == &ra && mb->move == &rb
	&& (ma->n > 0) && (mb->n > 0) && (data->a->size > 1 && data->b->size > 1))
	{
		if (move)
			rr(data);
		ma->n--;
		mb->n--;
		i++;
	}
	while (ma->move == &rra && mb->move == &rrb
	&& (ma->n > 0) && (mb->n > 0) && (data->a->size > 1 && data->b->size > 1))
	{
		if (move)
			rrr(data);
		ma->n--;
		mb->n--;
		i++;
	}
	while (ma->n > 0)
	{
		if (move && data->a->size > 1)
			ma->move(data);
		ma->n--;
		i++;
	}
	while (mb->n > 0)
	{
		if (move && data->b->size > 1)
			mb->move(data);
		mb->n--;
		i++;
	}
	return (i);
}

int			ind(int i, char a)
{
	if (a == 'a')
		return (i >= 2);
	return (i % 2);
}

void		generate_moves(t_data *data)
{
	int		moves;
	int		n[2];
	int		i;
	int		i_temp;
	int		min;

	revers_moves(data);
	n[0] = data->ma[0]->n;
	n[1] = data->mb[0]->n;
	i = -1;
	while (++i < 4)
	{
		n[0] = data->ma[ind(i, 'a')]->n;
		n[1] = data->mb[ind(i, 'b')]->n;
		moves = exec_moves(data, data->ma[ind(i, 'a')], data->mb[ind(i, 'b')], 0);
		if (moves < min || i == 0)
		{
			i_temp = i;
			min = moves;
		}
		data->ma[ind(i, 'a')]->n = n[0];
		data->mb[ind(i, 'b')]->n = n[1];
	}
	exec_moves(data, data->ma[ind(i_temp, 'a')], data->mb[ind(i_temp, 'b')], 1);
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
	if (i != -1)
	{
		data->mb[0]->move = rrb;
		data->mb[0]->n = i;
		return ;
	}
	else
	{
		i = 0;
		while (data->b->stack[i] != data->b->max)
			i++;
		if (i != data->b->size - 1)
		{
			data->mb[0]->move = rrb;
			data->mb[0]->n = i + 1;
		}
		else
			data->mb[0]->n = 0;
	}
}

void	best_move_for_a(t_data *data, int n)
{
	int		i;

	if (data->a->size == 1)
	{
		data->ma[0]->n = 0;
		data->ma[0]->value = data->a->stack[0];
		data->first = 0;
		return ;
	}
	data->first = -1;
	i = data->a->size;
	while (--i >= 0 && data->first == -1)
		if (data->a->stack[i] >= data->chunked_a[n].min && data->a->stack[i] <= data->chunked_a[n].max)
			data->first = i;
	if (data->first == -1)
		return ;
	data->first = (data->a->size - data->first - 1);
	data->ma[0]->move = ra;
	data->ma[0]->n = data->first;
	data->ma[0]->value = data->a->stack[i + 1];
}

void		clear_move(t_data *data)
{
	data->ma[1]->move = NULL;
	data->ma[1]->n = 0;
	data->mb[1]->move = NULL;
	data->mb[1]->n = 0;
	data->ma[0]->move = NULL;
	data->ma[0]->n = 0;
	data->ma[0]->value = 0;
	data->mb[0]->move = NULL;
	data->mb[0]->n = 0;
	data->mb[0]->value = 0;
}

void		sort_chunked_stack(t_data *data, int n)
{
	int			i;

	data->b = malloc(sizeof(t_stack));
	data->b->stack = malloc(sizeof(int) * (data->a->size));
	data->b->size = 0;
	i = -1;
	while (++i < n)
	{
		data->first = 1;
		while (data->first != -1)
		{
			best_move_for_a(data, i);
			if (data->first == -1)
				break ;
			best_move_for_b(data);
			generate_moves(data);
			pb(data);
			clear_move(data);
		}
	}
	i = 0;
	while (data->b->stack[i] != data->b->max)
		i++;
	if (i != data->b->size - 1)
	{
		data->mb[0]->move = rrb;
		data->mb[0]->n = i + 1;
	}
	else
		data->mb[0]->n = 0;
	data->ma[0]->n = 0;
	generate_moves(data);
	while (data->b->size)
		pa(data);
	free(data->b->stack);
	free(data->b);
}

void		push_swap(t_data *data)
{
	int				i;
	int				min;
	int				i_min;
	t_stack			*temp;

	data->sorted_a = copy(data->a);
	temp = copy(data->a);
	sort_stack(data->sorted_a);
	data->print = 0;
	min = 0;
	i_min = 0;
	i = 0;
	free(data->a->stack);
	free(data->a);
	while (++i < data->a->size / 5)
	{
		data->a = copy(temp);
		data->n_ope = 0;
		data->chunked_a = chunk_stack_temp(data, data->sorted_a, i, 0);
		sort_chunked_stack(data, data->n_chunk);
		if (i == 1 || data->n_ope < min)
		{
			min = data->n_ope;
			i_min = i;
		}
		free(data->chunked_a);
		free(data->a->stack);
		free(data->a);
	}
	data->a = copy(temp);
	data->n_ope = 0;
	data->chunked_a = chunk_stack_temp(data, data->sorted_a, i_min, 0);
	data->print = 0;
	sort_chunked_stack(data, data->n_chunk);
	free(data->chunked_a);
	free(data->sorted_a->stack);
	free(data->sorted_a);
	free(temp->stack);
	free(temp);
	free(data->a->stack);
	free(data->a);
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
	t_data			*data;

	int		i;
	int		min;
	int		max;
	int		ope_average = 0;
	i = -1;
	while (++i < 50)
	{
		data = malloc(sizeof(t_data));
		data->a = malloc(sizeof(t_stack));
		data->ma[0] = malloc(sizeof(t_move));
		data->mb[0] = malloc(sizeof(t_move));
		data->ma[1] = malloc(sizeof(t_move));
		data->mb[1] = malloc(sizeof(t_move));
		data->ma[0]->n = 0;
		data->mb[0]->n = 0;
		srand(i);
		generate_random_stack(data->a, ft_atoi(av[1]));
		if (0)
			load_stack_arg(data->a, av, ac);
		if (!checker(data->a, data->a->size, 0))
			push_swap(data);
		else
		{
			free(data->a->stack);
			free(data->a);
		}
		ope_average += data->n_ope;
		if (i == 0)
		{
			min = data->n_ope;
			max = data->n_ope;
		}
		if (data->n_ope > max)
			max = data->n_ope;
		if (data->n_ope < min)
			min = data->n_ope;
		printf("%d%%\n\033[A", i * 2);
		free(data->ma[0]);
		free(data->mb[0]);
		free(data->ma[1]);
		free(data->mb[1]);
		free(data);
	}
	printf("Average is %d operations.\n", ope_average / i);
	printf("Best was %d and worst was %d\n", min, max);
	return (1);
}