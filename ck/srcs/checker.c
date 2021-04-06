/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/04/06 15:49:00 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int			empty_line(int empty, char **line)
{
	if (empty == 0)
		printf(BCYAN"\033[AChecker>:"BWHITE" Hey.. Don't let me empty :-(\n"WHITE);
	if (empty == 1)
		printf(BCYAN"\033[AChecker>:"BWHITE" Ouch.. You did it again :-/\n"WHITE);
	if (empty == 2)
		printf(BCYAN"\033[AChecker>:"BWHITE" Oof.. It really hurt you know? >.<\n"WHITE);
	if (empty == 3)
		printf(BCYAN"\033[AChecker>:"BWHITE" Is it a provocation? :-|\n"WHITE);
	if (empty == 4)
		printf(BCYAN"\033[AChecker>:"BWHITE" Ok. This is not fun anymore.\n"WHITE);
	if (empty == 5)
	{
		printf(BCYAN"\033[AChecker>:"BWHITE" I wanted to be kind, but here you are..\n"BRED);
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
	return (0);
}



int		parsing_ck(t_data *data)
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

int main(int ac, char **av)
{
	t_data		*data;
	static void		(*redirect[11])(t_data *) =
	{
		sa, sb, ss,
		pa, pb,
		ra, rb, rr, rra, rrb, rrr
	};
	int	red_r;
	int	save;
	int	empty;

	(void)ac;
	(void)av;
	data = init_data();
	data->flags->args = create_args(av, ac);
	if (ac == 1 || parsing_ck(data))
		ft_exit(data, 1, NULL);
	if (data->flags->random)
		generate_random_stack(data, 0);
	else
		load_stack_arg(data, data->flags->args + (data->flags->visualize || data->flags->color || data->flags->random));
	save = data->a->size;
	data->b = malloc(sizeof(t_stack));
	data->b->stack = malloc(sizeof(int) * (data->a->size));
	data->b->size = 0;
	data->print = 0;
	char	*line;
	int		ret;
	ret = 1;
	empty = 0;
	while (ret == 1)
	{
		ret = get_next_line(0, &line);
		red_r = node(line);
		//printf("Error [%s] invalid\n", line);
		if (red_r != -1)
			redirect[red_r](data);
		else if (ret && line[0])
		{
			printf("Error [%s] invalid\n", line);
			exit (1);
		}
		else if (ret != 0)
			if (empty_line(empty++, &line))
				break ;
		free(line);
	}
	if (!checker(data->a, save, 1) && data->flags->visualize)
		print_stack(data->a, 1);
	free_data(data, 2);
	free(data->b->stack);
	free(data->b);
	return (1);
}