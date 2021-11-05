/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/11/05 03:07:11 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_three(t_data *data, int print)
{
	if (print)
		data->print = 1;
	if (data->a->size == 2)
	{
		sa(data);
		free_data(data, 2);
		return ;
	}
	data->b = malloc(sizeof(t_stack));
	data->b->stack = NULL;
	data->b->size = 0;
	sort_three(data);
	free(data->b->stack);
	free(data->b);
	free_data(data, 2);
}

void	push_swap_five(t_data *data, int print)
{
	data->b = malloc(sizeof(t_stack));
	data->b->stack = malloc(sizeof(int) * data->a->size);
	data->b->size = 0;
	if (print)
		data->print = 1;
	while (data->a->size > 3)
		pb(data);
	sort_three(data);
	while (data->b->size)
	{
		five_setup_a(data);
		generate_moves(data);
		pa(data);
	}
	while (data->a->stack[data->a->size - 1] > data->a->stack[0])
		ra(data);
	free_stack(data->b);
	free_data(data, 2);
}

void	final_print(t_data *data)
{
	printf("A sorted.\n");
	print_stack(data->a, 1);
	printf("\n");
	printf(BGREEN);
	print_arrow(data->a->size, biggest_num(data->a));
	printf(
		BCYAN"Total Operations: ["BWHITE"%d"BCYAN"]\n"BWHITE, data->n_ope);
}

void	push_swap_all(t_data *data, int print)
{
	t_stack			*temp;
	int				i_min;

	temp = copy(data->a);
	data->sorted_a = copy(data->a);
	free_stack(data->a);
	sort_stack(data->sorted_a);
	i_min = find_best_chunk_size(data, temp);
	free_stack(temp);
	data->chunked_a = chunk_stack(data, data->sorted_a, i_min, 0);
	if (print)
		data->print = 1;
	sort_chunk(data, data->n_chunk);
	if (data->flags->visualize)
	{
		final_print(data);
	}
	free_data(data, 3);
}

void	push_swap(t_data *data, int print)
{
	if (data->a->size <= 3)
		push_swap_three(data, print);
	else if (data->a->size <= 5)
		push_swap_five(data, print);
	else
		push_swap_all(data, print);
}

int	main(int ac, char **av)
{
	t_data			*data;

	if (ac == 1)
		return (1);
	data = init_data();
	data->flags->args = create_args(av, ac);
	parsing(data);
	if (data->flags->random)
		generate_random_stack(data, 1);
	else
		load_stack_arg(data, data->flags->args + (data->flags->visualize
				|| data->flags->color || data->flags->random));
	if (!checker(data->a, data->a->size, 0, data->flags->color))
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
