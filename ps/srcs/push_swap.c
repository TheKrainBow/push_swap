/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/04/04 16:12:58 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
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

void		push_swap(t_data *data, int print)
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
	i_min = 1;
	i = 0;
	free(data->a->stack);
	free(data->a);
	while ((++i < data->a->size / 5 && data->a->size > 5)
	|| (i < data->a->size && data->a->size <= 5))
	{
		data->a = copy(temp);
		data->n_ope = 0;
		data->chunked_a = chunk_stack(data, data->sorted_a, i, 0);
		sort_chunk(data, data->n_chunk);
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
	data->chunked_a = chunk_stack(data, data->sorted_a, i_min, 0);
	if (print)
		data->print = 1;
	sort_chunk(data, data->n_chunk);
	if (data->flags->visualize)
	{
		printf("A sorted.\n");
		print_stacks(data, 0);
		printf(BCYAN"Total Operations: ["BWHITE"%d"BCYAN"]\n"BWHITE, data->n_ope);
	}
	free(temp->stack);
	free(temp);
	free_data(data, 3);
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

int		parsing(t_data *data)
{
	int		i;
	char	*temp;
	char	**args;

	args = data->flags->args;
	temp = NULL;
	i = -1;
	if (args[0][0] == '-')
	{
		temp = ft_strtrim(args[0], "-crv");
		if (temp && !(temp[0]))
		{
			if (ft_strchr(args[0], 'c'))
				data->flags->color = 1;
			if (ft_strchr(args[0], 'r'))
				data->flags->random = 1;
			if (ft_strchr(args[0], 'v'))
				data->flags->visualize = 1;
		}
		else if (!ft_strmap(temp, ft_isdigit))
			ft_exit(data, 1, temp);
	}
	free(temp);
	return (0);
}

int		main(int ac, char **av)
{
	t_data			*data;

	data = init_data();
	data->flags->args = create_args(av, ac);
	if (ac == 1 || parsing(data))
		ft_exit(data, 1, NULL);
	if (data->flags->random)
		generate_random_stack(data);
	else
		load_stack_arg(data, data->flags->args + (data->flags->visualize || data->flags->color || data->flags->random));
	if (!checker(data->a, data->a->size, 0))
		push_swap(data, 1);
	else if (data->flags->visualize)
	{
		printf(BWHITE"A sorted.\n");
		print_stack(data->a, 1);
		printf(BCYAN"Total Operations: ["BWHITE"%d"BCYAN"]\n"BWHITE, 0);
		free_data(data, 2);
	}
	else
		free_data(data, 2);
	return (0);
}