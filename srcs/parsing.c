/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krain <krain@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:24:02 by magostin          #+#    #+#             */
/*   Updated: 2021/11/03 01:19:22 by krain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_try(t_data *data, char *arg)
{
	long	nbr;

	nbr = ft_atoi(arg);
	if (!ft_strmap(arg + 1, ft_isdigit))
		ft_exit(data, 1, NULL);
	if (arg[0] != '-' && ft_isdigit(arg[0]) == 0)
		ft_exit(data, 1, NULL);
	if (ft_atoi(arg) > 2147483647)
		ft_exit(data, 1, NULL);
	if (ft_atoi(arg) < -2147483648)
		ft_exit(data, 1, NULL);
}

void	parsing2(int index, t_data *data)
{
	char	**args;

	args = data->flags->args;
	while (args[++index])
		ft_try(data, args[index]);
}

void	parsing(t_data *data)
{
	char	*temp;
	char	**args;

	args = data->flags->args;
	temp = NULL;
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
		else
			ft_try(data, args[0]);
		parsing2(0, data);
	}
	else
		parsing2(-1, data);
	free(temp);
}
