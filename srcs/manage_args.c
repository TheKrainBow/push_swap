/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:57:08 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/04/06 15:28:44 by mdelwaul         ###   ########.fr       */
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

void		load_stack_arg(t_data *data, char **args)
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
			if (data->a->stack[data->a->size - j - 1] == data->a->stack[data->a->size - i - 1])
				ft_exit(data, 2, NULL);
	}
}

void	generate_random_stack(t_data *data, int push_swap)
{
	int		i;
	int		n;
	int		random;

	if (!data->flags->args[1]
	|| !data->flags->args[2] || data->flags->args[3])
		ft_exit(data, 1, NULL);
	srand(ft_atoi(data->flags->args[2]));
	n = ft_atoi(data->flags->args[1]);
	random = rand() % n;
	if (n <= 0)
		ft_exit(data, 1, NULL);
	data->a->stack = malloc(sizeof(int) * n);
	data->a->size = n;
	i = -1;
	while (++i < n)
		data->a->stack[i] = i;
	i = -1;
	if (data->flags->visualize && push_swap)
		printf(BWHITE"   Generating random A.\n");
	while (++i < n + random)
	{
		ft_swap(&data->a->stack[rand() % n], &data->a->stack[rand() % n]);
		if (data->flags->visualize && push_swap)
		{
			print_stack(data->a, 0);
			if ((int)(((double)(i + 1) / (double)(n + random)) * 100) >= 100)
				printf(BGREEN);
			printf("%*.0d[%d%%]\n"BWHITE, 10, 0, (int)(((double)(i + 1) / (double)(n + random)) * 100));
			printf("\033[2A\033[K");
			usleep(1000 * 100);
		}
	}
	if (data->flags->visualize && push_swap)
	//if (push_swap)
	{
		printf("\033[A\033[K"WHITE);
		sleep(1);
	}
}