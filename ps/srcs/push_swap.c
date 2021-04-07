/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/04/07 03:10:31 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ind(int i, char a)
{
	if (a == 'a')
		return (i >= 2);
	return (i % 2);
}

int		find_best_chunk_size(t_data *data, t_stack *temp)
{
	int				i;
	int				min;
	int				i_min;

	i = 0;
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
		free_stack(data->a);
	}
	data->a = copy(temp);
	data->n_ope = 0;
	return (i_min);
}

void	push_swap(t_data *data, int print)
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
		printf("A sorted.\n");
		print_stacks(data, 0);
		printf(
			BCYAN"Total Operations: ["BWHITE"%d"BCYAN"]\n"BWHITE, data->n_ope);
	}
	free_data(data, 3);
}

int		main(int ac, char **av)
{
	t_data			*data;

	data = init_data();
	data->flags->args = create_args(av, ac);
	if (ac == 1 || parsing(data))
		ft_exit(data, 1, NULL);
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
