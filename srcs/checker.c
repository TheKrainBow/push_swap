/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/03/29 14:24:43 by mdelwaul         ###   ########.fr       */
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

	srand(10);
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
	t_stack		a;
	t_stack		b;
	t_data		data;
	static void		(*redirect[11])(t_data *) =
	{
		sa, sb, ss,
		pa, pb,
		ra, rb, rr, rra, rrb, rrr
	};
	int	red_r;
	int	save;

	generate_random_stack(&a, 8);
	(void)ac;
	(void)av;
	//load_stack_arg(&a, av, ac);
	save = a.size;
	b.stack = malloc(sizeof(int) * (a.size));
	b.size = 0;
	load_stack_int(&b, 0);
	data.a = &a;
	data.b = &b;
	data.print = 0;
	char	*line;
	int		ret;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(0, &line);
		red_r = node(line);
		free(line);
		if (red_r != -1)
			redirect[red_r](&data);
	}
	if (!checker(&a, save, 1))
		print_stack(&a);
	free(a.stack);
	free(b.stack);
	return (1);
}