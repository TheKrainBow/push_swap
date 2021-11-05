/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/11/04 22:01:54 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	node(char *line, int c)
{
	if (!ft_strcmp("sa", line) || (c && !ft_strcmp(BRED"sa", line)))
		return (0);
	if (!ft_strcmp("sb", line) || (c && !ft_strcmp(BGREEN"sb", line)))
		return (1);
	if (!ft_strcmp("ss", line) || (c && !ft_strcmp(BBLUE"ss", line)))
		return (2);
	if (!ft_strcmp("pa", line) || (c && !ft_strcmp(BRED"pa", line)))
		return (3);
	if (!ft_strcmp("pb", line) || (c && !ft_strcmp(BGREEN"pb", line)))
		return (4);
	if (!ft_strcmp("ra", line) || (c && !ft_strcmp(BRED"ra", line)))
		return (5);
	if (!ft_strcmp("rb", line) || (c && !ft_strcmp(BGREEN"rb", line)))
		return (6);
	if (!ft_strcmp("rr", line) || (c && !ft_strcmp(BBLUE"rr", line)))
		return (7);
	if (!ft_strcmp("rra", line) || (c && !ft_strcmp(BRED"rra", line)))
		return (8);
	if (!ft_strcmp("rrb", line) || (c && !ft_strcmp(BGREEN"rrb", line)))
		return (9);
	if (!ft_strcmp("rrr", line) || (c && !ft_strcmp(BBLUE"rrr", line)))
		return (10);
	return (-1);
}

void	ft_error(void *ptr)
{
	free(ptr);
	printf("Error\n");
	exit(1);
}

int	read_input(t_data *data)
{
	int				red_r;
	char			*line;
	int				ret;
	int				empty;
	static void		(*redirect[11])(t_data *) =
	{sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

	ret = 1;
	empty = 0;
	while (ret == 1)
	{
		ret = get_next_line(0, &line);
		red_r = node(line, data->flags->color);
		free(line);
		if (red_r != -1)
			redirect[red_r](data);
		else if (ret)
		{
			printf("Error\n");
			return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data			*data;
	int				save;

	if (ac == 1)
		return (0);
	data = init_data();
	data->flags->args = create_args(av, ac);
	parsing(data);
	if (data->flags->random)
		generate_random_stack(data, 0);
	else
		load_stack_arg(data, data->flags->args
			+ (data->flags->visualize
				|| data->flags->color || data->flags->random));
	save = data->a->size;
	data->b = malloc(sizeof(t_stack));
	data->b->stack = malloc(sizeof(int) * (data->a->size));
	data->b->size = 0;
	if (read_input(data)
		&& !checker(data->a, save, 1, data->flags->color)
		&& data->flags->visualize)
		print_stack(data->a, 1);
	free_stack(data->b);
	free_data(data, 2);
	return (0);
}
