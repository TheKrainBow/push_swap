/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:59:45 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/07/12 01:27:40 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	biggest_num(t_stack *a)
{
	int			i;
	long int	temp;
	int			size;
	int			best_size;

	i = -1;
	best_size = 0;
	while (++i < a->size)
	{
		size = 1;
		temp = a->stack[i];
		if (temp < 0)
		{
			temp *= -1;
			size++;
		}
		while (temp >= 10)
		{
			temp /= 10;
			size++;
		}
		if (size > best_size)
			best_size = size;
	}
	return (best_size);
}

void	print_arrow(int size, int mult)
{
	int		i;

	i = -1;
	while (++i < (size) * (mult + 2) - 1)
		printf("-");
	printf(">\n");
}

void	print_stacks(t_data *data, int reset)
{
	int		size;
	int		mult;
	int		i;

	if (!data->print || !data->flags->visualize)
		return ;
	size = ft_max(data->a->size, data->b->size);
	mult = ft_max(biggest_num(data->a), biggest_num(data->b));
	printf(BRED);
	print_arrow(size, mult);
	i = -1;
	while (++i < data->a->size)
		printf(BRED"["BWHITE"%0*d"BRED"]", mult, data->a->stack[i]);
	printf("\n");
	i = -1;
	while (++i < data->b->size)
		printf(BGREEN"["BWHITE"%0*d"BGREEN"]", mult, data->b->stack[i]);
	printf("\n");
	print_arrow(size, mult);
	i = -1;
	while (++i <= 4 && reset)
		printf("\033[1A\033[K"BWHITE);
	usleep(1000 * 100);
}

void	print_stack(t_stack *a, int arrow)
{
	int		i;
	int		mult;

	mult = biggest_num(a);
	i = -1;
	printf(BWHITE);
	while (++i < (a->size) * (mult + 2) - 1 && arrow)
		printf("-");
	if (arrow)
		printf(">\n");
	printf(BRED);
	i = -1;
	while (++i < a->size)
		printf(BRED"["BWHITE"%0*d"BRED"]", mult, a->stack[i]);
	printf("\n"BWHITE);
}
