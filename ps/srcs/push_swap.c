/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/04/04 16:55:51 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ind(int i, char a)
{
	if (a == 'a')
		return (i >= 2);
	return (i % 2);
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

int		parsing_ps(t_data *data)
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
	if (ac == 1 || parsing_ps(data))
		ft_exit(data, 1, NULL);
	if (data->flags->random)
		generate_random_stack(data, 1);
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