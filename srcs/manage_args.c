/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:57:08 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/10/05 18:15:05 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char	**create_args(char **av, int ac)
{
	char		**dest;
	char		**splited;
	char		**temp;
	int			i;

	dest = NULL;
	i = 0;
	while (++i < ac)
	{
		temp = dest;
		splited = ft_split(av[i], ' ');
		dest = ft_tabjoin(dest, splited);
		ft_free_tab(temp);
		ft_free_tab(splited);
	}
	return (dest);
}

void	load_stack_arg(t_data *data, char **args)
{
	int		i;
	int		j;

	i = -1;
	data->a->size = 0;
	while (args && args[++i])
		data->a->size++;
	data->a->stack = malloc(sizeof(int) * data->a->size);
	i = -1;
	while (args && args[++i])
	{
		data->a->stack[data->a->size - i - 1] = ft_atoi(args[i]);
		j = -1;
		while (++j < i)
			if (data->a->stack[data->a->size - j - 1]
				== data->a->stack[data->a->size - i - 1])
				ft_exit(data, 2, NULL);
	}
}

void	create_stack_rndm(t_data *data, int n)
{
	int	i;

	data->a->stack = malloc(sizeof(int) * n);
	data->a->size = n;
	i = -1;
	while (++i < n)
		data->a->stack[i] = i;
}

void	print_random_stack(t_data *data, int i, int max)
{
	print_stack(data->a, 0);
	if ((int)(((double)(i + 1) / (double)(max)) * 100) >= 100)
		printf(BGREEN);
	printf("%*.0d[%d%%]\n"BWHITE, 10, 0,
		(int)(((double)(i + 1) / (double)(max)) * 100));
	printf("\033[2A\033[K");
	usleep(1000 * 100);
}

void	generate_random_stack(t_data *data, int push_swap)
{
	int		i;
	int		n;

	if (!data->flags->args[1]
		|| !data->flags->args[2] || data->flags->args[3])
		ft_exit(data, 1, NULL);
	srand(ft_atoi(data->flags->args[2]));
	n = ft_atoi(data->flags->args[1]);
	create_stack_rndm(data, n);
	if (n <= 0)
		ft_exit(data, 1, NULL);
	i = -1;
	if (data->flags->visualize && push_swap)
		printf(BWHITE"   Generating random A.\n");
	while (++i < n + (n / 2))
	{
		ft_swap(&data->a->stack[rand() % n], &data->a->stack[rand() % n]);
		if (data->flags->visualize && push_swap)
			print_random_stack(data, i, n + (n / 2));
	}
	if (data->flags->visualize && push_swap)
	{
		printf("\033[A\033[K"WHITE);
		sleep(1);
	}
}
