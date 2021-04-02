/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/04/02 12:19:21 by mdelwaul         ###   ########.fr       */
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

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
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

int			empty_line(int empty)
{
	int			i;

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
		i = -1;
		while (i < 500000000)
			i++;
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
		printf(WHITE"\n");
		return (1);
	}
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
	//load_stack_arg(&a, av, ac);
	data = malloc(sizeof(t_data));
	data->a = malloc(sizeof(t_stack));
	data->b = malloc(sizeof(t_stack));
	srand(42);
	generate_random_stack(data->a, ft_atoi(av[1]));
	//print_stack(data.a);
	save = data->a->size;
	data->b->stack = malloc(sizeof(int) * (data->a->size));
	data->b->size = 0;
	load_stack_int(data->b, 0);
	data->print = 0;
	char	*line;
	int		ret;
	ret = 1;
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
			if (empty_line(empty++))
				break ;
		free(line);
	}
	if (!checker(data->a, save, 1))
		print_stack(data->a);
	free(data->a->stack);
	free(data->b->stack);
	free(data->a);
	free(data->b);
	free(data);
	return (1);
}