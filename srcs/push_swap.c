/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/04/01 19:30:33 by magostin         ###   ########.fr       */
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

	//print_stack(a);
	data->n_chunk = (int)(a->size / n);
	if ((a->size % n))
		(data->n_chunk)++;
	dest = malloc(sizeof(t_chunk) * (data->n_chunk));
	//printf("%d Chunk sizeof %d\n", size, n);
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
	return (/*(c >= a && c <= b) ||*/ (c >= b && c <= a));
}

int		check_b_insert(t_data *data, int index)
{
	int		prev;

	prev = index - 1;
	if (index == 0)
		prev = data->b->size - 1;
	if (data->b->stack[index] > data->ma->value && data->b->stack[prev] < data->ma->value)
	{
		//printf("%d between [%d;%d]\n", data->ma->value, data->b->stack[prev], data->b->stack[index]);
		return (1);
	}
	return (0);
}

void		revers_moves(t_data *data)
{
	if (data->ma->move == &ra)
		data->ra->move = &rra;
	else
		data->ra->move = &ra;
	if (data->mb->move == &rb)
		data->rb->move = &rrb;
	else
		data->rb->move = &rb;
	data->ra->n = data->a->size - data->ma->n;
	data->rb->n = data->b->size - data->mb->n;

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

t_move			*copy_move(t_move *a)
{
	t_move		*dest;

	dest = malloc(sizeof(t_move));
	dest->n = a->n;
	dest->move = a->move;
	dest->value = a->value;
	return (dest);
}

void		generate_moves(t_data *data)
{
	t_move	*ma[2];
	t_move	*mb[2];
	int		moves[4];
	int		n[2];
	int		temp_ope;
	int		i;
	int		i_temp;
	int		min;

	revers_moves(data);
	temp_ope = data->n_ope;
	ma[0] = copy_move(data->ma);
	mb[0] = copy_move(data->mb);
	ma[1] = copy_move(data->ra);
	mb[1] = copy_move(data->rb);
	/*printf("	%d %s\n", ma[0]->n, ma[0]->move == &ra ? "ra" : "rra");
	printf("	%d %s\n", mb[0]->n, mb[0]->move == &rb ? "rb" : "rrb");
	printf("	%d %s\n", ma[1]->n, ma[1]->move == &ra ? "ra" : "rra");
	printf("	%d %s\n", mb[1]->n, mb[1]->move == &rb ? "rb" : "rrb");*/
	n[0] = ma[0]->n;
	n[1] = mb[0]->n;
	min = exec_moves(data, ma[0], mb[0], 0);
	ma[0]->n = n[0];
	mb[0]->n = n[1];
	data->n_ope = temp_ope;
	i_temp = 0;
	i = 0;
	while (++i < 4)
	{
		n[0] = ma[ind(i, 'a')]->n;
		n[1] = mb[ind(i, 'b')]->n;
		moves[i] = exec_moves(data, ma[ind(i, 'a')], mb[ind(i, 'b')], 0);
		//printf("moves[%d] = %d with ma[%d]mb[%d]\n", i, moves[i] - data->n_ope, ind(i, 'a'), ind(i, 'b'));
		if (moves[i] < min)
		{
			i_temp = i;
			min = moves[i];
		}
		ma[ind(i, 'a')]->n = n[0];
		mb[ind(i, 'b')]->n = n[1];
		data->n_ope = temp_ope;
	}
	i = i_temp;
	exec_moves(data, ma[ind(i, 'a')], mb[ind(i, 'b')], 1);
	free(ma[0]);
	free(mb[0]);
	free(ma[1]);
	free(mb[1]);

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
		data->mb->move = rrb;
		data->mb->n = i;
		return ;
	}
	else
	{
		i = 0;
		while (data->b->stack[i] != data->b->max)
			i++;
		if (i != data->b->size - 1)
		{
			data->mb->move = rrb;
			data->mb->n = i + 1;
		}
		else
			data->mb->n = 0;
	}
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
	while (--i >= 0 && data->first == -1)
		if (data->a->stack[i] >= data->chunked_a[n].min && data->a->stack[i] <= data->chunked_a[n].max)
			data->first = i;
	if (data->first == -1)
		return ;
	data->first = (data->a->size - data->first - 1);
	data->ma->move = ra;
	data->ma->n = data->first;
	data->ma->value = data->a->stack[i + 1];
}

