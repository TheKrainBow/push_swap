/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/07/12 01:35:20 by mdelwaul         ###   ########.fr       */
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

int	final_line(char **line)
{
	printf(PROMPT"I wanted to be kind, but here you are..\n"BRED);
	sleep(2);
	printf("\n\n"BRED);
	printf("	KOKOK           KOKOKO         KOKOKOKOKO          KOKO\n");
	printf("	KOKOK         KOKOKO         KOKOKOKOKOKOKO        KOKO\n");
	printf("	KOKOK       KOKOKO          KOKOK      KOKOK       KOKO\n");
	printf("	KOKOK     KOKOKO            KOKO        KOKO       KOKO\n");
	printf("	KOKOK   KOKOKO              KOKO        KOKO       KOKO\n");
	printf("	KOKOK KOKOKO               KOKO          KOKO      KOKO\n");
	printf("	KOKOKOKOKO                 KOKO          KOKO      KOKO\n");
	printf("	KOKOKOKOKO                 KOKO          KOKO      KOKO\n");
	printf("	KOKOK KOKOKO               KOKO          KOKO      KOKO\n");
	printf("	KOKOK   KOKOKO              KOKO        KOKO       KOKO\n");
	printf("	KOKOK     KOKOKO            KOKO        KOKO           \n");
	printf("	KOKOK       KOKOKO          KOKOK      KOKOK           \n");
	printf("	KOKOK         KOKOKO         KOKOKOKOKOKOKO        KOKO\n");
	printf("	KOKOK           KOKOKO         KOKOKOKOKO          KOKO\n");
	printf("\n");
	printf("(Shouldv been KO since first empty line)");
	printf(WHITE"\n");
	free(*line);
	return (1);
}

int	empty_line(int empty, char **line)
{
	if (empty == 0)
		printf(PROMPT"Hey.. Don't let me empty :-(\n"WHITE);
	if (empty == 1)
		printf(PROMPT"Ouch.. You did it again :-/\n"WHITE);
	if (empty == 2)
		printf(PROMPT"Oof.. It really hurt you know? >.<\n"WHITE);
	if (empty == 3)
		printf(PROMPT"Is it a provocation? :-|\n"WHITE);
	if (empty == 4)
		printf(PROMPT"Ok. This is not fun anymore.\n"WHITE);
	if (empty == 5)
		return (final_line(line));
	return (0);
}

int	read_input(t_data *data)
{
	int				red_r;
	char			*line;
	int				ret;
	int				empty;
	static	void	(*redirect[11])(t_data *) =
	{sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

	ret = 1;
	empty = 0;
	while (ret == 1)
	{
		ret = get_next_line(0, &line);
		red_r = node(line, data->flags->color);
		if (red_r != -1)
			redirect[red_r](data);
		else if (ret && line[0])
		{
			printf("Error [%s] invalid.\n", line);
			exit(1);
		}
		else if (ret != 0 && empty_line(empty++, &line))
			return (0);
		free(line);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data			*data;
	int				save;

	data = init_data();
	data->flags->args = create_args(av, ac);
	if (ac == 1 || parsing(data))
		ft_exit(data, 1, NULL);
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
		&& !checker(data->a, data->a->size, 1, data->flags->color)
		&& data->flags->visualize)
		print_stack(data->a, 1);
	free_data(data, 2);
	free_stack(data->b);
	return (1);
}
