/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:56:25 by magostin          #+#    #+#             */
/*   Updated: 2021/03/05 01:10:20 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_stacks(int *a, int *b, int s_a, int s_b)
{
	int		i;

	(void)s_b;
	(void)b;
	i = ft_max(s_a, s_b);
	printf("_____\n");
	while (--i >= 0)
	{
		if (i < s_a)
			printf("|%d ", a[i]);
		else
			printf("|  ");
		if (i < s_b)
			printf("%d|\n", b[i]);
		else
			printf(" |\n");
	}
	printf("|a b|\n");
}

void		load_stack_arg(int *a, int s_a, char **av)
{
	int		i;

	i = -1;
	while (++i < s_a)
		a[s_a - i - 1] = ft_atoi(av[i + 1]);
}

void		load_stack_int(int *a, int s_a, int x)
{
	int		i;

	i = -1;
	while (++i < s_a)
		a[s_a - i - 1] = x;
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

int main(int ac, char **av)
{
	int		*a;
	int		*b;
	int		s_a;
	int		s_b;
	static void		(*redirect[11])(int *, int *, int *, int *) =
	{
		sa, sb, ss,
		pa, pb,
		ra, rb, rr, rra, rrb, rrr
	};
	int red_r;

	a = malloc(sizeof(int) * (2 * (ac - 1)));
	s_a = ac - 1;
	b = malloc(sizeof(int) * (2 * (ac - 1)));
	s_b = 0;
	load_stack_arg(a, s_a, av);
	load_stack_int(b, s_a, -42);
	char	*line;
	int		ret;
	ret = 1;
	while (ret == 1)
	{
		print_stacks(a, b, s_a, s_b);
		ret = get_next_line(1, &line);
		red_r = node(line);
		free(line);
		if (red_r == -1)
			break ;
		redirect[red_r](a, b, &s_a, &s_b);
	}
	free(a);
	free(b);
	return (1);
}