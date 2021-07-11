/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelwaul <mdelwaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:54:24 by mdelwaul          #+#    #+#             */
/*   Updated: 2021/07/12 01:28:40 by mdelwaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	parsing(t_data *data)
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

void	free_stack(t_stack *a)
{
	free(a->stack);
	free(a);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->a = malloc(sizeof(t_stack));
	data->a->stack = NULL;
	data->ma[0] = malloc(sizeof(t_move));
	data->mb[0] = malloc(sizeof(t_move));
	data->ma[1] = malloc(sizeof(t_move));
	data->mb[1] = malloc(sizeof(t_move));
	data->ma[0]->n = 0;
	data->mb[0]->n = 0;
	data->print = 0;
	data->flags = malloc(sizeof(t_flags));
	data->flags->random = 0;
	data->flags->visualize = 0;
	data->flags->color = 0;
	return (data);
}

void	free_data(t_data *data, int free_power)
{
	if (free_power >= 2)
		free(data->a->stack);
	if (free_power >= 1)
	{
		free(data->a);
		free(data->ma[0]);
		free(data->mb[0]);
		free(data->ma[1]);
		free(data->mb[1]);
		ft_free_tab(data->flags->args);
		free(data->flags);
	}
	if (free_power >= 3)
	{
		free(data->chunked_a);
		free_stack(data->sorted_a);
	}
	free(data);
}