void		clear_move(t_data *data)
{
	data->ra->move = NULL;
	data->ra->n = 0;
	data->rb->move = NULL;
	data->rb->n = 0;
	data->ma->move = NULL;
	data->ma->n = 0;
	data->ma->value = 0;
	data->mb->move = NULL;
	data->mb->n = 0;
	data->mb->value = 0;
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
		data->mb->move = rrb;
		data->mb->n = i + 1;
	}
	else
		data->mb->n = 0;
	data->ma->n = 0;
	generate_moves(data);
	while (data->b->size)
		pa(data);
	free(data->b->stack);
	free(data->b);
}

int		*push_swap(t_data *data)
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
	while (++i < data->a->size)
	{
		data->a = copy(temp);
		data->n_ope = 0;
		data->chunked_a = chunk_stack(data->sorted_a, i, 0);
		//data->chunked_a = chunk_stack_temp(data, data->sorted_a, i, 0);
		//sort_chunked_stack(data, data->n_chunk);
		sort_chunked_stack(data, i);
		if (i == 1 || data->n_ope < min)
		{
			min = data->n_ope;
			i_min = i;
		}
		free(data->chunked_a);
		free(data->a->stack);
		free(data->a);
	}
	//printf("%d for %d\n", min, i_min);
	data->a = copy(temp);
	data->n_ope = 0;
	data->chunked_a = chunk_stack(data->sorted_a, i_min, 0);
	//data->chunked_a = chunk_stack_temp(data, data->sorted_a, i_min, 0);
	data->print = 1;
	sort_chunked_stack(data, i_min);
	//sort_chunked_stack(data, data->n_chunk);
	free(data->chunked_a);
	free(data->sorted_a->stack);
	free(data->sorted_a);
	free(temp->stack);
	free(temp);

	//print_stack(data->a);

	free(data->a->stack);
	free(data->a);
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

	a->stack = malloc(sizeof(int) * n);
	a->size = n;
	i = -1;
	while (++i < n)
		a->stack[i] = i;
	i = -1;
	while (++i < n)
		swap(&a->stack[rand() % n], &a->stack[rand() % n]);
}
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
int main(int ac, char **av)
{
	t_data			*data;
	static void		(*redirect[11])(t_data *) =
	{
		sa, sb, ss,
		pa, pb,
		ra, rb, rr, rra, rrb, rrr
	};

	(void)ac;
	(void)av;
	(void)redirect;
	//int test = open("test.output", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
	// S_IROTH);
	//int	tempfd = dup(1);
	//write(1, "1", 1);
//	dup2(test, 1);
	//data->b = malloc(sizeof(t_stack));
	data = malloc(sizeof(t_data));
	data->a = malloc(sizeof(t_stack));
	data->ma = malloc(sizeof(t_move));
	data->mb = malloc(sizeof(t_move));
	data->ra = malloc(sizeof(t_move));
	data->rb = malloc(sizeof(t_move));
	data->ma->n = 0;
	data->mb->n = 0;
	srand(42);
	generate_random_stack(data->a, ft_atoi(av[1]));
	//load_stack_arg(data->a, av, ac);
	//print_stack(data->a);
	if (!checker(data->a, data->a->size, 0))
		push_swap(data);
	else
	{
		free(data->a->stack);
		free(data->a);
	}
	free(data->ma);
	free(data->mb);
	free(data->ra);
	free(data->rb);
	free(data);
	//print_stacks(&a, &b);
	//close(test);
	//dup2(tempfd, 1);
	return (1);
}